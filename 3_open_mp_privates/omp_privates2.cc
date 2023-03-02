#include <stdio.h>
#include <omp.h>

int main() {

int num_threads = -1, thread_id = -3;

#pragma omp parallel private(num_threads, thread_id)
{
    thread_id = omp_get_thread_num();
    printf("Hello World. This thread is %d\n", thread_id);
    if(thread_id == 0){
        num_threads = omp_get_num_threads();
        printf("Total # of threads is: %d\n", num_threads);
    }
}
    printf("***OUTSIDE PARALLEL BLOCK***\n");
    printf("num_threads = %d\n", num_threads);
    printf("thread_id = %d\n", thread_id);
    return 0;
}