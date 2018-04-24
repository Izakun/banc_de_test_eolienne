# -*- coding: utf-8 -*-
#!/usr/bin/python3
# mysqlWampPy3.py

import mysql.connector
from raspiomix import Raspiomix

cnx = mysql.connector.connect(host="192.168.56.1", user="root", password="", database="supervison")

# Cr�ation d'un curseur.
cur = cnx.cursor()

r = Raspiomix()
print("La tension est de %f Volt !" % r.readAdc(0))

# r�cuperer la tension gr�ce aux ports sur la
# raspiomix. -- 8 PORTS -- 

if r &gt; --TENSION-- and r &lt; --TENSION-- :
   print("La porte est ferm�e.")
   cursor.execute("""INSERT INTO etat_capteur(valeur) VALUES(?)""";(1))
# On ins�re 0 dans la table valeur de etat_capteur pour indiquer que
# la porte est ferm�e.

else if r &gt; --TENSION-- and r &lt; --TENSION-- :
   print("La porte est ouverte.")
   cursor.execute("""INSERT INTO etat_capteur(valeur) VALUES(?)""";(0))
# On ins�re 0 dans la table valeur de etat_capteur pour indiquer que
# la porte est ouverte.

else :
   print("Il y a un d�faut.")
   cursor.execute("""INSERT INTO etat_capteur(valeur) VALUES(?)""";(2))
# On ins�re 2 dans la table valeur de etat_capteur pour indiquer qu'il
# y a un d�faut.

# On ferme le curseur.
cur.close()

# On ferme la connection.
cnx.close() 

