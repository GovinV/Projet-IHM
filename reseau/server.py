#!/usr/bin/python3
# -*-coding:Utf-8 -*

import signal
import select, socket, sys
from lobby import Lobby, Room
from player import Player
import player



def signal_handler(signal, frame):
        print('Arrivederci!')
        sys.exit(0)

signal.signal(signal.SIGINT, signal_handler)

READ_BUFFER = 4096

host = "127.0.0.1"
port = 8888 
MAX_CLIENTS = 30

listen_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
listen_sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
listen_sock.setblocking(0)
listen_sock.bind((host,port))
listen_sock.listen(MAX_CLIENTS)
print("Now listening at ", (host, port))
lobby = Lobby()
connection_list = []
connection_list.append(listen_sock)

while True:
    # Player.fileno()
    read_players, write_players, error_sockets = select.select(connection_list, [], [])
    for player in read_players:
        if player is listen_sock: # new connection, player is a socket
            new_socket, add = player.accept()
            new_player = Player(new_socket)
            connection_list.append(new_player)
            lobby.welcome_new(new_player)

        else: # new message
            try:
                msg = player.socket.recv(READ_BUFFER)
            except:
                continue
            if msg:
                msg = msg.decode().lower()
                lobby.handle_msg(player, msg)
            else:
                player.socket.close()
                connection_list.remove(player)

    for sock in error_sockets: # close error sockets
        sock.close()
        connection_list.remove(sock)
