#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct pos {
  int r;
  int c;
  int cnt;
};

char map[51][51];
bool visit[51][51];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void initVisit(int r, int c) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      visit[i][j] = false;
    }
  }
}

int main() {
  int r, c, d = 0;
  pos p, np;
  string s;
  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    cin >> s;
    for (int j = 0; j < c; j++) {
      map[i][j] = s[j];
    }
  }

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (map[i][j] == 'L') {
        initVisit(r, c);
        queue<pos> q;
        q.push({i, j, 0});
        visit[i][j] = true;
        while (!q.empty()) {
          p = q.front(); 
          q.pop();
          for(int k = 0; k < 4; k++) {
            np.r = p.r + dr[k];
            np.c = p.c + dc[k];
            if (np.r < 0 || np.r >= r || np.c < 0 || np.c >= c || visit[np.r][np.c] || map[np.r][np.c] == 'W') continue;
            np.cnt = p.cnt + 1;
            visit[np.r][np.c] = true;
            if (np.cnt > d) d = np.cnt;
            q.push(np);
          }
        }
      }
    }
  }

  cout << d << endl;
  
  return 0;
}