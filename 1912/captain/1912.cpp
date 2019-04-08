#include <cstdio>

using namespace std;

int DP[100001] = {0, }, max_sum = -1001;

int max(int a, int b) {
  return a > b ? a : b;
}

int main() {
  int n, m;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &m);
    DP[i] = DP[i - 1] + m > m ? DP[i - 1] + m : m;
    if (DP[i] > max_sum) max_sum = DP[i];
  }
  printf("%d\n", max_sum);
  return 0;
}