# SerialStack Command Registry

The CMD field defines the operation performed by a SerialStack packet.

| CMD | Name | Description | Status |
|:---:|:-----|:------------|:------:|
| `0x00` | RESERVED | Invalid command identifier | Reserved |
| `0x01` | PING | Node availability check | Core |
| `0x02` | PONG | Ping response message | Core |
| `0x03` | ACK | Successful packet acknowledgement | Core |
| `0x04` | NACK | Packet rejection notification | Core |
| `0x05` | HEARTBEAT | Periodic node alive signal | Core |
| `0x06` | STATUS_REQUEST | Request node status information | Core |
| `0x07` | STATUS_RESPONSE | Return node status information | Core |
| `0x08-0xFE` | RESERVED | Future command allocation | Reserved |
| `0xFF` | EXTENDED_COMMAND | Extended command mechanism | Reserved |
