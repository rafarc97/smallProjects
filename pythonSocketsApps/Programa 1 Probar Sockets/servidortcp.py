import socket

HOST = 'localhost'
PORT = 1025

socketServidor = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

socketServidor.bind((HOST,PORT))
socketServidor.listen(1)
print("Nos quedamos a la espera ... ")
s_cliente, addr = socketServidor.accept()

mensaje = s_cliente.recv(1024)

print("Recibo: [" +str(mensaje)+ "] del cliente con la dirección " +str(addr))

s_cliente.send("Hola, cliente, soy el servidor".encode())

s_cliente.close()
socketServidor.close()