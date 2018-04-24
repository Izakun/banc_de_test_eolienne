from raspiomix import Raspiomix
import RPi.GPIO as GPIO

class capteur_porte:
    
    etat_porte = r.readAdc(0)
    #etat_capteur = AN0
    entree_can = 3.3

    def __init__(self, etat_porte):
        
        self.etat_porte = etat_porte
    
    def __init__(self, etat_capteur):
    
        self.etat_capteur = etat_capteur
        
    def read_etat(self, entree_can, etat_capteur):
        
        self.etat_capteur = etat_capteur
        self.entree_can = entree_can