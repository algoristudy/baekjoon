#include <cstdio>
#include <queue>
using namespace std;

struct pos {
  int r;
  int c;
  int cnt;
  int num;
};

int n, dist = 9999999; 
int map[101][101];
bool visit[101][101];
int num = 2;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void initVisit() {
  for (int i = 0; i < n; i++) 
    for (int j = 0; j < n; j++) 
      visit[i][j] = false;
}

void divide(int r, int c) {
  map[r][c] = num; // 대륙을 구분
  queue<pair<int, int>> q;
  q.push({r, c});
  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nr = p.first + dr[i];
      int nc = p.second + dc[i];
      if (nr < 0 || nr >= n || nc < 0 || nc >= n || map[nr][nc] != 1) continue;
      map[nr][nc] = num;
      q.push({nr, nc});
    }
  }
  num++;
}

void getDist(int r, int c) {
  for (int i = 0; i < 4; i++) {
    int nr = r + dr[i];
    int nc = c + dc[i];
    if (nr < 0 || nr >= n || nc < 0 || nc >= n || map[nr][nc] != 0) continue;
    initVisit();
    visit[nr][nc] = true;
    queue<pos> q;
    q.push({nr, nc, 1, map[r][c]});
    while (!q.empty()) {
      pos np, p = q.front();
      q.pop();
      if (p.cnt >= dist) return;
      np.num = p.num;
      np.cnt = p.cnt + 1;
      for (int j = 0; j < 4; j++) {
        np.r = p.r + dr[j];
        np.c = p.c + dc[j];
        if (np.r < 0 || np.r >= n || np.c < 0 || np.c >= n || visit[np.r][np.c]) continue;
        if (map[np.r][np.c] == 0) {
          visit[np.r][np.c] = true;
          q.push(np);
        } else if (map[np.r][np.c] != p.num) {
          // 새로운 대륙을 찾은 것
          if (p.cnt < dist) {
            dist = p.cnt;
          }
          return;
        }

      }
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &map[i][j]);
  
  for (int i = 0; i < n; i++) 
    for (int j = 0; j < n; j++)
      if (map[i][j] == 1) divide(i, j);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (map[i][j] != 0) {
        getDist(i, j);
      }
    }
  }
  
  printf("%d\n", dist);

  return 0;
}