# Sceduling in OPENMP

## What is scheduling?

Sceduling is a method in openmp to distribute iterations to different threads in a `for` loop.

basic form of scheduling:
```
#pragma omp parallel for schedule(scheduling-type) for(conditions){
    //do something
}
```

## Static Scheduling
- Syntax: `#pragma omp parallel for schedule(static,chunk-size)`

- if `chunk-size` is not specified, the defualt value is 1.

- `#pragma omp parallel for schedule(static,1)` is equivalent to `#pragma omp parallel for`

- if `chunk-size` is specified, the iterations will be divided into `iter_size/chunk-size`


## Dynamic Scheduling
- Syntax: `#pragma omp parallel for schedule(dynamic,chunk-size)`

- openmp will split the task into `iter_size/chunk-size` chunks, but distribute the chunks dynamically without any specific order.

## Guided Scheduling
- Syntax: `#pragma omp parallel for schedule(guided,chunk-size)`

- Chunk size is dynamic while using guided method, the size of a chunk is proportional to the number of unassigned iterations divided by the number of the threads, and the size will be decreased to chunk-size(but the last chunk could be smaller than chunk-size)

