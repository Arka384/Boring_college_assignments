import scapy.all as scapy
import ipaddress as ipaddr
import threading

ipList = []

def sendPackets(low, high):
    for i in range(low, high):
        try:
            # print(ipList[i])
            packet = scapy.IP(dst = ipList[i])/scapy.ICMP()/"Hello"
            reply = scapy.sr1(packet, verbose=False, retry = 0, timeout = 2)
            if reply:
                print("Host: ", ipList[i], " responsive")
        except Exception as e:
            pass

"""
    import ipaddress as ipaddr
    addresses = ipaddr.IPv4Network(addr)
"""

addr = input("Enter network address in CIDR notation (ex:192.168.0.0/24): ")
try:
    addresses = ipaddr.IPv4Network(addr)
except ValueError:
    print("Invalid address given")
    exit()

for i in addresses:
    ipList.append(str(i))
print("Number of possible host IP: ", ipList.__len__())


numThreads = 20     # decide how many threads needed 
loadPerThread = len(ipList)//(numThreads-1)
# divide the load equally on every thread
lastThreadLoad = len(ipList) - (loadPerThread*(numThreads-1))
threads = []

for i in range(0, numThreads-1):
    low = i*loadPerThread
    # created threads with the function as target
    t = threading.Thread(target=sendPackets, args=(low, low + loadPerThread, ))
    threads.append(t)
t = threading.Thread(target=sendPackets, args=(len(ipList) - lastThreadLoad, lastThreadLoad))
threads.append(t)

# start all threads
for thread in threads:
    thread.start()
# then wait for all of them to end
for thread in threads:
    thread.join()