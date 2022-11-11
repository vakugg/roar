#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <stdlib.h>
#include <windows.h>
#include "instructions.h"
#include "lfsr.h"
#include "sorteer.h"

#define FIND_ASSEMBLER_FILE "C:\Users\Admin\Documents\rebuild_asm_test\find_assembler.s"

#define bits_quant 20
#define reg_quant 9 //число байт для calloc

extern void _get_call_adress(void);




    uint64_t sizze_to_quantity_returner(int user_put)
    {
        uint64_t a =1;
        for(int i=0;i<user_put; i++)
        {
         a*=2;
        }
        return(a-1);
    }




    uint64_t compare(const void * x1, const void * x2)   // функция сравнения элементов массива
    {
      return ( *(uint64_t*)x1 - *(uint64_t*)x2 );              // если результат вычитания равен 0, то числа равны, < 0: x1 < x2; > 0: x1 > x2
    }


    boolean accuracy_lfsr_check(void)
    {
        void* test_arr =calloc(1024*1024-1, (size_t)reg_quant);
        if(test_arr == NULL)
        {
            exit(512);
        }


        uint64_t* rands_arr =calloc(1024*1024-1, sizeof(uint64_t));
        if(rands_arr == NULL)
        {
            exit(513);
        }

        fio_lfsr test;
        lfsr_init(&test,1024*1024-1, 218,0);
        uint64_t leo;

        for(uint64_t i =0; i<1024*1024-1; i++)
        {
            rands_arr[i]=test.last_val;
            lfsr_next(&test,&leo);
        }



        qsort(rands_arr,1024*1024-1,sizeof(uint64_t),compare);


        for(uint64_t i =1; i<1024*1024-1; i++)
        {
            if(rands_arr[i-1] != rands_arr[i]-1)
            {
                free(test_arr);
                free(rands_arr);
                return(FALSE);
            }
            printf("%lld\n",rands_arr[i]);
        }

        free(test_arr);
        free(rands_arr);
        return(TRUE);


    }


    boolean accuracy_instructions_check()
    {
        void* test_arr =calloc(1024-1, (size_t)reg_quant);
        if(test_arr == NULL)
        {
            exit(612);
        }

        uint64_t* rands_arr =calloc(1024-1, sizeof(uint64_t));
        if(rands_arr == NULL)
        {
            exit(613);
        }


        jmp_instr *kefir = test_arr;

        jmp_struct testTEMP;
        testTEMP.prev_index=0;
        testTEMP.index_adr_diff=0;

        fio_lfsr testNAME_SURNAME;
        lfsr_init(&testNAME_SURNAME,1024-1, (unsigned long) test_arr,0);



        kefir[0].opcode=0xe9;
        kefir[0].offset = testNAME_SURNAME.last_val;

        testTEMP.prev_index = testNAME_SURNAME.last_val;
        rands_arr[0]= testNAME_SURNAME.last_val;

        uint64_t chislo_derzshatyel;

        uint64_t weee =1;
        do
        {

            lfsr_next(&testNAME_SURNAME, &chislo_derzshatyel);

            rands_arr[weee] = chislo_derzshatyel;

            testTEMP.index_adr_diff = &kefir[chislo_derzshatyel] - &kefir[testTEMP.prev_index];
            kefir[chislo_derzshatyel].opcode= 0xe9;
            kefir[chislo_derzshatyel].offset = testTEMP.index_adr_diff;

            testTEMP.prev_index = chislo_derzshatyel;

            weee++;
        }while(weee < 1024-1);


        // цель -
//        for(uint64_t i=0; i<1024-2; i++)
//        {
//            uint64_t base= rands_arr[i+1];
//            uint64_t step= rands_arr[i];
//            uint64_t dif = step-base;
//            int64_t omg = kefir[i].offset;
//            if(dif !=  omg)
//            {
//                free(test_arr);
//                free(rands_arr);
//                return(TRUE);
///            }
//        }

        if(kefir[1023].opcode!= 0xC3)
        {
            free(test_arr);
            free(rands_arr);
            return(TRUE);
        }

        free(test_arr);
        free(rands_arr);
        return(FALSE);

    }





void execute(void (*f)(void))
{
    f();
}





boolean execute_check()
{
    void* test_arr =calloc(3, 9);
    if(test_arr == NULL)
    {
        exit(712);
    }

    jmp_instr *kefir = test_arr;


    kefir[0].opcode=0xE9;
    kefir[0].offset = (&kefir[2]-&kefir[0]);
    kefir[2].opcode=0xE9;
    kefir[2].offset = (&kefir[1]-&kefir[2]);
    kefir[1].opcode=0xC3;
    kefir[1].offset=0X00;

    execute(kefir);

   return(0);
}




int main(int argc, char* argv[])
{
    int chooser;
    if(atoi(argv[1])<3 || atoi(argv[1])>32 )
    {
        //exit(23);
        chooser =3;// я не нашёл как вызывать консоль в кутэ
    }
    else
    {
        chooser =atoi(argv[1]);
    }

    // time vars
        clock_t strt_time, fin_time;     double rslt;
        uint64_t quant_holder = sizze_to_quantity_returner(chooser);

        int v = 3;
        printf("Code is at %p \n", (void *)main);
        printf("Stack is at %p \n", (void *)&v);
        printf("Heap is at %p \n", malloc(9));

        void *moloko = calloc(quant_holder+1, 9);
        if (moloko == NULL) exit(911);

        jmp_instr* jmp_arr =moloko;



        jmp_struct TeMp;
        TeMp.prev_index = 0;
        TeMp.index_adr_diff =0;


       // boolean LFSRcheck = accuracy_lfsr_check();

       // boolean INSTRcheck = accuracy_instructions_check();

       // boolean EXcheck = execute_check();


        //инициализируем lfsr
        fio_lfsr tEmP;
        lfsr_init(&tEmP,quant_holder,(unsigned long)moloko , 0);// от 3 до 32 бит

        uint64_t numholder;



        //формируем инструкции и пихаем в память

        uint64_t eee =0;

        jmp_arr[0].opcode =0xE9;
        jmp_arr[0].offset = &jmp_arr[tEmP.last_val] - &jmp_arr[0];
        TeMp.prev_index = tEmP.last_val;

        eee++;
        do
        {
            lfsr_next(&tEmP, &numholder);
            //вычисляем разность между адресами

            TeMp.index_adr_diff = &jmp_arr[numholder] - &jmp_arr[TeMp.prev_index];
            jmp_arr[TeMp.prev_index].opcode=0xE9;
            jmp_arr[TeMp.prev_index].offset =TeMp.index_adr_diff;


            TeMp.prev_index =numholder;

            eee++;
        } while(eee < quant_holder);
        //последний - ret
        lfsr_next(&tEmP, &numholder);
        TeMp.index_adr_diff = &jmp_arr[numholder] - &jmp_arr[TeMp.prev_index];
        jmp_arr[TeMp.prev_index].opcode=0xc3;
        jmp_arr[TeMp.prev_index].offset=0x00;






        strt_time = clock();// обходим адреса внутри

        execute(moloko);

        fin_time = clock();

        rslt = (double)((fin_time - strt_time) / CLOCKS_PER_SEC);

        printf("time is%lf",rslt);




    return 0;
}
