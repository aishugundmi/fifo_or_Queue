#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fifo.h"

fifo_t* fifo_1, *fifo_2;

int main()
{
    int val;
    fifo_1 = fifo_create(100);
    fifo_2 = fifo_create(100);
    fifo_push(fifo_1, 123);
    fifo_push(fifo_2, 567);

    if(fifo_pop(fifo_1, &val) == 0) {
        printf("fifo_1 read = %d\n", val);
    }

    if(fifo_pop(fifo_2, &val) == 0) {
        printf("fifo_2 read = %d\n", val);
    }

    return 0;
}


