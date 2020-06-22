# Python program to implement client side of chat room.
import socket
import select
import sys

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
if len(sys.argv) != 3:
	print ("Uso correcto: script, Direccion IP, Numero de puerto")
	exit()
IP_address = str(sys.argv[1])
Port = int(sys.argv[2])
server.connect((IP_address, Port))

while True:

	# maintains a list of possible input streams
	sockets_list = [sys.stdin, server]


	read_sockets,write_socket, error_socket = select.select(sockets_list,[],[])

	for socks in read_sockets:
		if socks == server:
			message = socks.recvfrom(2048)
			print (message)
		else:
			message = sys.stdin.readline()
			server.sendto(message.encode(), (IP_address,Port))
			sys.stdout.write("<Tu>")
			sys.stdout.write(message)
			sys.stdout.flush()
server.close()
