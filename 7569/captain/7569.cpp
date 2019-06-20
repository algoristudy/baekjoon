#include <cstdio>
#include <queue>

using namespace std;

struct Pos {
  int h;
  int r;
  int c;
  int cnt = 0;
};

int dh[] = {-1, 1};
int dr[] = {1, 0, -1, 0}; 
int dc[] = {0, -1, 0, 1}; 

queue<Pos> q; 

int main() {
  Pos pos;
  int count = 0, m, n, h, state; // count 익지 않은 토마토 개수
  int result = 0;
  int box[101][101][101];
  scanf("%d %d %d ", &m, &n, &h);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++) {
        scanf("%d", &box[i][j][k]);
        if (box[i][j][k] == 0) count++;
        else if (box[i][j][k] == 1) {
          pos.h = i; pos.r = j; pos.c = k;
          q.push(pos);
        };
      }
    }
  }
  while (!q.empty() && count != 0) {
    Pos np, p = q.front();
    q.pop();
    // r, c 방향 구하기
    np.h = p.h;
    np.cnt = p.cnt + 1;
    for (int i = 0; i < 4; i++) {
      np.r = p.r + dr[i];
      np.c = p.c + dc[i];
      if (np.r < 0 || np.r >= n || np.c < 0 || np.c >= m) continue;
      if (box[np.h][np.r][np.c] == 0) {
        box[np.h][np.r][np.c] = 1;
        count--;
        if (result < np.cnt) result = np.cnt;
        q.push(np);
      }
    }
    // h 방향 구하기
    np.r = p.r;
    np.c = p.c;
    for (int i = 0; i < 2; i++) {
      np.h = p.h + dh[i];
      if (np.h < 0 || np.h >= h) continue;
      if (box[np.h][np.r][np.c] == 0) {
        box[np.h][np.r][np.c] = 1;
        count--;
        if (result < np.cnt) result = np.cnt; 
        q.push(np);
      }
    }
  }
  printf("%d\n", count == 0 ? result : -1);
}