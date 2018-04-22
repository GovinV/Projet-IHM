#!/usr/bin/python3
# -*-coding:Utf-8 -*

import socket, pdb
import uuid

QUIT_STRING = "<$quit$>::"


class Lobby:
    def __init__(self):
        self.rooms = {} # {room_id: Room}
        self.room_player_map = {} # {playerid: roomId}
        self.players= [] # all players

    def welcome_new(self, new_player): # new player
        self.players.append(new_player)
        self.send_player(new_player,b"infos:: <name>\n")

    def list_rooms(self, player): # list room with ID and capacity
        
        if len(self.rooms) == 0:
            # no room create
            msg = "List::<no room>\n" 
            self.send_player(player,msg.encode())
        else:
            msg = "List::"
            for room in self.rooms:
                # check if players are not in game
                if self.rooms[room].status != "game":
                    msg += self.rooms[room].id + ":"+ self.rooms[room].name +":" \
                    + str(self.rooms[room].length) \
                    + ":" + str(self.rooms[room].capacity) + ">"
            msg+="\n"
            if msg == "List::\n":
                msg = "List::<no room>\n" 
            self.send_player(player,msg.encode())
    
    def handle_msg(self, player, msg): # main function - decode message
        if msg == "":
            return

        instructions = b"infos:: trouve\n"
        print(player.id + " says: " + msg+"\n")
        if "name:" in msg: # name client ( first connexion )
            name = (msg.split("\n")[0]).split(":")[1]
            player.name = name
            print("New connection from:", player.name)
            self.send_player(player,b"yourid::"+ player.id.encode()+ b"\n")

        elif "<create>" in msg: # create new room
            if len(msg.split(">")) >= 2: # error check
                room_name = (msg.split("\n")[0]).split(">")[1]
                new_room = Room(room_name, 4, player)
                room_id = new_room.id
                self.rooms[room_id] = new_room
                self.rooms[room_id].players.append(player)
                self.rooms[room_id].welcome_new(player)
                self.room_player_map[player.id] = room_id
                player.status = "inroom"
                new_msg="newroom::" + room_id + ":" + room_name +"\n"
                self.broadcast(player,new_msg)  
            else:
                self.send_player(player,instructions)

        elif "<join>" in msg: # join a room 
            if len(msg.split()) >= 2: # error check
                room_id = msg.split()[1] # ID room to join
                if not room_id in self.rooms: # new room:
                    self.send_player(player,b"error::This Room is not created: <list> to see.\n")
                # check if the players in room are not in game or the room isn't full 
                elif self.rooms[room_id].status != "game" or \
                     self.rooms[room_id].length < self.rooms[room_id].capacity:
                    self.rooms[room_id].players.append(player)
                    self.rooms[room_id].welcome_new(player)
                    self.room_player_map[player.id] = room_id
                    player.status = "inroom"
                    new_msg="roomjoin::" + room_id + ":" + player.id +"\n"
                    # say to all clients that one client has join this room
                    self.broadcast(player,new_msg)                     
                else:
                    self.send_player(player,b"error::This Room is full. Choose another one: <list> to see.\n")
            else:
                self.send_player(player,instructions) # instructions to join correctly a room

        elif "<leave>" in msg: # client leave the room
            if player.id in self.room_player_map: 
                old_room = self.room_player_map[player.id] # ID room
                self.rooms[old_room].remove_player(player) # remove player in the room
                if player == self.rooms[old_room].owner: # if player is the owner
                    for o in self.id_others(old_room):
                        del self.room_player_map[o]
                else:
                    del self.room_player_map[player.id]
                player.status = "inlobby"
                player.is_ready = False
                if self.rooms[old_room].length == 0:
                    del self.rooms[old_room]
                    new_msg ="roomdel::" + old_room + "\n"
                else:
                    new_msg = "playerleave::" + old_room + ":" + player.id +"\n"
                self.broadcast(player,new_msg)                                  
            else:
                self.send_player(player,b"error::You are not currently in a room\n")

        elif "<list>" in msg: # list room / function above this file
            self.list_rooms(player)

        elif "<ready>" in msg: # player ready for game
            if player.id in self.room_player_map: # check if player is in room
                room = self.room_player_map[player.id] # ID room
                if player.is_ready: # change value is_ready
                    player.is_ready = False
                    self.rooms[room].infogame(player,b"playerready::" + player.id.encode() + b":0\n")
                else:
                    player.is_ready = True  
                    self.rooms[room].infogame(player,b"playerready::" + player.id.encode() + b":1\n") 
            else:
                self.send_player(player,b"error::You are not currently in a room\n")

        elif "<startgame>" in msg: # start game is all players are ready
            if player.id in self.room_player_map:
                room = self.room_player_map[player.id]
                if player == self.rooms[room].owner: # check if owner is present
                    if self.rooms[room].all_ready(): # check if all players are ready
                        self.rooms[room].infogame(player,b"startgame::1")
                    else:
                        self.send_player(player,b"error:: not all ready\n")
                else:
                    self.send_player(player,b"startgame:: not owner\n")
            else:
                self.send_player(player,b"error::You are not currently in a room\n")

        elif "<quit>" in msg: # quit server 
            self.send_player(player,QUIT_STRING.encode())
            self.remove_player(player)

        elif "<players>" in msg: # show players in room
            if player.id in self.room_player_map:
                print("ouais")
                room = self.room_player_map[player.id]
                self.rooms[room].send_players_list(player)
            else:
                self.send_player(player,b"error::You are not currently in a room\n")

        elif "<changeroomname>" in msg: # change room name 
            if len(msg.split(">")) >= 2: # error check
                room_name = (msg.split("\n")[0]).split(">")[1]
                if player.id in self.room_player_map:
                    room = self.room_player_map[player.id]
                    if player == self.rooms[room].owner: # have to be the owner
                        self.rooms[room].name = room_name
                        new_msg = "changeroomname::" + room + ":" + room_name +"\n"
                        # say to all players the new room name
                        self.broadcast(player,new_msg)
                        #self.rooms[room].infogame(player,b"room"+new_msh.encode())
                    else:
                        self.send_player(player,b"changeroomname:: not owner\n")
                else:
                    self.send_player(player,b"error::You are not currently in a room\n")
            else:
                # instructions for the command if fail
                self.send_player(player,instructions)

        elif "<changemaxplayer>" in msg: # change capacity of the room
            if len(msg.split()) >= 2: # error check
                room_MP = msg.split()[1]
                if player.id in self.room_player_map:
                    room = self.room_player_map[player.id]
                    if player == self.rooms[room].owner: # have to be the owner
                        if self.rooms[room].length <= int(room_MP): # check new value
                            self.rooms[room].capacity = int(room_MP)
                            new_msg = "changemaxplayer::" + room + ":" + room_MP +"\n"
                            # say to all players the new capacity room
                            self.broadcast(player,new_msg)
                    else:
                        self.send_player(player,b"changemaxplayer:: not owner\n")
                else:
                    self.send_player(player,b"error::You are not currently in a room\n")
            else:
                # instructions for the command if fail
                self.send_player(player,instructions)

        else:
            # check if in a room or not first
            if player.id in self.room_player_map:
                self.rooms[self.room_player_map[player.id]].broadcast(player, msg.encode())
            else:
                msg = "error:: You are currently not in any room! \n"
                self.send_player(player,msg.encode())
    
    # function to remove players
    def remove_player(self, player):
        self.players.remove(player)
        if player.id in self.room_player_map:
            room = self.room_player_map[player.id]
            self.rooms[room].remove_player(player)
            if player == self.rooms[room].owner:
                for o in self.id_others(room):
                    del self.room_player_map[o]
            else:
                del self.room_player_map[player.id]
            if self.rooms[room].length == 0:
                del self.rooms[room]
                new_msg ="roomdel::" + room + "\n"
            else:
                new_msg = "playerleave::" + room + ":" + player.id +"\n"
            self.broadcast(player,new_msg)
        print("Player: " + player.id + " has left\n")

    # function to send to all players except the sender
    def broadcast(self, from_player, msg):
        for player in self.players:
            if player != from_player:
                if player.status == "inlobby":
                    self.send_player(player,msg.encode())

    # function to show ID players 
    def id_others(self,room):
        ret = []
        for k,v in self.room_player_map.items():
            if v == room:
                ret.append(k)
        return ret

    # function to send message 
    def send_player(self,player,msg):
        try:
            player.socket.sendall(msg)
        except:
            pass

class Room:
    def __init__(self, name, capacity, owner):
        self.players = [] # a list of sockets
        self.name = name # name room
        self.length = 0 # length room
        self.capacity = capacity # capacity room
        self.owner = owner # owner of the room
        self.status = "waiting" # status room ( waiting or game )
        self.id = str(uuid.uuid4()) # ID room

    def welcome_new(self, from_player): # new player in a room / send informations room
        msg = "playerjoin::" + from_player.id + ":" + from_player.name + "\n"
        self.length+=1
        for player in self.players:
            self.send_player(player,msg.encode())
    
    def broadcast(self, from_player, msg): # message to all players in the room
        msg = b"ingame::" + from_player.name.encode() + b":" + msg
        for player in self.players:
            if player != from_player:
                self.send_player(player,msg)

    def infogame(self, from_player, msg): # change status room to waiting -> game
        if msg == b"startgame::1":
            self.status = "game"
        for player in self.players:
            if player != from_player:
                self.send_player(player,msg)

    def remove_player(self, player): # remove players in a room
        if player == self.owner:
            for p in self.players:
                if p != self.owner:
                    self.players.remove(p)
                    p.status = "inlobby"
                    p.is_ready = False
                    self.length-=1
                    self.send_player(p,b"playerleave::"+ p.id.encode() + b":"+ p.name.encode() + b"\n")
        self.players.remove(player)
        self.length-=1
        leave_msg = b"playerleave::"+ player.id.encode() + b": "+ player.name.encode() + b"\n"
        self.infogame(player, leave_msg)

    def send_players_list(self, player): # send informations to all players in a room
        msg ="players::"
        for player in self.players:
            msg += player.id + ":" + player.name +">"
        msg+="\n"
        print("alllez")
        self.send_player(player,msg.encode())

    def all_ready(self): # check if all players are ready
        ret=True
        for player in self.players:
            if not player.is_ready:
                ret=False
                break
        return ret

    def send_player(self,player,msg): # send to all players (players with no room too)
        try:
            player.socket.sendall(msg)
        except:
            pass