#include <stdint.h>

#define rd  (reg[(i & 0b00000000000000000000111110000000) >> 7 ])
#define rs1 (reg[(i & 0b00000000000011111000000000000000) >> 15])
#define rs2 (reg[(i & 0b00000001111100000000000000000000) >> 20])

#define func3 ((i & 0b00000000000000000111000000000000) >> 12)
#define func7 ((i & 0b11111110000000000000000000000000) >> 25)


#define imm_i (((i & 0b01111111111100000000000000000000) >> 20)\
            | (( i >> 31) * 0b11111111111100000000000000000000))
#define imm_s (((i & 0b01111110000000000000000000000000) >> 25)\
            | (( i & 0b00000000000000000000111110000000) >> 7 )\
            | (( i >> 31) * 0b11111111111111111111000000000000))
#define imm_b (((i & 0b00000000000000000000000010000000) << 4 )\
            | (( i & 0b01111110000000000000000000000000) >> 20)\
            | (( i & 0b00000000000000000000111100000000) >> 7 )\
            | (( i >> 31) * 0b11111111111111111110000000000000))
#define imm_u (  i & 0b11111111111111111111000000000000)
#define imm_j (( i & 0b00000000000011111111000000000000)\
            | (( i & 0b00000000000100000000000000000000) >> 9 )\
            | (( i & 0b01111111111000000000000000000000) >> 20)\
            | (( i >> 31) * 0b11111111111100000000000000000000))

#define shamt_i ((i & (0b00000001111100000000000000000000) >> 20) // same as rs2 but intent has meaning.

#define csr (((i & 0b01111111111100000000000000000000) >> 20)\
          | (( i >> 31) * 0b11111111111100000000000000000000))
#define zimm ((i & (0b00000000000011111000000000000000) >> 15)
