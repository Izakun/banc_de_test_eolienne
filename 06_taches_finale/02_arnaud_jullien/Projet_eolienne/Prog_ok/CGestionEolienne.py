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

class CGestionEolienne(Thread):

    def __init__(self):
        Thread.__init__(self)
        self.__mesPuis = CAcqPuissance()
    

    def run(self): #fonction qui s'exucute lorsqu'on lance la classe en thread
        while True:
            time.sleep(1)
            '''
            le thread s'exécutera toutes les 1 secondes
            '''
            self.__mesPuis.mesurerPuissance()
            print(self.__mesPuis.moyennePuissance())
            
        

if __name__ == "__main__":
   eole = CGestionEolienne()
   eole.start()
   
