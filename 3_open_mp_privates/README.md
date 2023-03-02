# Parallelized hello world with Privates

A simple hello world program that is parallelized using OpenMP

## Whats new?

### Adding private vairables to each thread

Declare variables that you want to be private, i.e, each thread will have its own copy.
```
int num_threads, thread_id;
```

Then add the private() clause to the pragma directive, while mentioning the vairables that will be private.
```
#pragma omp parallel private(num_threads, thread_id)
{
    thread_id = omp_get_thread_num();
    printf("Hello World. This thread is %d\n", thread_id);
    if(thread_id == 0){
        num_threads = omp_get_num_threads();
        printf("Total # of threads is: %d\n", num_threads);
    }
}
```

### Local variables are default private
https://stackoverflow.com/questions/6358375/openmp-are-local-variables-automatically-private
```
#pragma omp parallel
{
    int x; // private to each
}
```

### What is the value of these varibles after execution of the code in the directive?
Run
```
make omp_privates2
qsub omp_privates.pbs
cat *.o*
```
The value of the vairables after the execution of the parallel block will be the same as what it was at the point initially.

## Can the intial values of the vairables be access in the directive?
Yes by using firstprivate() instead of private(). See omp_privates3.cc.
```
make omp_privates3
qsub omp_privates.pbs
cat *.o*
```

The intial value inside the private block is not carried over from the outside.

## Links
https://stackoverflow.com/questions/15468367/openmp-performance-impact-private-directive-vs-declaring-variable-inside-for-c
