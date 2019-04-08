#include <cstdio>

using namespace std;

const int SIZE = 501;

int DP[SIZE][SIZE];

int max(int a, int b) {
  return a > b ? a : b;
}

int main() {
  int n, m;
  int result = 0;
  scanf("%d", &n);
  // DP 초기화
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      DP[i][j] = 0;
    }
  }
  scanf("%d", &DP[0][1]);
  // 데이터 입력
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < i + 2; j++) {
      scanf("%d", &m);
      DP[i][j] = max(DP[i - 1][j - 1], DP[i - 1][j]) + m;
    }
  }
  // 최대값 구하기
  for (int i = 1; i < n + 1; i++) {
    if (DP[n - 1][i] > result) result = DP[n - 1][i];
  }
  printf("%d\n", result);
  return 0;
}