import scapy.all as scapy

def get_mac(ip):
    # Send an ARP request to get the MAC address corresponding to the given IP
    arp_request = scapy.ARP(pdst=ip)
    broadcast = scapy.Ether(dst="ff:ff:ff:ff:ff:ff")
    arp_request_broadcast = broadcast/arp_request
    answered_list = scapy.srp(arp_request_broadcast, timeout=1, verbose=False)[0]

    # Return the MAC address from the response
    if answered_list:
        return answered_list[0][1].hwsrc
    else:
        return None

def sniff_arp():
    scapy.sniff(store=False, prn=process_arp_packet)

def process_arp_packet(packet):
    if packet.haslayer(scapy.ARP) and packet[scapy.ARP].op == 2:
        # Check if the sender's MAC matches the MAC in the ARP cache
        real_mac = get_mac(packet[scapy.ARP].psrc)
        response_mac = packet[scapy.ARP].hwsrc
        if real_mac != response_mac:
            print("[!] Possible ARP poisoning detected!")

sniff_arp()