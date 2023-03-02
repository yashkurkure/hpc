#include <omp.h>
#include <stdio.h>

int main() 
{
    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 0; i < 20; i++) {
            printf("Thread %d is processing iteration %d\n", omp_get_thread_num(), i);
        }
    }
    return 0;
}
