#!/usr/bin/python3
# -*-coding:Utf-8 -*

import signal
import select, socket, sys
from lobby import Lobby, Room
from player import Player
import player


# function check CTRL+C in order to quit server
def signal_handler(signal, frame):
        print('ENDSERVER!')
        sys.exit(0)

signal.signal(signal.SIGINT, signal_handler)

READ_BUFFER = 4096

# definition port / adress server
host = "0.0.0.0"
port = 2213
MAX_CLIENTS = 30

listen_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# can re-use adress with option SO_REUSEADDR
listen_sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
listen_sock.setblocking(0)
listen_sock.bind((host,port))
# max clients
listen_sock.listen(MAX_CLIENTS)
print("Now listening at ", (host, port))
lobby = Lobby()
connection_list = []
connection_list.append(listen_sock)

while True:
    # Player.fileno()
    # utilisation of function select to have several clients
    read_players, write_players, error_sockets = select.select(connection_list, [], [])
    for player in read_players:
        if player is listen_sock: # new connection / one socket = one player
            new_socket, add = player.accept()
            new_player = Player(new_socket)
            connection_list.append(new_player)
            lobby.welcome_new(new_player)

        else: # nouveau message
            try:
                msg = player.socket.recv(READ_BUFFER)
            except:
                continue
            if msg:
                # handle message with lobby.py
                msg = msg.decode().lower()
                for m in msg.split("\n")
                    lobby.handle_msg(player, m)
            else:
                player.socket.close()
                connection_list.remove(player)

    for sock in error_sockets: # close sockets
        sock.close()
        connection_list.remove(sock)
