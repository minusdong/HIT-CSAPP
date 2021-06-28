/*
 9.11题：
 A. 00001001111100
 B.
    |  Parameter    |   Value  |
    |---------------|----------|
    |     VPN       |   0x09   |
    |   TLB index   |    0x1   |
    |    TLB tag    |   0x02   |
    |    TLB hit?   |    否    |
    |  Page fault?  |    否    |
    |      PPN      |   0x17   |
 C. 010111111100
 D.
    | Parameter     |  Value  |
    |---------------|---------|
    |  字节偏移      |   0x0   |
    |  缓存索引      |   0xF   |
    |  缓存标记      |   0x17  |
    |  缓存命中      |    否   |
    | 返回的缓存字节  |    -    |
 */


/*
 9.13题：
 A. 00000001000000
 B. 
    |  Parameter    |   Value  |
    |---------------|----------|
    |     VPN       |   0x01   |
    |   TLB index   |    0x1   |
    |    TLB tag    |   0x00   |
    |    TLB hit?   |    否    |
    |  Page fault?  |    是    |
    |      PPN      |     -    |
 C/D. Page Fault
 */


/*
 9.15题：
    |  Request   | Block size | Block header |
    |------------|------------|--------------|
    | malloc(3)  |     8      |     0x9      |
    | malloc(11) |     16     |     0x11     |
    | malloc(20) |     24     |     0x19     |
    | malloc(21) |     32     |     0x21     |
 */


/*
 9.19题：
 (1) a
 (2) d
 (3) b
 */