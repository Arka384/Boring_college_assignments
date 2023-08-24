import socket

ipAddr = "127.0.0.1"
port = 5555

udpClientSocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
print("Socket object created")

while True:
	print("Enter a student name: ")
	msg = input()
	if(msg == "exit"):
		break
	udpClientSocket.sendto(msg.encode(), (ipAddr, port)) #send message to server
	data = udpClientSocket.recvfrom(1024)	#recieve response
	#data[0] contains the message from server
	#data[1] contains the address of server
	add = data[0].decode()
	print("Address for student: ", end="")
	print(add, "\n")

udpClientSocket.close()