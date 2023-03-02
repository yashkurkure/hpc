**Grade:** 150.0/150.0 <BR>
**Comments:** Nice job, why not use the excel files versus the web page? Would very much like to see your python scripts. <BR>

# High Performance Linpack (HPL)
**Assignment:** 

This assignment will introduce you to the idea of benchmarking and how it can be used to understand trends. You will look at some trends in HPC, calculate the performance of one of your devices (cell phone, laptop, desktop) and compare it to Top500 over time.

**Problem Description:**

For this assignment, you will install Linpack on one of your devices; a simple google search will likely yield one or more prebuilt versions of Linpack.  For instance:
 
 - **Android Phone** via [Google Play Store](https://play.google.com/store/apps/details?id=com.sqi.linpackbenchmark&hl=en_US&gl=US)
 - **iPhone** via [Apple App Store](https://apps.apple.com/us/app/linpack/id380883195) 
 - **iPhone** via [Apple App Store](https://apps.apple.com/us/app/mobile-linpack/id1001893181)
 - **Linux** for [Intel processors](https://www.intel.com/content/www/us/en/developer/articles/technical/onemkl-benchmarks-suite.html)
 - **Windows** for [Intel Processors](https://www.intel.com/content/www/us/en/developer/articles/technical/onemkl-benchmarks-suite.html)
 - **MacOS** for [Intel Processors](https://www.intel.com/content/www/us/en/developer/articles/technical/onemkl-benchmarks-suite.html)
 - **MacOS** for Apple (ARM) Processors can run iPhone versions

There are even more out there - the goal here is not really how fast your device is but more to get a feel for where today's modern devices fit relative to HPC across time. You can find an extensive disucssion of HPL in Chapter 04 of the course textbook.

You can find all the Top500 rankings from 1993 - 2022 on the [course website](https://www.evl.uic.edu/papka/cs494/assignments).

**Assignment Requirements:**

Other than finding a way to *benchmark suite* your device, you can use **Microsoft Excel** to do most of the assignment.

You will need to keep notes along the way - you can do this in **Excel** or anything you want; in the end, you will commit your notes in PDF form into the repository for submission.

**Assignment Tasks:**

1. Benchmark your device; you want to run the benchmark at least **ten** times, capturing the value for those **ten** runs and then computing the average. (the values should be in your PDF notes file)
2. In what year would your device have entered the top500? What would be its ranking?
3. What was the fastest machine in the world the year you were born (or your favorite year if you don't want to use your birth year)?
4. How many times faster was the #1 machine than the #500 machine that year?
5. Write a few sentences about that year's resources based on what you see in the top500 results; remember that every year has two postings of the list.
6. Using the November numbers for the past ten years, create histogram bins of the machines by the ratio of Rmax to RPeak for the top 10 systems (remove duplicates, same machine on the list for multiple years).  Remember Rmax is the value achieved during HPL, and Rpeak is the theoretical performance of the machine.  The result will show the distribution of the computational efficiency of the machines.
7. Please add some comments on the assignment - what you liked, didn't like, and how it could be improved in the future.
8. When finished, you will add, commit and push a single PDF file to the assignment repository and issue a pull request that the assignment is ready for grading.  Remember to create a *development* branch, and the PDF will be part of that development branch.

