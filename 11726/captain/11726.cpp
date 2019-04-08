#include <cstdio>

using namespace std;

int DP[1001];

int main() {
  int n;
  scanf("%d", &n);
  DP[0] = 1;
  DP[1] = 2;
  for (int i = 2; i < n; i++) DP[i] = (DP[i - 1] + DP[i - 2]) % 10007;
  printf("%d\n", DP[n - 1] % 10007);
  return 0;
}