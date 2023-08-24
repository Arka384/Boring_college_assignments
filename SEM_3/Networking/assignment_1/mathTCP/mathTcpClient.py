import socket

ipAddr = "127.0.0.1"
port = 5555

clientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM);
print("Client socker object created")
clientSocket.connect((ipAddr, port))    #connect with server
print("Connected with server")

#ask for expression
print("Enter and integer expression to evaluate")
message = input()
clientSocket.send(message.encode()) #send the expression to server
print("Request for expression evaluation sent to server")

result = clientSocket.recv(1024)    #recieve result of expression
print("Result recieved from server")
print("Result of expression is: ", result.decode())

clientSocket.close()    #close all connection
