#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fifo.h"


fifo_t* fifo_create(int size)
{
    fifo_t* temp = NULL;
    temp = malloc(sizeof(fifo_t));
    temp->read_index = 0;
    temp->write_index = 0;
    temp->unread_count = 0;
    temp->buff = malloc(sizeof(int) * size);
    temp->max_size = size;
    return temp;
}

int fifo_push(fifo_t* fifo, int val)
{
    if(fifo->unread_count >= fifo->max_size)
        return -1;
    fifo->buff[fifo->write_index] = val;
    (fifo->unread_count)++;
    (fifo->write_index)++;
    if(fifo->write_index >= fifo->max_size)
        fifo->write_index = 0;

    return 0;
}

int fifo_pop(fifo_t* fifo,   int* val)
{
    if(fifo->unread_count == 0)
        return -1;
    *val = fifo->buff[(fifo->read_index)];
    (fifo->read_index)++;

    if(fifo->read_index >= fifo->max_size)
        fifo->read_index = 0;

    (fifo->unread_count)--;
//    if(fifo->read_index >= fifo->max_size)

    return 0;
}


