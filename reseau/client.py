#!/home/constan/Documents/logiciels/Python-3.6.4/python
# -*-coding:Utf-8 -*

import socket
import sys

def main():
    soc = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    host = "127.0.0.1"
    port = 8888

    try:
        soc.connect((host, port))
    except:
        print("Connection error")
        sys.exit()

    print("Enter 'quit' to exit")
    message = raw_input(" -> ")

    while message != 'quit':
        soc.sendall(message.encode("utf8"))
        if soc.recv(5120).decode("utf8") == "-":
            pass        # continue

        message = raw_input(" -> ")

    soc.send(b'--quit--')
    #soc.close()

if __name__ == "__main__":
    main()