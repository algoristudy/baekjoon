#include <cstdio>
#include <queue>

using namespace std;

struct pos
{
  int x;
  int y;
  int count = 0;
};

bool visit[301][301];
int t, l;
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
pos start, goal, p, np;


int bfs() {
  if (start.x == goal.x && start.y == goal.y) return 0;
  visit[start.y][start.x] = true;
  queue<pos> q;
  q.push(start);
  while(!q.empty()) {
    p = q.front();
    q.pop();
    for (int i = 0; i < 8; i++) {
      np.x = p.x + dx[i];
      np.y = p.y + dy[i];
      if (np.x < 0 || np.x >= l || np.y < 0 || np.y >= l || visit[np.y][np.x]) continue;
      if (np.x == goal.x && np.y == goal.y) return p.count + 1;
      visit[np.y][np.x] = true;
      np.count = p.count + 1;
      q.push(np);
    }
  }
  return 0;
}

int main() {
  scanf("%d", &t); {
    while(t--) {
      scanf("%d %d %d %d %d", &l, &start.x, &start.y, &goal.x, &goal.y);
      for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
          visit[i][j] = false;
        }
      }
      
      printf("%d\n", bfs());
    }
  }
}