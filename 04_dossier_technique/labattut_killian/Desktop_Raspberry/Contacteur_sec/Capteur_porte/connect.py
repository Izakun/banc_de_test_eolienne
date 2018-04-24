#!/usr/bin/python3.4
# coding: utf-8

import mysql.connector

def connect_db():
    
    db = mysql.connector.connect(host="10.16.2.147",
                         user="root",
                         passwd="",
                         database="soufflerie",
                         port="3306")
    return db
