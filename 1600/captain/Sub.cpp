#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int k, w, h;
int board[201][201];
bool visit[201][201][31];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int kdx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int kdy[] = {1, -1, 1, -1, 2, -2, 2, -2};

struct position {
    int x;
    int y;
    int k;
    int cnt;
};

int bfs(int k) {
    queue<position> q;
    q.push(position({0, 0, k, 0}));

    while (!q.empty()) {
        position cur = q.front();
        q.pop();

        if (cur.x < 0 || cur.y < 0 || cur.x >= w || cur.y >= h || board[cur.y][cur.x]) continue; // 범위를 벗어나거나, 장애물로 갈 수 없는 경우

        if (cur.x == w - 1 && cur.y == h - 1) return cur.cnt; // 목적지에 도착하였을 경우 카운트

        if (visit[cur.y][cur.x][cur.k]) continue;
        visit[cur.y][cur.x][cur.k] = true;

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            q.push(position({nx, ny, cur.k, cur.cnt + 1}));
        }

        if (cur.k == 0) continue;
        for (int i = 0; i < 8; i++) {
            int nx = cur.x + kdx[i];
            int ny = cur.y + kdy[i];
            q.push(position({nx, ny, cur.k - 1, cur.cnt + 1}));
        }
    }

    return -1;
}

int main(void) {
    scanf("%d %d %d", &k, &w, &h);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    printf("%d\n", bfs(k));

    return 0;
}