#ifndef FIFO_H_INCLUDED
#define FIFO_H_INCLUDED



typedef struct fifo{
    int* buff;
    int write_index;
    int read_index;
    size_t unread_count;
    unsigned int max_size;
}fifo_t;


fifo_t* fifo_create(int size);

int fifo_push(fifo_t* fifo, int val);

int fifo_pop(fifo_t* fifo, int* val);


#endif // FIFO_H_INCLUDED
