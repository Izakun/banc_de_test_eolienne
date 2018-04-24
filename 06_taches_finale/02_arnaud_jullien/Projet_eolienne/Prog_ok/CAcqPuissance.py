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

class CAcqPuissance:
    
    IN_CAN_COURANT = 2
    IN_CAN_TENSION = 1
    
    def __init__(self):
        self.r = Raspiomix()
        self.listePuissances = deque(maxlen=60)
        
    def mesurerPuissance(self):
        
        
        # -------- Mesure tension ----------------------------------
        # tension = ((self.r.readAdc(ENTREE_CAN))/(4.5/(4.5+47)))
        # 1/(4.5/(4.5+47)) = 11,44444444444444444
        tension = self.r.readAdc(__class__.IN_CAN_TENSION) * 11.44444444444444444
        #print("tension = {:.1f} V".format(tension))
        
        # -------- Mesure courant ----------------------------------
        # courant = ((self.r.readAdc(ENTREE_CAN))*5
        courant = self.r.readAdc(__class__.IN_CAN_COURANT) * 5
        #print("courant = {:.1f} A".format(courant))
        
        # -------- Mesure puissance instantanée ----------------------------------
        puissinst = courant * tension
        
        
        self.listePuissances.append(puissinst)
        #print("puissance instantanée = {:.1f} W".format(puissinst))
        return puissinst
        

    def moyennePuissance(self): #calcule la moyenne de la liste
        moyenne = mean(self.listePuissances)
        return moyenne
        
        
        
        
        
if __name__ == "__main__":
    
    mesPuis = CAcqPuissance()
    print(mesPuis)
    mesPuis.mesurerPuissance()
    print(mesPuis.listePuissances)
    mesPuis.moyennePuissance()

    

