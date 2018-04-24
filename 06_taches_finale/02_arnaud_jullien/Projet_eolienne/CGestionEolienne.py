#!/usr/bin/env python3
# coding: utf-8
'''
Programme : heure.py       version 1.0
Date : 19-12-2017
Auteur : Jullien Arnaud

Matériel utilisé : Fonctionnement programme :
  
  
'''
from raspiomix import Raspiomix
from datetime import datetime
from threading import Thread
import time
from CAcqPuissance import CAcqPuissance
from CAcqForce import CAcqForce
import mysql.connector
cnx = mysql.connector.connect(host="10.16.37.120", user="gestioneolienne", password="Nantes44", database="soufflerie")

class CGestionEolienne(Thread):
    
    #connexion a la basse de donnee
    #cnx = mysql.connector.connect(host="10.16.37.120", user="gestioneolienne", password="Nantes44", database="soufflerie")

    def __init__(self):
        Thread.__init__(self)
        self.__mesPuis = CAcqPuissance()
        self.__lectForce = CAcqForce()
    

    def run(self): #fonction qui s'exucute lorsqu'on lance la classe en thread
        while True:
            time.sleep(1)
            '''
            le thread s'exécutera toutes les 1 secondes
            '''
            self.__mesPuis.mesurerPuissance()
            self.__lectForce.lectureForce()
            print("puissance instantanée = {} force du vent = {}".format(self.__lectForce.lectureForce(),self.__mesPuis.mesurerPuissance()))
            cur = cnx.cursor()
            #ordre des colonnes: id_releve_C, nom, valeurs, heure, id_capteur
            donnee = """UPDATE direct SET puissance={}, vent={} WHERE id=0""" \
             .format(self.__mesPuis.mesurerPuissance(),self.__lectForce.lectureForce())

            print(donnee)
            cur.execute(donnee)
            cnx.commit()
             

if __name__ == "__main__":
   eole = CGestionEolienne()
   eole.start()
   
