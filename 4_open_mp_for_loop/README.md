# OpenMp for loop

Run a openMP for loop

## Whats New?

### Parallel For
```
#pragma omp parallel
    {
        #pragma omp for
        for (int i = 0; i < 20; i++) {
            // std::cout << "Thread " << omp_get_thread_num() << " is processing iteration " << i << std::endl;
            printf("Thread %d is processing iteration %d\n", omp_get_thread_num(), i);
        }
    }
```

This will break down loop and distribute a set of iterations to each thread to execute.

### cout vs printf

Refer: https://stackoverflow.com/questions/4459888/openmp-c-and-c-cout-printf-does-not-give-the-same-output


Many implementations of printf acquire a lock to ensure that each printf call is not interrupted by other threads.

In contrast, `std::cout`'s overloaded `<<` operator means that (even with a lock) one thread's printing of `i` and `' '` and `'\n'` can be interleaved with another thread's output, because `std::cout<<i<<" "<<endl;` is translated to three operator `<<()` function calls by the `C++` compiler.

