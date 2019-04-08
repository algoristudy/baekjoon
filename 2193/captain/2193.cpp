#include <cstdio>

using namespace std;

long DP[100];

int main() {
  int n; 
  scanf("%d", &n);
  DP[0] = 1; DP[1] = 1;
  for (int i = 2; i < n; i++) DP[i] = DP[i - 1] + DP[i - 2];
  printf("%ld\n", DP[n - 1]);
  return 0;
}