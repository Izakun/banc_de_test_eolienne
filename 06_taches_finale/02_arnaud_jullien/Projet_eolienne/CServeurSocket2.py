#!/usr/bin/python3.4
# coding: utf-8

"""
Programme : PServeurSocket.py       version 1.0
Date : 15-03-2018
Auteur : Arnaud JULLIEN
"""

import socket
import sys
from threading import Thread
import time
from CAcqPuissance import CAcqPuissance
from socket import error as SocketError
import errno
import RPi.GPIO as GPIO

TCP_IP = ''
TCP_PORT = 2018
GPIO.setmode(GPIO.BOARD) # mode de fonctionnement GPIO
GPIO.setup(12, GPIO.OUT) # configure port en sortie    

connexion_principale = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
connexion_principale.bind((TCP_IP, TCP_PORT))
connexion_principale.listen(7)
print("Le serveur est lancé sur le port {}. Attente de la connextion du client...".format(TCP_PORT))

class CServeurSocket2(Thread): #recoit un message de la part d'un client
 
    def __init__(self):
        Thread.__init__(self)
        ##self.socket_client = socket_client
        self.__mesPuis = CAcqPuissance()
        self.message_recu = "0"
        self.p = GPIO.PWM(12, 500)
        
    def consigne(self):
            
        #================= Gestion consigne ===============================
        
        consigne = float(self.message_recu.replace("%:",""))
        if consigne < 100 :
            self.p.ChangeDutyCycle(consigne)
        print("consigne : {}".format(consigne))
        return consigne
    
    def id(self):
        
        id = self.message_recu.replace("id","")
        str(id)
        id = id.split("/")
        print(id)
        print("id_scenario: {}".format(id[0]))
        print("id_phase: {}".format(id[1]))
        return id
        
        
         
 
    def run(self):
                       
        self.p.start(0)
                                      
        while True:
            self.socket_client, infos = connexion_principale.accept()
            print("Le client {} est connecté!".format(infos))
            
            continuer = True

            while continuer:
                #i = 3
                try:
                    print("attente du message...")
                    self.message_recu  = self.socket_client.recv(1024)
                    print("message recv: {}".format(self.message_recu))
                    print("message recu!")
                    self.message_recu = self.message_recu.decode('utf_8')
                    message_decode = self.message_recu[0]+self.message_recu[1]
                    print(self.message_recu)
                    if message_decode == "%:":
                        
                        """
                        Lorsque le serveur recoit "%:x"  il enverra ensuite cette puissance a la
                        soufflerie
                        """
                        self.consigne()
                        
                        msgs = "ok int"
                        msgs = msgs.encode('utf_8')
                        self.socket_client.send(msgs)
                        
                        
                    elif message_decode == "id":
                        
                        """
                        Lorsque le serveur recoit "idx/y"  il ira ensuite chercher ces id dans la
                        bdd pour acceder aux scenarios.
                        """
                        
                        self.id()
                        msgs = "ok id"
                        msgs = msgs.encode('utf_8')
                        self.socket_client.send(msgs)
                        
                        
        
                    elif self.message_recu == "getWP":
                        
                        """
                        Lorsque le serveur recoit "getWP"  il renvoi la puissance instantanée
                        et la force du vent
                        EX : 14/150.04
                        """
                        
                        msg = self.__mesPuis.mesurerPuissance()
                        print(msg)
                        msgs = "{}/{}".format(i,self.__mesPuis.mesurerPuissance()/100)
                        msgs = msgs.encode('utf_8')
                        i += 1
                        if self.socket_client.send(msgs):
                            print("ok: {}".format(msgs))
                        else:
                            print("pas ok")
                            print(msgs)
                            
                    elif self.message_recu == "close":
                        
                        self.socket_client.close()
                        continuer = False
                        print("Fermeture de la connexion client , attente d'une nouvelle connexion")
                        
                        
                    
                    else:
                        
                        """
                        Affiche donnees incorrectes si les données envoyées ne sont pas attendues
                        """
                        
                        print("Donnees  incorrectes")
                        msgs = "Donnees  incorrectes"
                        msgs = msgs.encode('UTF-8')
                        self.socket_client.send(msgs)
                        print(self.message_recu)

                except BlockingIOError as erreur:
                    print("ERREUR : Except dans Receive \n {}".format(erreur))

                except:
                    print("ERREUR : {}".format(sys.exc_info()))

if __name__ == "__main__":
##    mesPuis = CAcqPuissance()
##    val = mesPuis.mesurerPuissance()
##    #msgs = "10/5.5"#+str(self.__mesPuis.mesurerPuissance())
##    msgs = "10/{}".format(val)
##    msgs = msgs.encode('UTF-8')
##    print(msgs)     
    
##    socket_client, infos = connexion_principale.accept()
##    print("Le client {} est connecté!".format(infos))
     
    Serveur_thread = CServeurSocket2()
    
    print(Serveur_thread.consigne())
    
     
    Serveur_thread.start()
    
##    while True:
##        pass

