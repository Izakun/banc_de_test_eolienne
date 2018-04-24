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
 
TCP_IP = ''
TCP_PORT = 2018

connexion_principale = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
connexion_principale.bind((TCP_IP, TCP_PORT))
connexion_principale.listen(7)
print("Le serveur est lancé sur le port {}. Attente de la connextion du client...".format(TCP_PORT))

class Serveur(Thread): #recoit un message de la part d'un client
 
    def __init__(self):
        Thread.__init__(self)
        ##self.socket_client = socket_client
        self.__mesPuis = CAcqPuissance()
        self.socket_client, infos = connexion_principale.accept()
        print("Le client {} est connecté!".format(infos))
         
 
    def run(self):
              

        while True:
            i = 3
            try:
                print("attente du message...")
                message_recu  = self.socket_client.recv(1024)
                print("message recv: {}".format(message_recu))
                print("message recu!")
            except BlockingIOError:
                print("Except dans Receive")
                pass
            else :
                message_recu = message_recu.decode()
                message_decode = message_recu[0]+message_recu[1]
                print(message_decode)
                if message_decode == "%:":
                    
                    """
                    Lorsque le serveur recoit "%:x"  il enverra ensuite cette puissance a la
                    soufflerie
                    """
                    
                    intensite = message_recu.replace("%:","")
                    print(intensite)
                    msgs = "ok"
                    msgs = msgs.encode('UTF-8')
                    self.socket_client.send(msgs)
                    
                elif message_decode == "id":
                    
                    """
                    Lorsque le serveur recoit "idx/y"  il ira ensuite chercher ces id dans la
                    bdd pour acceder aux scenarios.
                    """
                    
                    id_scenario = message_recu.replace("id","")
                    str(id_scenario)
                    id_scenario = id_scenario.split("/")
                    print(id_scenario)
                    print("id scenario: {}".format(id_scenario[0]))
                    print("id_eolienne: {}".format(id_scenario[1]))
                    msgs = "ok"
                    msgs = msgs.encode('UTF-8')
                    self.socket_client.send(msgs)
    
                elif message_recu == "getWP":
                    
                    """
                    Lorsque le serveur recoit "getWP"  il renvoi la puissance instantanée
                    et la force du vent
                    EX : 14/150.04
                    """
                    
                    msg = self.__mesPuis.mesurerPuissance()
                    print(msg)
                    msgs = "{}/{}".format(i,self.__mesPuis.mesurerPuissance()/100)
                    msgs = msgs.encode('UTF-8')
                    i += 1
                    if self.socket_client.send(msgs):
                        print("ok: {}".format(msgs))
                    else:
                        print("pas ok")
                        print(msgs)
                
                else:
                    
                    """
                    Affiche donnees incorrectes si les données envoyées ne sont pas attendues
                    """
                    
                    print("Donnees  incorrectes")
                    msgs = "Donnees  incorrectes"
                    msgs = msgs.encode('UTF-8')
                    self.socket_client.send(msgs)
                    print(message_recu)
                           

if __name__ == "__main__":
##    mesPuis = CAcqPuissance()
##    val = mesPuis.mesurerPuissance()
##    #msgs = "10/5.5"#+str(self.__mesPuis.mesurerPuissance())
##    msgs = "10/{}".format(val)
##    msgs = msgs.encode('UTF-8')
##    print(msgs)     
    
##    socket_client, infos = connexion_principale.accept()
##    print("Le client {} est connecté!".format(infos))
     
    Serveur_thread = Serveur()
     
    Serveur_thread.start()
    
    while True:
        pass

