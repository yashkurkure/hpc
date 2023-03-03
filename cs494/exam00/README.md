## CS494 Introduction to High Performance Computing Exam00

You will complete this exam in two parts within 75 minutes.

### Part One (50 Points) Microsoft Forms

Using the standard Microsoft Forms that we have used for all the quizzes in the class. 

You can find the Microsoft Forms portion of the exam at URL: [https://forms.office.com/r/BmK6nyhyeX](https://forms.office.com/r/BmK6nyhyeX)

### Part Two (100 Points) OpenMP Programming
There are two starter codes (*question00.cc*, *question01.cc*) and a *Makefile* provided, do not modify the *Makefile* or change the names of the source files. You may edit the contents of the source code files as needed to complete the exam. Each program will be run with `export OMP_NUM_THREADS=2`. 

0. (50 points)[question00.cc] Write a parallel program in C++ using OpenMP that computes the sum of two arrays `A` and `B` of size `N` and stores the result in an array `C`. Assume that all arrays are initialized and of the same size. Your program should use the `#pragma omp parallel for` directive to parallelize the loop that performs the addition.

	Your program **should not use the reduction clause** to compute the sum of the elements in array `C`. Instead, you should declare and initialize a variable `sum` outside the parallel region and use an **atomic operation** to accumulate the sum of the elements computed by each thread.

1. (50 points)[question01.cc] Write a C++ program that uses OpenMP to parallelize the computation of the sum of an array of 100 integers. Your program should use two **sections**, with each section adding up half of the elements in the array. Within each section, each thread should output a file (`write_data` is provided for you) containing the thread ID and the portion of the array that it has processed. Your program should output a message to the console indicating which thread computed which section. Finally, your program should compute the total sum of the array and output it to the console. 
