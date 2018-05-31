#!/usr/bin/python3.4
# coding: utf-8
"""
Classe : mesure_tension.py version : 1.0
Auteur : A.JULLIEN
Date : 26/03/2018
Matériel utilisé : carte raspberry, carte raspiOmix+, module grove Sliding potentiometer
Connexion : module potentiomètre -> AN1 raspiOmix+
Fonction :
Convertit la tension analogique appliquée sur l'entrée AN1 en code
puis à partir de ce dernier, affiche la tension calculée correspondant à l'entrée
"""
from raspiomix import Raspiomix
from threading import Thread
from statistics import mean
from collections import deque
import time
from decimal import *
import RPi.GPIO as GPIO

class CGestionCommande():
    
    OUT_CAN_TENSION = 1
    
    def __init__(self):
        self.r = Raspiomix()
        Thread.__init__(self)
        
    def launch(self):

        GPIO.setmode(GPIO.BOARD) # mode de fonctionnement GPIO
        GPIO.setup(12, GPIO.OUT) # configure port en sortie

        
        p = GPIO.PWM(12, 1200)
        p.ChangeFrequency(500)
        p.start(50)
##        try:
##            while 1:
##                for dc in range(0, 101, 5):
##                    p.ChangeDutyCycle(dc)
        print("En fonctionnement")
        while 1:
            print("+")
            time.sleep(1)
        
        
        
        
        
if __name__ == "__main__":
    
    envTens = CGestionCommande()
    envTens.launch()

    

    

    
