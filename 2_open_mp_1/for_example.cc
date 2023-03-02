#include <omp.h>
#include <iostream>

int main() 
{
    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 0; i < 20; i++) {
            std::cout << "Thread " << omp_get_thread_num() << " is processing iteration " << i << std::endl;
        }
    }
    return 0;
}
