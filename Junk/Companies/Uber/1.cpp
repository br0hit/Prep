#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

long long power(long long base, int exp)
{
  long long result = 1;
  while (exp > 0)
  {
    if (exp & 1)
      result = (result * base) % MOD;
    base = (base * base) % MOD;
    exp >>= 1;
  }
  return result;
}

int drawingEdge(int n)
{
  // Number of possible edges
  int edges = (n * (n - 1)) / 2;

  // Each edge can be prese         nt or absent, so 2^edges
  return power(2, edges);
}

int main()
{
  vector<int> test_cases = {1, 2, 3, 4};

  for (int n : test_cases)
  {
    cout << "n = " << n << ": " << drawingEdge(n) << endl;
  }

  return 0;
}