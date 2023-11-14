import scapy.all as scapy

def traceroot(ipAddr, maxHops):
    print("\nhops\t Routers-IP")
    for i in range (1, maxHops+1):
        pack = scapy.IP(dst=ipAddr, ttl=i)/scapy.ICMP()/"Hello"
        rep = scapy.sr1(pack, timeout=1, verbose=False)
        if(rep == None):
            print(i, "\t", "*")
        else:
            x = rep[0]
            xSrc = x[scapy.IP].src
            print(i, "\t", xSrc)
            if(xSrc == ipAddr):
                return
    print("Destination not found within ", maxHops, " hops")
            

ipAddr = input("Enter target IP: ")
maxHops = int(input("Enter max hops: "))

traceroot(ipAddr, maxHops)