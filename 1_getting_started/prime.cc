#include <bits/stdc++.h>
#include <omp.h>
#include <chrono>
#include <thread>
using namespace std;

bool is_prime(unsigned long long n) {
  if (n <= 1)
    return false;
  for (unsigned long long i = 2; i <= sqrt(n); i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cerr << "Usage: " << argv[0] << " <n>" << endl;
    return 1;
  }
  unsigned long long n = strtoull(argv[1], nullptr, 10);
  for (unsigned long long i = 2; i <= n; i++) {
    if (is_prime(i)) {
      // Sleep for 1 nanosecond
      std::this_thread::sleep_for(std::chrono::nanoseconds(1));
    }
  }
  return 0;
}
