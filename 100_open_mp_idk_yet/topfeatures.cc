#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <omp.h>

int main() {
    // Set number of threads using environment variable
    omp_set_dynamic(0);
    omp_set_num_threads(4);

    // Get number of threads
    int num_threads = omp_get_num_threads();
    std::cout << "Number of threads: " << num_threads << std::endl;

    // Get thread ID
    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        #pragma omp critical
        {
            std::cout << "Thread ID: " << tid << std::endl;
        }
    }

    // Set dynamic thread adjustment
    omp_set_dynamic(1);
    std::cout << "Dynamic thread adjustment: " << omp_get_dynamic() << std::endl;

    // Enable nested parallelism
    omp_set_nested(1);
    std::cout << "Nested parallelism: " << omp_get_nested() << std::endl;

    // Timers
    double start_time = omp_get_wtime();
    #pragma omp parallel
    {
        int sleep_time = rand()%6;
        std::cout << "Thread ID: " << omp_get_thread_num() << " is about to sleep for " << sleep_time << std::endl;
        sleep(sleep_time);
    }
    double end_time = omp_get_wtime();
    std::cout << "Elapsed time: " << end_time - start_time << " seconds" << std::endl;

    // API for locking
    omp_lock_t lock;
    omp_init_lock(&lock);

    #pragma omp parallel
    {
        // Code that needs to be protected by a lock
        omp_set_lock(&lock);
        std::cout << "Thread ID: " << omp_get_thread_num() << " is inside the lock" << std::endl;
        omp_unset_lock(&lock);
    }

    omp_destroy_lock(&lock);

    // Barrier
    #pragma omp parallel num_threads(4)
    {
        sleep(rand()%6);
        #pragma omp barrier
        std::cout << "Thread " << omp_get_thread_num() << " finished work" << std::endl;
    }

    // Reduction
    int sum = 0;
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < 10; i++) {
        sum += i;
    }
    std::cout << "Reduction: " << sum << std::endl;

    // Schedule
    #pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < 10; i++) {
        std::cout << "Thread " << omp_get_thread_num() << " is processing iteration " << i << std::endl;
    }

    return 0;
}
