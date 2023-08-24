import socket

ipAddr = "127.0.0.1"
port = 5555

clientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print("Client socker object created")
clientSocket.connect((ipAddr, port))    #connect with server with particular port
print("Connected with server")

#ask for date-time to server
message = input("Enter message: ")  #GET_TIME for time
clientSocket.send(message.encode())

#recieve date time from server
if(message == "GET_TIME"):
    print("Request for current date and time sent to server")
    currTime = clientSocket.recv(1024)
    print("Current date and time recieved from server")
    print(currTime.decode())
else:
    msg = clientSocket.recv(1024)
    print(msg.decode())

clientSocket.close()    #close connections
