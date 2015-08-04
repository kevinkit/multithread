#ifndef INIT_FUNCS_H
#define INIT_FUNCS_H



int addi(int* in_mem1,int* in_mem2, int* out_mem, int size)
{
    int cores;
    int workload;    

    int i = 0;
    int rc;
    cores = get_cores();

    pthread_t thr[cores];
    two_int_in_one_out thr_data[cores];


    if(size % cores == 0){       
        workload = size/cores;
        printf("\n WORKLOAD = %d\n", workload);

        for(; i < cores;i++){
            thr_data[i].tid = i;
            thr_data[i].size = workload;
            thr_data[i].in_mem1 = in_mem1 + i*workload;
            thr_data[i].in_mem2 = in_mem2 + i*workload;
            thr_data[i].out_mem = out_mem + i*workload;
            if ((rc = pthread_create(&thr[i], NULL, simple_add, &thr_data[i]))) {
                fprintf(stderr, "error: pthread_create, rc: %d\n", rc);
                return EXIT_FAILURE;
            }
        }
    }
    else
    {
        //Try sth fitting
        for(;i < 32;i++)
        {
            if(size % (cores << i) == 0)
            {
                workload = size/(cores << i);
                //..to be continued
            }
        }
    }
    /* block until all threads complete */
    for (i = 0; i < cores; ++i) {
        pthread_join(thr[i], NULL);
    }
}



int subi(int* in_mem1,int* in_mem2, int* out_mem, int size)
{
    int cores;
    int workload;

    int i = 0;
    int rc;
    cores = get_cores();

    pthread_t thr[cores];
    two_int_in_one_out thr_data[cores];


    if(size % cores == 0){
        workload = size/cores;
        for(; i < cores;i++){
            thr_data[i].tid = i;
            thr_data[i].size = workload;
            thr_data[i].in_mem1 = in_mem1 + i*workload;
            thr_data[i].in_mem2 = in_mem2 + i*workload;
            thr_data[i].out_mem = out_mem + i*workload;
            if ((rc = pthread_create(&thr[i], NULL, simple_sub, &thr_data[i]))) {
                fprintf(stderr, "error: pthread_create, rc: %d\n", rc);
                return EXIT_FAILURE;
            }
        }
    }
    else
    {
        //Try sth fitting
        for(;i < 32;i++)
        {
            if(size % (cores << i) == 0)
            {
                workload = size/(cores << i);
                //..to be continued
            }
        }
    }
    /* block until all threads complete */
    for (i = 0; i < cores; ++i) {
        pthread_join(thr[i], NULL);
    }
}


int muli(int* in_mem1,int* in_mem2, int* out_mem, int size)
{
    int cores;
    int workload;

    int i = 0;
    int rc;
    cores = get_cores();

    pthread_t thr[cores];
    two_int_in_one_out thr_data[cores];


    if(size % cores == 0){
        workload = size/cores;
        for(; i < cores;i++){
            thr_data[i].tid = i;
            thr_data[i].size = workload;
            thr_data[i].in_mem1 = in_mem1 + i*workload;
            thr_data[i].in_mem2 = in_mem2 + i*workload;
            thr_data[i].out_mem = out_mem + i*workload;
            if ((rc = pthread_create(&thr[i], NULL, simple_mul, &thr_data[i]))) {
                fprintf(stderr, "error: pthread_create, rc: %d\n", rc);
                return EXIT_FAILURE;
            }
        }
    }
    else
    {
        //Try sth fitting
        for(;i < 32;i++)
        {
            if(size % (cores << i) == 0)
            {
                workload = size/(cores << i);
                //..to be continued
            }
        }
    }
    /* block until all threads complete */
    for (i = 0; i < cores; ++i) {
        pthread_join(thr[i], NULL);
    }
}






#endif 
