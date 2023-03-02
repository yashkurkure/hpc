# Open MP Critical and Single Construct

## Critical Directive


The pragma critical privideds mutual exclusion for access to shared variables by multiple thread. The ciritical directive delinieates a block of code that only one thread is permitted to execute at a time.
```
 #pragma omp parallel
  {
    int thread_id = omp_get_thread_num();
    #pragma omp critical
    {
      std::cout << "Hello, World! (thread " << thread_id << ")" << std::endl;
    }
  } 
```

##  Single Directive
The delineated code block will be executed by only on thread. It can be any one thread out of all the running threads.
Additinally, all threads will be blocked from going past the end og the single pragma block until after all of them have reached that point in their execution.

```
  int num_threads = 0;
  #pragma omp parallel
  {
    #pragma omp single
    {
      num_threads = omp_get_num_threads();
    }
  }
```