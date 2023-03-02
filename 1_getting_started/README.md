# Getting Started

Executing a program on a super computer

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

### Submit the job

```
qsub prime.pbs
```

If the job was submitted succesfully qsub will echo the job id in the format `<sequence_number>.<server_name> `
```
ykurku2@login-1.extreme:~/hpc/1_getting_started $ qsub prime.pbs
1037417.admin.extreme.acer.uic.edu
```

### Check status of the job

```
qstat 1037417.admin.extreme.acer.uic.edu

//or 

qstat -n //mentions the node the job was submitted to.
```
qstat is the command to check the status of jobs.

Example:
```
ykurku2@login-1.extreme:~/hpc/1_getting_started $ qstat 1037417.admin.extreme.acer.uic.edu
Job ID                    Name             User            Time Use S Queue
------------------------- ---------------- --------------- -------- - -----
1037417.admin              prime            ykurku2         00:00:48 R edu_shared     
ykurku2@login-1.extreme:~/hpc/1_getting_started $ qstat -n 1037417.admin.extreme.acer.uic.edu

admin.extreme.acer.uic.edu: 
                                                                                  Req'd       Req'd       Elap
Job ID                  Username    Queue    Jobname          SessID  NDS   TSK   Memory      Time    S   Time
----------------------- ----------- -------- ---------------- ------ ----- ------ --------- --------- - ---------
1037417.admin.extreme.  ykurku2     edu_shar prime             31534     1      1       --   00:20:00 R  00:02:23
   compute-0-33
ykurku2@login-1.extreme:~/hpc/1_getting_started $ 

```

### Delete a job

Lets first check all the jobs running on the machine:
```
ykurku2@login-1.extreme:~/hpc/1_getting_started $ qstat
Job ID                    Name             User            Time Use S Queue
------------------------- ---------------- --------------- -------- - -----
1037416.admin              prime            ykurku2         00:06:33 C edu_shared     
1037417.admin              prime            ykurku2         00:01:51 R edu_shared     
```
Job 1037416 is (C) complete and Job 1037417 is (R) running.

If you try and cancel the running job...
```
ykurku2@login-1.extreme:~/hpc/1_getting_started $ qdel 1037416.admin 
qdel: Request invalid for state of job MSG=invalid state for job - COMPLETE 1037416.admin.extreme.acer.uic.edu
```

Delete the running job...
```
ykurku2@login-1.extreme:~/hpc/1_getting_started $ qdel 1037417.admin
```

Use qstat to see the update status of the job (C) complete.
```
ykurku2@login-1.extreme:~/hpc/1_getting_started $ qstat
Job ID                    Name             User            Time Use S Queue
------------------------- ---------------- --------------- -------- - -----
1037416.admin              prime            ykurku2         00:06:33 C edu_shared     
1037417.admin              prime            ykurku2         00:02:11 C edu_shared     
ykurku2@login-1.extreme:~/hpc/1_getting_started $ 
```