# MAC_protocols
This is an implementation of MAC Layer Protocols (Pure and Slotted Aloha, CSMA/CA, CSMA/CD)

### What is MAC Layer Protocols
The Media Access Control (MAC) data communication Networks protocol sub-layer, also known as the Medium Access Control, is a sub-layer of the data link layer specified in the seven-layer OSI model. The medium access layer was made necessary by systems that share a common communications medium. Typically these are local area networks. The MAC layer is the "low" part of the second OSI layer, the layer of the "data link". In fact, the IEEE divided this layer into two layers "above" is the control layer the logical connection (Logical Link Control, LLC) and "down" the control layer The medium access (MAC).

The LLC layer is standardized by the IEEE as the 802.2 since the beginning 1980 Its purpose is to allow level 3 network protocols (for eg IP) to be based on a single layer (the LLC layer) regardless underlying protocol used, including WiFi, Ethernet or Token Ring, for example. All WiFi data packets so carry a pack LLC, which contains itself packets from the upper network layers. The header of a packet LLC indicates the type of layer 3 protocol in it: most of the time, it is IP protocol, but it could be another protocol, such as IPX (Internet Packet Exchange) for example. Thanks to the LLC layer, it is possible to have at the same time, on the same network, multiple Layer 3 protocols.

In LAN nodes uses the same communication channel for transmission. The MAC sub-layer has two primary responsibilities:

Data encapsulation, including frame assembly before transmission, and frame parsing/error detection during and after reception. Media access control, including initiation of frame transmission and recovery from transmission failure. 
![alt text](https://github.com/zerospook/MAC_protocols/blob/master/images/Network-layers.jpg "Network Layers")

### Following Protocols are used by Medium Access Layer :

## ALOHA : 
ALOHA is a system for coordinating and arbitrating access to a shared communication channel. It is a random access protocol. It was developed in the 1970s at the University of Hawaii. The original system used terrestrial radio broadcasting, but the system has been implemented in satellite communication systems. A shared communication system like ALOHA requires a method of handling collisions that occur when two or more systems attempt to transmit on the channel at the same time. 

In the ALOHA system, a node transmits whenever data is available to send. If another node transmits at the same time, a collision occurs, and the frames that were transmitted are lost. However, a node can listen to broadcasts on the medium, even its own, and determine whether the frames were transmitted.
_Types Of ALOHA_:
* Pure ALOHA - It allows station to transmit data whenever they have data to be sent. It waits for an acknowledgement until the receiver receives the data. If the acknowledgement doesn't come in the alloted time, then it waits for a random amount of time(_back-off-time_) before resending the data. It's throughput is maximized when frames are of uniform length.
![alt text](https://github.com/zerospook/MAC_protocols/blob/master/images/pureAloha.jpg "Collision in Pure ALOHA")
![alt text](https://github.com/zerospook/MAC_protocols/blob/master/images/pureALOHA1.jpg "How packets collide in Pure ALOHA")
_the time and medium are common for all the stations_

* Slotted ALOHA - It was developed to increase the efficiency of Pure ALOHA, as the chances in Pure ALOHA are high. The time of the shared channel is divided into discrete time intervals called _slots_. Sending of data can happen only at the beginning of the time slot.If a station misses out the allowed time, it must wait for the next slot, this reduces collision.
![alt text](https://github.com/zerospook/MAC_protocols/blob/master/images/slottedALOHA1.jpg "Reduced collision in Slotted ALOHA")
![alt text](https://github.com/zerospook/MAC_protocols/blob/master/images/slottedAloha.jpg "How packets collide in Slotted ALOHA")
_the time and medium are common for all the stations_
![alt text](https://github.com/zerospook/MAC_protocols/blob/master/images/diff_PureSlotted.jpg "Difference between Pure and Slotted ALOHA")

## Carrier Sensed Multiple Access (CSMA) : 
CSMA is a network access method used on shared network topologies such as Ethernet to control access to the network. Devices attached to the network cable listen (carrier sense) before transmitting. If the channel is in use, devices wait before transmitting. MA (Multiple Access) indicates that many devices can connect to and share the same network. All devices have equal access to use the network when it is clear.

Even though devices attempt to sense whether the network is in use, there is a good chance that two stations will attempt to access it at the same time. On large networks, the transmission time between one end of the cable and another is enough that one station may access the cable even though another has already just accessed it. There are two methods for avoiding these so-called collisions, listed here :

## CSMA/CD (Carrier Sense Multiple Access/Collision Detection) : 
CD (collision detection) defines what happenswhen two devices sense a clear channel, then attempt totransmit at the same time. A collision occurs, and bothdevices stop transmission, wait for a random amount oftime, and then retransmit. This is the technique used to access the 802.3 Ethernet network channel.

This method handles collisions as they occur, but if the bus is constantly busy, collisions can occur so often that performance drops drastically. It is estimated that network traffic must be less than 40 percent of the bus capacity for the network to operate efficiently. If distances are long, time lags occur that may result in inappropriate carrier sensing, and hence collisions.

## CSMA/CA (Carrier Sense Multiple Access/Collision Avoidance) : 
In CA collision avoidance), collisions areavoided because each node signals its intent to transmitbefore actually doing so. This method is not popular becauseit requires excessive overhead that reduces performance. 

## How to use:
```
g++ mac_lp.cpp -o mac_lp
.\mac_lp.exe
```

## References:
* General Theory & Description - https://ecomputernotes.com
* Concept & Images - https://www.youtube.com/user/nesoacademy
