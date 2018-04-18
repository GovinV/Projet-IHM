#!/usr/bin/python3
# -*-coding:Utf-8 -*

import socket, pdb
import uuid

QUIT_STRING = "<$quit$>"


class Lobby:
    def __init__(self):
        self.rooms = {} # {room_id: Room}
        self.room_player_map = {} # {playerid: roomId}
        self.players= [] # all players

    def welcome_new(self, new_player):
        self.players.append(new_player)
        new_player.socket.sendall(b"<name>\n")

    def list_rooms(self, player):
        
        if len(self.rooms) == 0:
            msg = "<no room>\n" 
            player.socket.sendall(msg.encode())
        else:
            msg = ""
            for room in self.rooms:
                msg += self.rooms[room].id + ":"+ self.rooms[room].name +":" \
                + str(self.rooms[room].length) \
                + ":" + str(self.rooms[room].capacity) + ">"
            msg+="\n"
            player.socket.sendall(msg.encode())
    
    def handle_msg(self, player, msg):
        
        instructions = b"Instructions:\n"\
            + b"[<list>] to list rooms \n"\
            + b"[<create> room_name] to create a room\n" \
            + b"[<join> room_id] to join a room\n" \
            + b"[<leave>] to leave your current room\n" \
            + b"[<manual>] to show instructions\n" \
            + b"[<quit>] to quit\n" \
            + b"Otherwise start typing and enjoy!" \
            + b"\n"

        print(player.id + " says: " + msg)
        if "name:" in msg:
            name = msg.split()[1]
            player.name = name
            print("New connection from:", player.name)
            player.socket.sendall(instructions)

        elif "<create>" in msg:
            if len(msg.split()) >= 2: # error check
                room_name = msg.split()[1]
                new_room = Room(room_name, 4, player)
                room_id = new_room.id
                self.rooms[room_id] = new_room
                self.rooms[room_id].players.append(player)
                self.rooms[room_id].welcome_new(player)
                self.room_player_map[player.id] = room_id
                player.status = "inroom"
                new_msg="newroom:" + room_id + ":" + room_name +"\n"
                self.broadcast(player,new_msg)
            else:
                player.socket.sendall(instructions)

        elif "<join>" in msg:
            if len(msg.split()) >= 2: # error check
                room_id = msg.split()[1]
                if not room_id in self.rooms: # new room:
                    player.socket.sendall(b"This Room is not created:\n <list> to see.\n")
                elif self.rooms[room_id].length < self.rooms[room_id].capacity:
                    self.rooms[room_id].players.append(player)
                    self.rooms[room_id].welcome_new(player)
                    self.room_player_map[player.id] = room_id
                    player.status = "inroom"
                    new_msg="roomjoin:" + room_id + ":" + player.id +"\n"
                    self.broadcast(player,new_msg)                    
                else:
                    player.socket.sendall(b"This Room is full. Choose another one:\n <list> to see.\n")
            else:
                player.socket.sendall(instructions)

        elif "<leave>" in msg:
            if player.id in self.room_player_map: 
                old_room = self.room_player_map[player.id]
                self.rooms[old_room].remove_player(player)
                del self.room_player_map[player.id]
                player.status = "inlobby"
                if self.rooms[old_room].length == 0:
                    del self.rooms[old_room]
                    new_msg ="roomdel:" + old_room + "\n"
                else:
                    new_msg = "playerleave:" + old_room + ":" + player.id +"\n"
                self.broadcast(player,new_msg)                                    
            else:
                player.socket.sendall(b"You are not currently in a room\n")

        elif "<list>" in msg:
            self.list_rooms(player) 

        elif "<manual>" in msg:
            player.socket.sendall(instructions)
        
        elif "<quit>" in msg:
            player.socket.sendall(QUIT_STRING.encode())
            self.remove_player(player)

        elif "<players>" in msg:
            if player.id in self.room_player_map:
                room = self.room_player_map[player.id]
                self.rooms[room].send_players_list(player)
            else:
                player.socket.sendall(b"You are not currently in a room\n")

        elif "<changeroomname>" in msg:
            if len(msg.split()) >= 2: # error check
                room_name = msg.split()[1]
                if player.id in self.room_player_map:
                    room = self.room_player_map[player.id]
                    if player == self.rooms[room].owner:
                        self.rooms[room].name = room_name
                        new_msg = "roomchangename:" + room + ":" + room_name +"\n"
                        self.broadcast(player,new_msg)
                    else:
                        player.socket.sendall(b"changeroomname: not owner\n")
                else:
                    player.socket.sendall(b"You are not currently in a room\n")
            else:
                player.socket.sendall(instructions)

        elif "<changemaxplayer>" in msg:
            if len(msg.split()) >= 2: # error check
                room_MP = msg.split()[1]
                if player.id in self.room_player_map:
                    room = self.room_player_map[player.id]
                    if player == self.rooms[room].owner:
                        if self.rooms[room].capacity > int(room_MP):
                            self.rooms[room].capacity = int(room_MP)
                            new_msg = "roomchangecapacity:" + room + ":" + room_MP +"\n"
                            self.broadcast(player,new_msg)
                    else:
                        player.socket.sendall(b"changemaxplayer: not owner\n")
                else:
                    player.socket.sendall(b"You are not currently in a room\n")
            else:
                player.socket.sendall(instructions)

        else:
            # check if in a room or not first
            if player.id in self.room_player_map:
                self.rooms[self.room_player_map[player.id]].broadcast(player, msg.encode())
            else:
                msg = "You are currently not in any room! \n" \
                    + "Use [<list>] to see available rooms! \n" \
                    + "Use [<create>] to create a room! \n" \
                    + "Use [<join> room_name] to join a room! \n"
                player.socket.sendall(msg.encode())
    
    def remove_player(self, player):
        self.players.remove(player)
        if player.id in self.room_player_map:
            room = self.room_player_map[player.id]
            self.rooms[room].remove_player(player)
            if self.rooms[room].length == 0:
                del self.rooms[room]
            del self.room_player_map[player.id]
        print("Player: " + player.id + " has left\n")

    def broadcast(self, from_player, msg):
        for player in self.players:
            if player != from_player:
                if player.status == "inlobby":
                    player.socket.sendall(msg.encode())
    
class Room:
    def __init__(self, name, capacity, owner):
        self.players = [] # a list of sockets
        self.name = name
        self.length = 0
        self.capacity = capacity
        self.owner = owner
        self.id = str(uuid.uuid4())

    def welcome_new(self, from_player):
        msg = "playerjoin:" + from_player.id + ":" + from_player.name + "\n"
        self.length+=1
        for player in self.players:
            player.socket.sendall(msg.encode())
    
    def broadcast(self, from_player, msg):
        msg = from_player.name.encode() + b":" + msg
        for player in self.players:
            if player != from_player:
                player.socket.sendall(msg)

    def remove_player(self, player):
        self.players.remove(player)
        self.length-=1
        leave_msg = b"playerquit:"+ player.id.encode() + b": "+ player.name.encode() + b"\n"
        self.broadcast(player, leave_msg)

    def send_players_list(self, player):
        msg =""
        for player in self.players:
            msg += player.id + ":" + player.name +">"
        msg+="\n"
        player.socket.sendall(msg.encode())