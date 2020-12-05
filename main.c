#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fifo.h"

fifo_t* fifo_1, *fifo_2;

int main()
{
    int val;
    //creating fifo 1 for uart rx data collection...
    fifo_1 = fifo_create(100);

    //creating another fifo for different purpose, say adc isr to fifo
    fifo_2 = fifo_create(100);

    for(int i = 0; i < 10; i++)
        fifo_push(fifo_1, i);

    for(int i = 0; i < 10; i++)
        fifo_push(fifo_2, i*10);


    while(fifo_pop(fifo_1, &val) == 0) {
        printf("%d\n", val);
    }
    while(fifo_pop(fifo_2, &val) == 0) {
        printf("%d\n", val);
    }


    return 0;
}


