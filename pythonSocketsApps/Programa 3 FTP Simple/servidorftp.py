# server.py

import socket                   # Import socket module

port = 60000                    # Reserve a port for your service.
s = socket.socket()             # Create a socket object
host = socket.gethostname()     # Get local machine name
s.bind((host, port))            # Bind to the port
s.listen(5)                     # Now wait for client connection.

print ('Servidor escuchando....')

while True:
    conn, addr = s.accept()     # Establish connection with client.
    print ('Conexion conseguida desde '), addr
    data = conn.recv(1024)
    print('Servidor recibido', repr(data))

    filename='mytext.txt'
    f = open(filename,'rb')
    l = f.read(1024)
    while (l):
       conn.send(l)
       print('Enviado ',repr(l))
       l = f.read(1024)
    f.close()

    print('Envio realizado')
    conn.send('Gracias por tu conexion'.encode())
    conn.close()
