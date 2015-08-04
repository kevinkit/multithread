#ifndef THREAD_FUNCS_H
#define THREAD_FUNCS_H


/* thread function */
void *simple_add(void *arg) {
    two_int_in_one_out *data = (two_int_in_one_out *)arg;


    printf("hello from thr_func, thread id: %d\n", data->tid);
    printf("\nSIZE = %d\n", data->size);


    int pos = data->size*data->tid;
    int i = 0;

    for(i = 0; i < data->size; i++)
    {
            data->out_mem[i] = data->in_mem1[i] + data->in_mem2[i];
            printf("POS[%i] = %d + %d = %d\n", i , data->in_mem1[i], data->in_mem2[i], data->out_mem[i]);
    }
    pthread_exit(NULL);
}


/* thread function */
void *simple_sub(void *arg) {
    two_int_in_one_out *data = (two_int_in_one_out *)arg;


    printf("hello from thr_func, thread id: %d\n", data->tid);
    printf("\nSIZE = %d\n", data->size);


    int pos = data->size*data->tid;
    int i = 0;

    for(i = 0; i < data->size; i++)
    {
            data->out_mem[i] = data->in_mem1[i] - data->in_mem2[i];
            printf("POS[%i] = %d + %d = %d\n", i , data->in_mem1[i], data->in_mem2[i], data->out_mem[i]);
    }
    pthread_exit(NULL);
}





/* thread function */
void *simple_mul(void *arg) {
    two_int_in_one_out *data = (two_int_in_one_out *)arg;


    printf("hello from thr_func, thread id: %d\n", data->tid);
    printf("\nSIZE = %d\n", data->size);


    int pos = data->size*data->tid;
    int i = 0;

    for(i = 0; i < data->size; i++)
    {
            data->out_mem[i] = data->in_mem1[i] * data->in_mem2[i];
            printf("POS[%i] = %d + %d = %d\n", i , data->in_mem1[i], data->in_mem2[i], data->out_mem[i]);
    }
    pthread_exit(NULL);
}











#endif
