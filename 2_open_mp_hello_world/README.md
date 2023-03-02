# Parallelized hello world

A simple hello world program that is parallelized using OpenMP

## Whats new?

The pragma directive.
```
#pragma omp parallel
{
    printf("Hello World\n");
}
```
Once you surround the peice of code you want to parallelize, OpenMP will run this on `$OMP_NUM_THREADS` number of threads.
The environment variable `$OMP_NUM_THREADS` can be set in the PBS script.
```
# look in hello_world.pbs
export OMP_NUM_THREADS=4
```
Check `Makefile` for directions to compile `.cc` files that include `omp.h`.