#include <cstdio>

using namespace std;

static int INF = 999999;
int dist[102][102];
int sum[102];

int main() {
  int n, m, minSum = INF, result;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) 
      dist[i][j] = i == j ? 0 : INF;
  while(m--) {
    int a, b;
    scanf("%d %d", &a, &b);
    dist[a][b] = 1;
    dist[b][a] = 1;
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    int sum = 0;
    for (int j = 1; j <= n; j++) {
      sum += dist[i][j];
    }
    if (sum < minSum) {
      minSum = sum;
      result = i;
    }
  }
  printf("%d\n", result);
  return 0;
}