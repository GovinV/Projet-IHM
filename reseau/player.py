#!/usr/bin/python3
# -*-coding:Utf-8 -*

import socket, pdb
import uuid

class Player:
    def __init__(self, socket, name = "new"):
        socket.setblocking(0)
        self.socket = socket
        self.name = name
        self.id = str(uuid.uuid4())
        
    def fileno(self):
        return self.socket.fileno()
