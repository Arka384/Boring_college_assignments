import scapy.all as scapy
from prettytable import PrettyTable

sourceIPs = []
srcDstIpPairs = []
srcDstPortPairs = []
filtered = {}   # src, dst -> list of packets from src to dst
filteredOnPort = {} # (src,dst) : [sPort, dPort] -> list of packets

unwantedIP = ["0.0.0.0"]

# method to get all unique host IP
def findDistinctHostIP(packets):
    for packet in packets:
        try:
            if not scapy.IP in packet:
                continue
            src = packet[scapy.IP].src
            if src in unwantedIP:
                continue
            if src not in sourceIPs:
                sourceIPs.append(src)
        except Exception as e:
            print(e)
    print("Number of unique host IP: ", len(sourceIPs))
    table = PrettyTable(["Unique host IP"])
    for ip in sourceIPs:
        table.add_row([ip])
    print(table)


# method to classify packets w.r.t unique src and dest IP
# creates a map with [src, dst] as key
# and list of packets between src and dst as value
# [srcIP, dstIP] -> list of packets from src to dst
def classifyPacketsWithIP(packets):
    for packet in packets:  # for all packets
        if not scapy.IP in packet:
            continue
        src = packet[scapy.IP].src
        dst = packet[scapy.IP].dst
        if src in unwantedIP or dst in unwantedIP:
            continue
        currentPair = [src, dst]
        temp = str(currentPair)
        if temp not in filtered: # new (srcIP, dstIP) pair found
            # keep track of IP pairs
            srcDstIpPairs.append(currentPair)
            sub = [packet]
            filtered[temp] = sub
        else:
            # existing ip pair. So add packet to list
            filtered[temp].extend(packet)

def displayFilteredPackets():
    for ip, p in filtered.items():
        print(ip)
        for i in p:
            if scapy.UDP in i:
                print(i[scapy.UDP].sport, " -> ", i[scapy.UDP].dport)
            elif scapy.TCP in i:
                print(i[scapy.TCP].sport, " -> ", i[scapy.TCP].dport)


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
        if src in unwantedIP or dst in unwantedIP:
            continue
        ips = str([src, dst])
        sPort = 0
        dPort = 0
        if scapy.TCP in packet: # find source port and dest port 
            sPort = packet[scapy.TCP].sport
            dPort = packet[scapy.TCP].dport
        elif scapy.UDP in packet:
            sPort = packet[scapy.UDP].sport
            dPort = packet[scapy.UDP].dport
        currentPortPair = [sPort, dPort]
        ports = str([sPort, dPort])

        if ips not in filteredOnPort:  # new (src, dst) pair found
            tempDict = {}   # creating sub dictionary
            sub = [packet]
            tempDict[ports] = sub
            # keep track of port pairs
            srcDstPortPairs.append(currentPortPair)
            filteredOnPort[ips] = tempDict
        else:
            portsDict = filteredOnPort[ips] # get existing sub dict
            if ports not in portsDict:  # if new pair of (sPort, dPort)
                srcDstPortPairs.append(currentPortPair)
                sub = [packet]
                portsDict[ports] = sub
            else:
                portsDict[ports].extend(packet)

def displayFilteredOnPort():
    for ips, subDict in filteredOnPort.items():
        print(ips)
        for ports, pack in subDict.items():
            print(ports)
            for i in pack:
                print(i.summary())
            
# get average packet details from a list of packets
# number of packets and avg size of packet payload
# for both TCP and UDP
def getAvgPacketDetails(packets):
    tcpPacketCount = 0
    tcpPayloadLength = 0
    udpPacketCount = 0
    udpPayloadLength = 0
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
    packetsToCapture = 10
    packets = scapy.sniff(count = packetsToCapture)
    print(packets)  # gives an overview of packets captured
    print("===================================================")

    findDistinctHostIP(packets)
    print("===================================================")

    classifyPacketsWithIP(packets)
    # displayFilteredPackets()
    print("Details of packets about all sourceIP/destinationIP pairs")
    getSrcDstIpinfo()
    print("===================================================")

    classifyPacketsWithPort(packets)
    # displayFilteredOnPort()
    print("===================================================")
    print("Details of packets for sourceIP/destIP along with sourcePort/destPort")
    getSrcDstIpPortInfo()
    


if __name__ == "__main__":
    main()