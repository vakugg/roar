#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <stdlib.h>
#include <windows.h>
#include "instructions.h"
#include "lfsr.h"

#define FIND_ASSEMBLER_FILE "C:\Users\Admin\Documents\rebuild_asm_test\find_assembler.s"

#define bits_quant 20
#define reg_quant 5 //число байт для calloc

extern void _get_call_adress(void);




    uint64_t sizze_to_quantity_returner(void)
    {
        uint64_t a =2;
        for(int i=0;i<bits_quant-1; i++)
        {
         a*=2;
        }
        return(a-1);
    }

void execute(void (*f)())
{
    f();
}




int main()
{

    // time vars
        clock_t strt_time, fin_time;     double rslt;
        //void* UP_range;



        void *moloko = calloc(sizze_to_quantity_returner(), reg_quant);
        if (moloko == NULL) exit(911);



        jmp_instr pemtraory;
        pemtraory.offset=0xe9;

        jmp_struct TeMp;
        TeMp.prev_index = (long long)&moloko[0]; //думай
        TeMp.index_adr_diff =0;



        //инициализируем lfsr
        fio_lfsr tEmP;
        lfsr_init(&tEmP,sizze_to_quantity_returner(),(unsigned long)moloko , 1); // нам потребуется внутри signed трижды long чтобы задействовать 64 бита - решай. пока до 32 бит
        uint64_t *numholder;


        //формируем инструкции и пихаем в память
        for(int i=0;i<sizze_to_quantity_returner() - 1; i++)
        {
            lfsr_next(&tEmP, numholder);
            //вычисляем разность между адресами
            TeMp.index_adr_diff = &moloko[*numholder] - TeMp.prev_index;
            pemtraory.offset=TeMp.index_adr_diff;

            moloko[*numholder]=pemtraory;

            TeMp.prev_index = numholder;


        }
        //последний - ret
        TeMp.index_adr_diff = &moloko[*numholder] - TeMp.prev_index;
        pemtraory.opcode= 0xc3;
        pemtraory.offset =0;
        moloko[*numholder]=pemtraory;





        strt_time = clock();// обходим адреса внутри

        execute(moloko);

        fin_time = clock();



        rslt = (double)((fin_time - strt_time) / CLOCKS_PER_SEC);




    return 0;
}
