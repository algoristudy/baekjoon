#include <cstdio>

using namespace std;

int wine[10002];
int DP[10002];

int max(int a, int b, int c) {
  if (a > b && a > c) return a;
  else if (b > a && b > c) return b;
  else return c;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &wine[i]); 
  }
  DP[0] = wine[0];
  DP[1] = wine[0] + wine[1];
  DP[2] = max(wine[0] + wine[1], wine[0] + wine[2], wine[1] + wine[2]);
  for (int i = 3; i < n; i++) {
    DP[i] = max(DP[i - 1], DP[i - 2] + wine[i], DP[i - 3] + wine[i - 1] + wine[i]);
  }
  printf("%d\n", DP[n - 1]);
  return 0;
}