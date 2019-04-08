#include <cstdio>

using namespace std;

long DP[100][10];

int main() {
  int n, sum = 0;
  scanf("%d", &n);
  for (int i = 0; i < 10; i++) DP[0][i] = i == 0 ? 0 : 1;
  for (int i = 1; i < n; i++) {
    DP[i][0] = DP[i - 1][1];
    DP[i][9] = DP[i - 1][8];
    for (int j = 1; j < 9; j++) DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % 1000000000;
  }
  for (int i = 0; i < 10; i++) sum = (sum + DP[n - 1][i]) % 1000000000;
  printf("%d\n", sum);
  return 0;
}