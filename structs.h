#ifndef STRUCTS_H
#define STRUCTS_H


//struct for two integer arrays as input , and one as output
typedef struct _two_int_in_one_out {
    int tid;
    int size;
    int size_rest;
    
    int thread_amount;
    int global_size;
    int wanted_size;

    int *in_mem1;
    int *in_mem2;
    int *out_mem;
} two_int_in_one_out;

















#endif
