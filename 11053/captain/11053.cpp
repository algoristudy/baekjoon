#include <cstdio>

using namespace std;

int arr[1001], DP[1001];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    DP[i] = 1001;
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= cnt; j++) {
      if (arr[i] == DP[j]) break;
      if (arr[i] < DP[j]) {
        DP[j] = arr[i];
        if (j == cnt) cnt++;
        break;
      }
    }
  }
  printf("%d\n", cnt);
  return 0;
}