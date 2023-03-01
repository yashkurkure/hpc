import csv
import matplotlib.pyplot as plt

def read_results(filename):
  with open(filename, 'r') as f:
    reader = csv.reader(f)
    next(reader)  # skip header
    inputs = []
    times = []
    for row in reader:
      inputs.append(int(row[0]))
      times.append(float(row[1]))
  return inputs, times

def plot_results(inputs, times):
  plt.plot(inputs, times)
  plt.xlabel("Input")
  plt.ylabel("Time (s)")
  plt.title("Time to Calculate Largest Prime")
  plt.savefig("results.png")

if __name__ == '__main__':
  inputs, times = read_results("prime.csv")
  plot_results(inputs, times)
