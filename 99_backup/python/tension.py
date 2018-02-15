#!/usr/bin/python3.4
# coding: utf-8
""" Classe : canAffichTensionPy3.py     version : 1.0
Auteur : H. Dugast
Date : 10-01-2017
Matériel utilisé : carte raspberry, carte raspiOmix+, module grove Sliding potentiometer
Connexion : module potentiomètre -> AN1 raspiOmix+
Fonction :
    Convertit la tension analogique appliquée sur l'entrée AN1 en code
    puis à partir de ce dernier, affiche la tension calculée correspondant à l'entrée
"""

from raspiomix import Raspiomix
import datetime
import time
from connect import *

# Lecture du port can.
r = Raspiomix()
ENTREE_CAN = 0

cur = connect.db.cursor()
cur.execute('SELECT periode_rafraich FROM parametre WHERE id = 1')
rows = cur.fetchone()
for row in rows:
    reponse = float(row)
cur.close()

# Boucle pour inserer valeur dans la base de donnees.
while True:
    print(r.readAdc(ENTREE_CAN))
    # Si la valeur est comprise entre 0,7 et 2,4, on fait :
    if r.readAdc(ENTREE_CAN) < 2.4 and r.readAdc(ENTREE_CAN) > 0.7:
        print("La porte est ouverte !")
        # On donne la valeur cur au curseur de la base de donnees.
        cur = connect.db.cursor()
        # On introduit les valeurs dans la table evenement.
        cur.execute("INSERT INTO evenement(date_heure, id_etat_capteur, id_capteur, id_type_evenement) VALUES (NOW(), 1, 1 ,1)")
        # On ferme le curseur.
        cur.close()
        # Validation de l'insertion dans la base de donnees.
        connect.db.commit()
        # Temps de raffraichissement, ici en seconde.
        time.sleep(reponse)
    elif r.readAdc(ENTREE_CAN) > 2.4 and r.readAdc(ENTREE_CAN) < 4.1:
        print("La porte est fermee !")
        # On donne la valeur cur au curseur de la base de donnees.
        cur = connect.db.cursor()
        # On introduit les valeurs dans la table evenement.
        cur.execute("INSERT INTO evenement(date_heure, id_etat_capteur, id_capteur, id_type_evenement) VALUES (NOW(), 2, 1, 2)")
        # On ferme le curseur.
        cur.close()
        # Validation de l'insertion dans la base de donnees.
        connect.db.commit()
        # Temps de raffraichissement, ici en seconde.
        time.sleep(reponse)
    else:
        print("Il y a une panne !")
        # On donne la valeur cur au curseur de la base de donnees.
        cur = connect.db.cursor()
        # On introduit les valeurs dans la table evenement.
        cur.execute("INSERT INTO evenement(date_heure, id_etat_capteur, id_capteur, id_type_evenement) VALUES (NOW(), 3, 1, 4)")
        # On ferme le curseur.
        cur.close()
        # Validation de l'insertion dans la base de donnees.
        connect.db.commit()
        # Temps de raffraichissement, ici en seconde.
        time.sleep(reponse)
        
# On ferme la base de donnees.
db.close()


