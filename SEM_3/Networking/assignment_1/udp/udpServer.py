import socket
import csv

ipAddr = "127.0.0.1"
port = 5555

#creating map of addresses
data = {}
with open('data.csv', mode = 'r') as file:
	csvFile = csv.reader(file)	#load data from a CSV file
	for lines in csvFile:
		data[lines[0]] = lines[1]	#populate the dictonary
		

udpServerSocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) #udp socket object
#if connection in port already exists then reuse that connection
udpServerSocket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
print("Socket object created")
udpServerSocket.bind((ipAddr, port))
print("Socket bind done")

#recieve student name from client
while True:
	conn = udpServerSocket.recvfrom(1024)	#recieve data from client
	#conn[0] contains the message send by client
	#conn[1] contains the address of client who has sent the data
	studentName = conn[0].decode()
	print("Name = \"", studentName, "\" revieved from: ", conn[1])
	add = data.get(studentName)	#get data from dictionary

	if add == None:	#if address not found
		msg = "Student record not found"
		udpServerSocket.sendto(msg.encode(), conn[1])
	else:
		udpServerSocket.sendto(add.encode(), conn[1])

udpServerSocket.close()	#close connection
