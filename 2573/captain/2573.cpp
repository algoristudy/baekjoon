#include <cstdio>

using namespace std;

int iceburg[301][301];
int meltAmount[301][301];
int check[301][301];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
int r, c;

void dfs(int cr, int cc, int count) {
  check[cr][cc] = count;
  for (int i = 0; i < 4; i++) {
    int nr = cr + dr[i];
    int nc = cc + dc[i];
    if (nr < 0 || nr >= r || nc < 0 || nc >= c) continue;
    if (iceburg[nr][nc] > 0 && check[nr][nc] == 0) {
      dfs(nr, nc, count);
    }
  }
}

int divide() {
  int count = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      check[i][j] = 0;
    }
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (check[i][j] == 0 && iceburg[i][j] > 0) {
        count++;
        dfs(i, j, count);
      }
    }
  }
  return count;
}

void melt() {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      meltAmount[i][j] = 0;
      if (iceburg[i][j] > 0) {
        for (int k = 0; k < 4; k++) {
          int nr = i + dr[k];
          int nc = j + dc[k];
          if (nr < 0 || nr >= r || nc < 0 || nc >= c) continue;
          if (iceburg[nr][nc] == 0) meltAmount[i][j]++;
        }
      }
    }
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      iceburg[i][j] = iceburg[i][j] > meltAmount[i][j] ? iceburg[i][j] - meltAmount[i][j] : 0;
    }
  }
}

int main() {
  int num, year = 0;
  scanf("%d %d", &r, &c);
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      scanf("%d", &iceburg[i][j]);
    }
  }
  while (true) {
    num = divide();
    if (num != 1) break;
    year++;
    melt(); 
  }

  printf("%d\n", num == 0 ? 0 : year);

  return 0;
}