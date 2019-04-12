#include <cstdio>
#include <queue>
using namespace std;

int map[101][101];
bool visit[101][101];
int n;
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

struct pos {
	int r;
	int c;
};

void bfs(int r, int c) {
	queue<pos> q;
	int nr, nc;
	q.push({r, c});
	visit[r][c] = false;
	while (!q.empty()) {
		pos p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			nr = p.r + dr[i];
			nc = p.c + dc[i];
			if (nr < 0 || nr >= n || nc < 0 || nc >= n || !visit[nr][nc]) continue;
			q.push({nr, nc});
			visit[nr][nc] = false;
		}
	}
}

void init_map(int hight) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = map[i][j] > hight ? true : false;
		}
	}
}

int main() {
	int max_cnt = 1, cnt = -1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &map[i][j]);
	for (int i = 1; cnt != 0; i++) {
		init_map(i);
		cnt = 0;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (visit[j][k]) {
					cnt++;
					bfs(j, k);
				}
			}
		}
		if (cnt > max_cnt) max_cnt = cnt;
	}
	printf("%d\n", max_cnt);
	return 0;
}
