#include <cstdio>
using namespace std;

const int div_num = 10007;
int DP[1001] = {1, 3, };

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 2; i < n; i++) {
    DP[i] = (DP[i - 1] + DP[i - 2] * 2) % div_num;
  }
  printf("%d\n", DP[n - 1]);
  return 0;
}