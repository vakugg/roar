#include <stdio.h>

;
#pragma pack(push, 1)
typedef struct jmp_struct
{
    long long index_adr_diff;
    unsigned long long *prev_index;
}jmp_struct;

typedef struct jmp_instr
{
    unsigned char opcode; //0xe9
    long long offset;
}jmp_instr;
#pragma pack(pop)



