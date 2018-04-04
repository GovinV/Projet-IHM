#!/usr/bin/python3
# -*-coding:Utf-8 -*

import socket, pdb
import uuid

QUIT_STRING = '<$quit$>'


class Hall:
    def __init__(self):
        self.rooms = {} # {room_name: Room}
        self.room_player_map = {} # {playerid: roomName}

    def welcome_new(self, new_player):
        new_player.socket.sendall(b'Welcome to server.\nPlease tell us your name:\n')

    def list_rooms(self, player):
        
        if len(self.rooms) == 0:
            msg = 'Oops, no active rooms currently. Create your own!\n' \
                + 'Use [<join> room_name] to create a room.\n'
            player.socket.sendall(msg.encode())
        else:
            msg = 'Listing current rooms...\n'
            for room in self.rooms:
                msg += room + ": " + str(len(self.rooms[room].players)) + " player(s)\n"
            player.socket.sendall(msg.encode())
    
    def handle_msg(self, player, msg):
        
        instructions = b'Instructions:\n'\
            + b'[<list>] to list all rooms\n'\
            + b'[<join> room_name] to join/create/switch to a room\n' \
            + b'[<manual>] to show instructions\n' \
            + b'[<quit>] to quit\n' \
            + b'Otherwise start typing and enjoy!' \
            + b'\n'

        print(player.id + " says: " + msg)
        if "name:" in msg:
            name = msg.split()[1]
            player.name = name
            print("New connection from:", player.name)
            player.socket.sendall(instructions)

        elif "<join>" in msg:
            same_room = False
            if len(msg.split()) >= 2: # error check
                room_name = msg.split()[1]
                if player.id in self.room_player_map: # switching?
                    if self.room_player_map[player.id] == room_name:
                        player.socket.sendall(b'You are already in room: ' + room_name.encode())
                        same_room = True
                    else: # switch
                        old_room = self.room_player_map[player.id]
                        self.rooms[old_room].remove_player(player)
                if not same_room:
                    if not room_name in self.rooms: # new room:
                        new_room = Room(room_name)
                        self.rooms[room_name] = new_room
                    if self.rooms[room_name].length < 4:
                        self.rooms[room_name].players.append(player)
                        self.rooms[room_name].welcome_new(player)
                        self.room_player_map[player.id] = room_name
                    else:
                        player.socket.sendall(b'This Room is full. Choose another one:\n' + instructions)
            else:
                player.socket.sendall(instructions)

        elif "<list>" in msg:
            self.list_rooms(player) 

        elif "<manual>" in msg:
            player.socket.sendall(instructions)
        
        elif "<quit>" in msg:
            player.socket.sendall(QUIT_STRING.encode())
            self.remove_player(player)

        else:
            # check if in a room or not first
            if player.id in self.room_player_map:
                self.rooms[self.room_player_map[player.id]].broadcast(player, msg.encode())
            else:
                msg = 'You are currently not in any room! \n' \
                    + 'Use [<list>] to see available rooms! \n' \
                    + 'Use [<join> room_name] to join a room! \n'
                player.socket.sendall(msg.encode())
    
    def remove_player(self, player):
        if player.id in self.room_player_map:
            self.rooms[self.room_player_map[player.id]].remove_player(player)
            del self.room_player_map[player.id]
        print("Player: " + player.id + " has left\n")

    
class Room:
    def __init__(self, name):
        self.players = [] # a list of sockets
        self.name = name
        self.length = 0

    def welcome_new(self, from_player):
        msg = self.name + " welcomes: " + from_player.name + '\n'
        self.length+=1
        for player in self.players:
            player.socket.sendall(msg.encode())
    
    def broadcast(self, from_player, msg):
        msg = from_player.name.encode() + b":" + msg
        for player in self.players:
            player.socket.sendall(msg)

    def remove_player(self, player):
        self.players.remove(player)
        self.length-=1
        leave_msg = player.name.encode() + b"has left the room\n"
        self.broadcast(player, leave_msg)


