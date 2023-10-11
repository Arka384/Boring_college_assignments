import scapy.all as scapy
from prettytable import PrettyTable

sourceIPs = []
srcDstIpPairs = []
srcDstPortPairs = []
filtered = {}   # src, dst -> list of packets from src to dst
filteredOnPort = {} # (src,dst) : [sPort, dPort] -> list of packets
unwantedIP = ["0.0.0.0"]

# structure 1
# method to classify packets w.r.t unique src and dest IP
# creates a map with [src, dst] as key
# and list of packets between src and dst as value
# [srcIP, dstIP] -> list of packets from src to dst

"""
    x s3 d3
    [s1,d1] = [1,2,3,4,54,x]
    [s1,d2] = [5,6,6,7]
    [s3,d3] = [x]
"""

# structure 2
# classify packets with src, dst
# then source port and dst port, Nested dictionary
# dict [srcIp, dstIp] -> dict [
#      [srcPort, dstPort] -> list of packets
#   ]
def classifyPacketsWithPort(packets):
    for packet in packets:  # for all packets
        if not scapy.IP in packet:
            continue
        src = packet[scapy.IP].src
        dst = packet[scapy.IP].dst
        # if src in unwantedIP or dst in unwantedIP:
        #     continue
        
        # finding all unique sources (question 2)
        if src not in sourceIPs:
            sourceIPs.append(src)

        ips = str([src, dst])
        # add the classification wrt of ips here (question 3)
        if ips not in filtered: # new (srcIP, dstIP) pair found
            # keep track of IP pairs
            srcDstIpPairs.append([src, dst])
            # sub = [packet]
            filtered[ips] = [packet]
        else:   # existing ip pair. So add packet to list
            filtered[ips].extend(packet)

        # continue with classification of ports (question 4)
        sPort = dPort = 0
        if scapy.TCP in packet: # find source port and dest port 
            sPort = packet[scapy.TCP].sport
            dPort = packet[scapy.TCP].dport
        elif scapy.UDP in packet:
            sPort = packet[scapy.UDP].sport
            dPort = packet[scapy.UDP].dport
        ports = str([sPort, dPort])

        if ips not in filteredOnPort:  # new (src, dst) pair found
            tempDict = {}   # creating sub dictionary
            sub = [packet]
            tempDict[ports] = sub
            # keep track of port pairs
            srcDstPortPairs.append([sPort, dPort])
            filteredOnPort[ips] = tempDict
        else:
            portsDict = filteredOnPort[ips] # get existing sub dict
            if ports not in portsDict:  # if new pair of (sPort, dPort)
                srcDstPortPairs.append([sPort, dPort])
                sub = [packet]
                portsDict[ports] = sub
            else:
                portsDict[ports].extend(packet)

def displayUniqueHosts():
    print("Number of unique host IP: ", len(sourceIPs))
    table = PrettyTable(["Unique host IP"])
    for ip in sourceIPs:
        table.add_row([ip])
    print(table)


# get average packet details from a list of packets
# number of packets and avg size of packet payload
# for both TCP and UDP
def getAvgPacketDetails(packets):
    tcpPacketCount = tcpPayloadLength = udpPacketCount = udpPayloadLength = 0
    for pack in packets:
        if scapy.TCP in pack:
            tcpPacketCount += 1
            tcpPayloadLength += len(pack[scapy.TCP].payload)
        elif scapy.UDP in pack:
            udpPacketCount += 1
            udpPayloadLength += len(pack[scapy.UDP].payload)
    
    if tcpPacketCount != 0:
        tcpPayloadLength /= tcpPacketCount
        tcpPayloadLength = '%.2f'%(tcpPayloadLength)
    if udpPacketCount != 0:
        udpPayloadLength /= udpPacketCount
        udpPayloadLength = '%.2f'%(udpPayloadLength)

    return [tcpPacketCount, tcpPayloadLength, udpPacketCount, udpPayloadLength]

        
# get info about packets
# for each pair of source/dest IP address
# get packet details
def getSrcDstIpinfo():
    table = PrettyTable(["SourceIP", "DestIP", "Protocol", "No of Segments", "Avg Payload size"])
    pairIndex = 0

    for ip, p in filtered.items():
        data = getAvgPacketDetails(p)
        table.add_row([srcDstIpPairs[pairIndex][0], srcDstIpPairs[pairIndex][1], "TCP", data[0], data[1]])
        table.add_row(["", srcDstIpPairs[pairIndex][1], "UDP", data[2], data[3]], divider=True)
        pairIndex += 1
    print(table)
    

# get info about packets
# for each quadruple of sourceIP/destIP and 
# source_port/dest_port get packet details
def getSrcDstIpPortInfo():
    table = PrettyTable(["SourceIP", "DestIP", "Protocol", "S_Port", "D_Port", "No_of_Segments", "Avg_Payload_Size"])
    IpIndex = 0
    PortIndex = 0

    for ips, subDict in filteredOnPort.items():
        for ports, packs in subDict.items():
            data = getAvgPacketDetails(packs)
            table.add_row([srcDstIpPairs[IpIndex][0], srcDstIpPairs[IpIndex][1], "TCP", 
                           srcDstPortPairs[PortIndex][0], srcDstPortPairs[PortIndex][1], data[0], data[1]])
            table.add_row(["", srcDstIpPairs[IpIndex][1], "UDP", 
                           srcDstPortPairs[PortIndex][0], srcDstPortPairs[PortIndex][1], data[2], data[3]], divider=True)
            PortIndex += 1
        IpIndex += 1
    print(table)

        
    
def main():
    packetsToCapture = 100
    packets = scapy.sniff(count = packetsToCapture)
    print(packets)  # gives an overview of packets captured
    print("===================================================")

    classifyPacketsWithPort(packets)    # complete filtering
    
    displayUniqueHosts()
    print("===================================================")
    print("Details of packets about all sourceIP/destinationIP pairs")
    getSrcDstIpinfo()
    print("===================================================")
    print("Details of packets for sourceIP/destIP along with sourcePort/destPort")
    getSrcDstIpPortInfo()
    
if __name__ == "__main__":
    main()