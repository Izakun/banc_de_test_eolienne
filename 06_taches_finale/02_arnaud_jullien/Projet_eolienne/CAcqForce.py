#!/usr/bin/env python3
# coding: utf-8
'''
Programme : heure.py       version 1.0
Date : 19-12-2017
Auteur : Jullien Arnaud

Matériel utilisé : Fonctionnement programme :
  
  
'''
from raspiomix import Raspiomix
from threading import Thread
import serial
import time

class CAcqForce(Thread):

    def __init__(self):
        pass
        
    def acquisitionTrame(self):
        ser = serial.Serial(
        port='/dev/ttyUSB0',
        baudrate = 9600,
        timeout=1
        )
        counter=0
        trame=ser.readline()
        print (trame)
        return trame
        
    def lectureForce(self) :
        trame = "$IIMWV,090.0,R,015.10,N,A*05"
        ftrame = trame.find("$IIMWV")
##        print (ftrame)
        if trame.find("$IIMWV") == 0 :
##            print("ok")
            trame2 = trame.split(",")
            forceVent = trame2[3]
##            print(forceVent)
            return forceVent
        else :
            print("pas ok")
            
 

if __name__ == "__main__":
    mesForce = CAcqForce()
    mesForce.lectureForce()

   
