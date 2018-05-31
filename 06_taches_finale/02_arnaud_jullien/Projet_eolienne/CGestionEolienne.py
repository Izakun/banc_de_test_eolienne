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
from CServeurSocket2 import CServeurSocket2
import mysql.connector

#cnx = mysql.connector.connect(host="10.16.37.120", user="gestioneolienne", password="Nantes44", database="soufflerie")

class CGestionEolienne(Thread):
    
    #connexion a la basse de donnee
    #cnx = mysql.connector.connect(host="10.16.37.120", user="gestioneolienne", password="Nantes44", database="soufflerie")

    def __init__(self):
        Thread.__init__(self)
        self.__mesPuis = CAcqPuissanc e()
        self.__lectForce = CAcqForce()
        self.__recvSocket = CServeurSocket2()
    

    def run(self): #fonction qui s'exucute lorsqu'on lance la classe en thread
        
        self.__recvSocket.start()
            
        while True:

            '''
            le thread s'exécutera toutes les 1 secondes
            '''
            
            self.__mesPuis.mesurerPuissance()
            self.__lectForce.lectureForce()
            print("puissance instantanée = {} force du vent = {}"\
                  .format(self.__mesPuis.mesurerPuissance(),self.__lectForce.lectureForce()))
            #cur = cnx.cursor()
            #ordre des colonnes: id_releve_C, nom, valeurs, heure, id_capteur
            donnee = "UPDATE releves SET puissance={}, force_vent={} WHERE id=0"\
                     .format(self.__mesPuis.mesurerPuissance(),self.__lectForce.lectureForce())

##            print(donnee)
            #cur.execute(donnee)
            #cnx.commit()
             

if __name__ == "__main__":
   eole = CGestionEolienne()
   eole.start()
   
