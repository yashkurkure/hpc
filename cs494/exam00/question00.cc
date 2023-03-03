#include <fstream>
#include <iostream>
#include <omp.h>

#define N 97

int main()
{
    int A[N], B[N], C[N], sum = 0;
    for (int i = 0; i < N; ++i)
    {
        A[i] = i;
        B[i] = N - i;
    }

    // Answer to question00
    #pragma omp parallel shared(sum)
    {


        // First we accumulate the sums at each index in C
        #pragma omp for
        for(int i = 0; i < N; i++){
            C[i] = A[i] + B[i];
        }

        // We wait for all the thread to be done filling C
        #pragma omp barrier

        // Then we add up all the elements in C to get the sum
        // Doing this on a single thread as 'sum' is shared
        #pragma omp single
        {
            for(int i = 0; i < N; i++){
                sum += C[i];
            }
        }
    }

    std::cout << "Sum: " << sum << std::endl;

    // Just for testing
    // int sum_no_parallel = 0;
    // for(int i = 0; i < N; i++){
    //     sum_no_parallel += A[i] + B[i]; 
    // }

    // std::cout << "Sum No Parallel: " << sum_no_parallel << std::endl;

    return 0;
}
