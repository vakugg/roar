#include"sorteer.h"

void qsortRecursive(uint64_t *mas, uint64_t size)
{

    uint64_t i = 0;
    uint64_t j = size - 1;
    uint64_t mid = mas[size / 2];


    do {

        while(mas[i] < mid)
        {
            i++;
        }

        while(mas[j] > mid)
        {
            j--;
        }


        if (i <= j)
        {
            uint64_t tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);



    if(j > 0)
    {

        qsortRecursive(mas, j + 1);
    }
    if (i < size)
    {

        qsortRecursive(&mas[i], size - i);
    }
}
