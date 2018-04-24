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
BUFFER_SIZE = 4096

socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
socket.bind((TCP_IP, TCP_PORT))
socket.listen(7)
print("Le serveur est lancé. Attente de la connextion du client...")

class Receive(Thread): #recoit un message de la part d'un client
 
    def __init__(self):
        Thread.__init__(self)
        self.socket_client = socket_client
         
 
    def run(self):
        
        """
        recoit le message du client puis test dans un premier temps si le message commence par
        %: dans ce cas ce sera le puissance a envoyer dans l'eolienne et si le message
        commence par id ce sera l'id du scenario a aller chercher dans la base de donnees
        """        

        while True:
            print("test2")
            try:
                print("avant test")
                message_recu  = self.socket_client.recv(BUFFER_SIZE)
                print("apres test")
            except BlockingIOError:
                print("Except dans Receive")
                pass
            else :
                message_recu = message_recu.decode()
                message_decode = message_recu[0]+message_recu[1]
                print(message_decode)
                if message_decode == "%:":
                    intensite = message_recu.replace("%:","")
                    print(intensite)
                    #Send().start()
                    #return intensite
                elif message_decode == "id":
                    id_scenario = message_recu.replace("id","")
                    str(id_scenario)
                    id_scenario = id_scenario.split("/")
                    print(id_scenario)
                    print("id scenario: {}".format(id_scenario[0]))
                    print("id_eolienne: {}".format(id_scenario[1]))
                    #return id_scenario
                    print("test")
                else:
                    print("Donnees  incorrectes")
                    
            
             
 
             
class Send(Thread):
 
    def __init__(self):
        Thread.__init__(self)
        self.__mesPuis = CAcqPuissance()
         
 
    def run(self):
        
        i = 3
        while True:
            time.sleep(1)
            msg = self.__mesPuis.mesurerPuissance()
            print(msg)
            msgs = "{}/{}".format(i,self.__mesPuis.mesurerPuissance()/100)
            msgs = msgs.encode('UTF-8')
            i += 1
            if socket_client.send(msgs):
                print("ok: {}".format(msgs))
                Receive().start()
            else:
                print("pas ok")
            print(msgs)

if __name__ == "__main__":
    mesPuis = CAcqPuissance()
    val = mesPuis.mesurerPuissance()
    #msgs = "10/5.5"#+str(self.__mesPuis.mesurerPuissance())
    msgs = "10/{}".format(val)
    msgs = msgs.encode('UTF-8')
    print(msgs)



    
     
    
    print("Ecoute sur le port {}".format(TCP_PORT))
    socket_client, infos = socket.accept()
    print("Le client {} est connecté!".format(infos))
     
     
    Receive_thread = Receive()
     
    Receive_thread.start()

