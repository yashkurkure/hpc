#include <iostream>
#include <omp.h> // include OpenMP header

int main() {
  int num_threads = 0;

  #pragma omp parallel // start of parallel region
  {
    int thread_id = omp_get_thread_num(); // get the thread ID
    #pragma omp critical // start of critical section
    {
      std::cout << "Hello, World! (thread " << thread_id << ")" << std::endl;
    } // end of critical section
    #pragma omp single // start of single construct
    {
      num_threads = omp_get_num_threads(); // get the number of threads
    } // end of single construct
  } // end of parallel region

  std::cout << "There were " << num_threads << " threads." << std::endl;

  return 0;
}
