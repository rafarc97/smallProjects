import socket
import os

HOST = 'localhost'
PORT = 1025

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HOST, PORT))
s.send("Hola servidor".encode())

mensaje = s.recv(1024)

print("RECIBIDO: [" +str(mensaje)+ "] del servidor")
s.close()
