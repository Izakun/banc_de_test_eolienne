#!/usr/bin/python3.4
# coding: utf-8

from raspiomix import Raspiomix
import datetime
import time
from t1 import *

r = Raspiomix()
ENTREE_CAN = 0
print("1")
def insert(v1, v2):
    _v1 = v1
    _v2 = v2
    cur = connect.db.cursor()
    cur.execute(
        "INSERT INTO evenement(date_heure, id_etat_capteur, id_capteur, id_type_evenement)"
        "VALUES (NOW(), %s, 1 ,%s)", (_v1, _v2))
    cur.commit()
    cur.close()
    time.sleep(reponse)
print("2")

def tension(tension):
    _t = tension
    if tension < 2.4 and tension > 0.7:
        print("La porte est ouverte !")
        insert(1, 1)
    elif tension > 2.4 and tension < 4.1:
        print("La porte est fermee !")
        insert(2, 2)
    else:
        print("Il y a une panne !")
        insert(3, 4)
print("3")

while True:
    cur = connect.db.cursor()
    sql = cur.execute('SELECT periode_rafraich FROM parametre WHERE id = 1')
    reponse = (cur.fetchone())
    cur.close()
    tension(r.readAdc(ENTREE_CAN))
    print("4")
    
print("5")
    

print(r.readAdc(ENTREE_CAN))

