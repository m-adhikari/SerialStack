# SerialStack Protocol Specification

## Overview
SerialStack is a lightweight packet oriented protocol desined for UART based communication. The protocol provides: packet framing, addressing, sequencing, command identification, protocol versioning, and error detection.

This protocol operates above UART physical layer and is independent of hardware, OS and application. 

## Packet format 
+------+------+------+------+------+------+------+----------------+------+------+
| SOF  | LEN  | VER  | DST  | SRC  | CMD  | SEQ  | Payload (64 B) | CRC8 | EOF  |
+------+------+------+------+------+------+------+----------------+------+------+

| Field | Size (Bytes) | Offset | Description |
|:------|-------------:|-------:|:------------|
| SOF | 1 | 0 | Start-of-frame delimiter (`0xAA`) |
| LEN | 1 | 1 | Number of valid payload bytes (`0–64`) |
| VER | 1 | 2 | Protocol version identifier |
| DST | 1 | 3 | Destination node address |
| SRC | 1 | 4 | Source node address |
| CMD | 1 | 5 | Command or service identifier |
| SEQ | 1 | 6 | Packet sequence number |
| Payload | 64 | 7–70 | Application-defined data |
| CRC8 | 1 | 71 | CRC-8 integrity checksum |
| EOF | 1 | 72 | End-of-frame delimiter (`0x55`) |
| **Total** | **73** | | Complete SerialStack frame size |

## Field Definition

**SOF:** Marks the beginning of every SerialStack frame.

**LEN:** Indicates the number of valid bytes within payload. Value range: 0x00 to 0x40 (0-64)
Unused payload bytes is ignored by the receiver.

**VER:** Protocol version implemented by the transmitting node.

**DST:** Specifies the destination node address.

**SRC:** Specifies the transmitting node address.

**CMD:** Protocol service or application command associated with the payload.

**SEQ:** Uniquely identifies packet. Supports acknowledgement, retransmission, duplicate detection, and diagnostics.

**Payload:** Contains application-defined data.

**CRC8:** Provides packet integrity verification. Calclated over entire packet excluding SOF, CRC8 and EOF

**EOF:** Marks the end of SerialStack frame.

## Design Characteristics

- Fixed frame size (73 bytes)
- Fixed payload allocation (64 bytes)
- Variable valid payload length using LEN
- Point-to-point and multi-node communication support
- Protocol versioning
- Node addressing
- Sequence-based packet tracking
- CRC-8 error detection
- Application-independent payload transport

## Protocol Requirements

- Verify SOF and EOF delimiters
- Reject packets with invalid CRC values
- Ignore payload bytes beyond LEN.
- process version supported packets.
- Validate destination address before forwarding data to application layer.

 




