import socket
import threading

ipAddr = "127.0.0.1"    #address of localhost
port = 5555

def onNewThread(con, addr):
    expression = con.recv(1024).decode()    #recieve expression from client
    print("From client: ", addr)
    print("Expression recieved: ", expression, "\n")
    try:
        result = eval(expression)   #evaluate the expression
    except: #if any exception occurs
        msg = "Invalid expression given"
        print(msg, "\n")
        con.send(msg.encode())
    else:   #if no exception occurs
        print("Sending result back to client: ", addr, "\n")
        con.send(str(result).encode())
    con.close()

serverSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print("Server socker object created")
serverSocket.bind((ipAddr, port))   #bind socket with localhost and port
print("Socket bind successfull")
print("Server is listining for clients")

while True:
    serverSocket.listen(5)
    con, clientAddr = serverSocket.accept() #accept incoming connection
    print("New connection")
    print("Connected to client: ", clientAddr)
    t = threading.Thread(target=(onNewThread), args=(con, clientAddr, ))
    t.start()

serverSocket.close()
