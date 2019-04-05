#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

bool visit[26];
int board[20][20];
queue<pair<int, int>> q;
int r, c, max_cnt = 0;
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

void dfs(int row, int col, int cnt) {
  // printf("row : %d, col: %d, cnt : %d\n", row, col, cnt);
  int a = board[row][col];
  visit[a] = true;
  if (cnt > max_cnt) max_cnt = cnt;
  for (int i = 0; i < 4; i++) {
    int nr = row + dr[i];
    int nc = col + dc[i];
    if (nr < 0 || nr >= r || nc < 0 || nc >= c || visit[board[nr][nc]]) continue;
    dfs(nr, nc, cnt + 1);
  }
  visit[a] = false;
}

int main() {
  char s[21];
  for (int i = 0; i < 26; i++) visit[i] = false;
  scanf("%d %d", &r, &c);
  for (int i = 0; i < r; i++) {
    scanf("%s", s);
    for (int j = 0; j < c; j++) board[i][j] = s[j] - 'A';
  }
  dfs(0, 0, 1);
  printf("%d\n", max_cnt);
  return 0;
}