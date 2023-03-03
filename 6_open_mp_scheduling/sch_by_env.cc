#include <stdio.h>
#include <omp.h>

int main()
{
    // Using schedule(runtime) uses the OMP_SCHEDULE environment vairable.
    #pragma omp parallel for schedule(runtime)
    for (int i = 0; i < 20; i++){
            printf("Thread %d is running number %d\n", omp_get_thread_num(), i);
    }
    return 0;
}