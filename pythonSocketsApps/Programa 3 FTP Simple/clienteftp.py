# client.py

import socket                   # Import socket module

s = socket.socket()             # Create a socket object
host = socket.gethostname()     # Get local machine name
port = 60000                    # Reserve a port for your service.

s.connect((host, port))
s.send("Hola servidor!".encode())

with open('received_file', 'wb') as f:
    print ('Archivo abierto')
    while True:
        print('Recibiendo datos...')
        data = s.recv(1024)
        print('datos=%s', (data))
        if not data:
            break
        # write data to a file
        f.write(data)

f.close()
print('Archivo recibido satisfactoriamente')
s.close()
print('Conexion cerrada')
