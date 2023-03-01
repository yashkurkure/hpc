# Getting Started

Executing a code on a super computer

## Project Structure

- prime.cc
    - Takes a number `n` from the command line.
    - loops `i` from `2 to n` checking if each number `i` is a prime number.
    - If `i` is prime sleep for 1 ns.

- prime.sh
    - Runs the program in prime.cc for a list of inputs in `input.txt`.
    - Measures the execution time for each number input in `input.txt`.
    - Generates `optimusprime.csv` with the input number and the execution time.

- **NEW!!** prime.pbs
    ```
    #!/bin/bash
    #PBS -N prime
    #PBS -l nodes=1:ppn=1
    #PBS -l walltime=00:20:00
    #PBS -q edu_shared
    #PBS -j oe

    cd $PBS_O_WORKDIR

    ./prime.sh
    ```
    Breakdown:
    -   `#!/bin/bash` is the shebang, specifies the path to the bash interpreter.
    - `#PBS -N prime` specifies the name of the job. In this case "prime".
    - `#PBS -l` to specifiy the resouce list that the job requires.
        - `#PBS -l nodes=1:ppn=1` defines the resources the job requires. Here we asign 1 node and 1 processor per node. 
        - `#PBS -l walltime=00:20:00` specifies that  job requires 20 minutes to run.
        - `#PBS -l mem=2gb` specifies that the job requires 2gb over all nodes.
    - `#PBS -q edu_shared` specifes the queue where the job will be submitted. In this case `edu_shared`.
    - `#PBS -j oe` combines the output and error into one file.
    - `$PBS_O_WORKDIR` path to the directory from which qsub was executed.

## PBS Commands

Three main commands:
- `qsub` - Allows user to submit jobs to the batch.
- `qstat` - Query for the status of jobs.
- `qdel` - Delete jobs.