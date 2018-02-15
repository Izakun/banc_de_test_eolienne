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
import MySQLdb

class connect:
    # Connection a la base de donnees.
    db = MySQLdb.connect(host="10.16.2.162",
                           user="supervision",
                           passwd="root",
                           db="supervision")
