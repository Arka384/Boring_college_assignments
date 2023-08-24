import socket
import threading
from datetime import datetime

ipAddr = "127.0.0.1"    #address for localhost
port = 5555

#thread for new client
def onNewClient(con, addr):
    data = con.recv(1024)
    if(data.decode() == "GET_TIME"):
        print("Client: ", addr , " requested for date and time")
        now = datetime.now()
        curr = now.strftime("Date: %d/%m/%Y, Time: %H:%M:%S")
        con.send(curr.encode()) #send this string to client
        print("Response sent to client")
    else:
        print("Recieved: ", data.decode(), ", from: ", addr)
        msg = "Different request given"
        con.send(msg.encode())
    con.close() 

serverSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print("Server socker object created")
serverSocket.bind((ipAddr, port))
print("Socket bind successfull")
print("Server is listining for clients")

while True:
    serverSocket.listen(5)  #at most 5 client connection
    con, clientAddr = serverSocket.accept()
    print("New connection")
    print("Connected to client: ", clientAddr)
    t = threading.Thread(target = onNewClient, args = (con, clientAddr, ))
    t.start()
    
serverSocket.close()
