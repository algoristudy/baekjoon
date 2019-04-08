#include <cstdio>

using namespace std;

int arr[1001], DP[1001];

int max(int a, int b) {
  return a > b ? a : b;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &arr[i]);
  }
  DP[0] = arr[0] = 0;
  for (int i = 1; i <= n; i++) {
    DP[i] = 0;
    for (int j = 1; j <= i; j++) {
      DP[i] = max(DP[i], DP[i - j] + arr[j]);
    }
  }
  printf("%d\n", DP[n]);
  return 0;
}

