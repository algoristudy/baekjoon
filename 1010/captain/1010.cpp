#include <cstdio>

using namespace std;

int DP[31][31];

int main() {
  for (int i = 0; i < 31; i++) {
    DP[0][i] = 1;
    DP[i][i] = 1;
  }
  for (int i = 1; i < 31; i++) {
    for (int j = i + 1; j < 31; j++) {
      DP[i][j] = DP[i - 1][j - 1] + DP[i][j - 1];
    }
  }
  int t, n, m;
  scanf("%d", &t);
  while(t--) {
    scanf("%d %d", &n, &m);
    printf("%d\n", DP[n][m]);
  }
  return 0;
}