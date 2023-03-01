#!/bin/bash

# Loop over all values in the input file
while read input_number; do

  # Measure the execution time with nanosecond accuracy
  start_time=$(date +%s%N)
  ./prime $input_number
  end_time=$(date +%s%N)

  # Calculate the execution time in nanoseconds
  execution_time=$((end_time - start_time))
  execution_time_in_seconds=$(bc <<< "scale=9; $execution_time/1000000000")

  # Write the execution time and input number to a CSV file
  echo "$input_number,$execution_time" >> prime.csv

  # Measure the execution time with nanosecond accuracy
  start_time=$(date +%s%N)
  ./optimusprime $input_number
  end_time=$(date +%s%N)

  # Calculate the execution time in nanoseconds
  execution_time=$((end_time - start_time))
  execution_time_in_seconds=$(bc <<< "scale=9; $execution_time/1000000000")

  # Write the execution time and input number to a CSV file
  echo "$input_number,$execution_time" >> optimusprime.csv

done < input.txt
