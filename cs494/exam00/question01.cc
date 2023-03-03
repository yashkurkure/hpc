#include <fstream>
#include <iostream>
#include <omp.h>
#include <stdio.h>

#define N 100

// thread_id which thread is writing the data
// data the data to write
// n the number of elements in data
// filename the name of the file to write to
void write_data(int thread_id, int *data, int n, std::string filename)
{
    std::ofstream outfile;
    outfile.open(filename);
    outfile << "Thread ID: " << thread_id << std::endl;
    outfile << "Data: ";
    for (int i = 0; i < n; ++i)
    {
        outfile << data[i] << " ";
    }
    outfile << std::endl;
    outfile.close();
}

int main()
{
    // Comment out if env variable is set
    omp_set_num_threads(2);

    int A[N];
    for (int i = 0; i < N; ++i)
    {
        A[i] = i;
    }

    int sum1 = 0, sum2 = 0;

    // Answer to question01.
    #pragma omp parallel sections
    {
        // Section 0
        // Process 1st half of the array.
        #pragma omp section
        {
            int lo = 0;
            int hi = N/2;
            for(int i = lo; i < hi; i++){
                sum1 += A[i];
            }

            // Print to identify the thread executing this section
            printf("Thread with id %d executed Section 0\n", omp_get_thread_num());

            // Write the status of thread to file.
            write_data(omp_get_thread_num(), A, hi - lo, "question01_file0.txt");
        }

        // Section 1
        // Process 2nd half of the array.
        #pragma omp section
        {
            int lo = N/2;
            int hi = N;
            for(int i = lo; i < hi; i++){
                sum2 += A[i];
            }

            // Print to identify the thread executing this section
            printf("Thread with id %d executed Section 1\n", omp_get_thread_num());
            
            // Write the status of thread to file.
            write_data(omp_get_thread_num(), A + lo, hi - lo, "question01_file1.txt");
        }
    }

    int total_sum = sum1 + sum2;
    std::cout << "Total sum: " << total_sum << std::endl;

    // For testing: N=100, answer = 4950
    // int total_sum_no_parallel = 0;
    // for(int i = 0; i < N; i++){
    //     total_sum_no_parallel+=A[i];
    // }
    // std::cout << "Total sum (no parallel): " << total_sum_no_parallel << std::endl;

    return 0;
}
