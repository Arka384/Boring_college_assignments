import scapy.all as scapy
import threading
ipAddr = ""

def isOpen(port):
    try:
        # create and send the packet
        packet = scapy.IP(dst=ipAddr)/scapy.TCP(dport=port, flags="S")
        res = scapy.sr1(packet, timeout=0.5, verbose=False)
        if res is not None and scapy.TCP in res:
            # if TCP response found then check for SYN and ACK flag 
            ack = (res[scapy.TCP].flags.S and res[scapy.TCP].flags.A)
            return ack
    except Exception as e:
        return False
    return False    

def driver(low, high):  # check in the given port range
    for port in range(low, high):
        if isOpen(port):    # check if both SYN and ACK is set or not
            print("<Port:", port, "> (SYN + ACK) recieved")


ipAddr = input("Enter host IP: ")

# creating a bunch of threads to make it faster
# each thread will be assigned a range of ports 
# threads will parallelly execute
numThreads = 10     # decide how many threads needed 
loadPerThread = 1023//(numThreads-1)
# divide the load equally on every thread
lastThreadLoad = 1023 - (loadPerThread*(numThreads-1))
threads = []

for i in range(0, numThreads-1):
    low = i*loadPerThread
    # created threads with the function as target
    t = threading.Thread(target=driver, args=(low, low + loadPerThread, ))
    threads.append(t)
t = threading.Thread(target=driver, args=(1023 - lastThreadLoad, lastThreadLoad))
threads.append(t)

# start all threads
for thread in threads:
    thread.start()
# then wait for all of them to end
for thread in threads:
    thread.join()
