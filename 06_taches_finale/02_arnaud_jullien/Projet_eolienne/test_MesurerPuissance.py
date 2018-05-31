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
import unittest
from CAcqPuissance import CAcqPuissance

class TestMesurerPuissance(unittest.TestCase):
    
    def test_mesurerPuissance(self):
        puiss = CAcqPuissance()
        p = puiss.mesurerPuissance()
        self.assertLess(p, 500)
        self.assertGreater(p, 0)
    
