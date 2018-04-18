#!/usr/bin/python3
# -*-coding:Utf-8 -*

import socket, pdb
import uuid

class Player:
    def __init__(self, socket, name = "new", status = "inlobby"):
        socket.setblocking(0)
        self.socket = socket
        self.name = name
        self.id = str(uuid.uuid4())
        self.status = status

    def fileno(self):
        return self.socket.fileno()
