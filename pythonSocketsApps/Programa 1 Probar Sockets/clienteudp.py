import socket
import os

HOST = 'localhost'
PORT = 1025

s_udp = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s_udp.sendto("soy el cliente".encode(),(HOST,PORT))
s_udp.close()