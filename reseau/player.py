#!/usr/bin/python3
# -*-coding:Utf-8 -*

import socket, pdb
import uuid

class Player:
    def __init__(self, socket, name = "new", status = "inlobby"):
        socket.setblocking(0)
        self.socket = socket # socket associate to the player
        self.name = name # name player
        self.id = str(uuid.uuid4()) # ID player
        self.status = status # status player ( waitng or game )
        self.is_ready = False # if player ready to play or no

    def fileno(self): # the integer file descriptor of the socket
        return self.socket.fileno()
