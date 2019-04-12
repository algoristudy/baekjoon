#include <cstdio>
#include <queue>
using namespace std;

struct pos {
	int r;
	int c;
};

int n = 1, m = 1, cnt;
int arr[50][50]; 
int dr[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dc[] = {0, 1, 0, -1, 1, -1, 1, -1};

void bfs(int r, int c) {
	queue<pos> q;
	int nr, nc;
	arr[r][c] = 0;
	q.push({r, c});
	while (!q.empty()) {
		pos cur = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			nr = cur.r + dr[i];
			nc = cur.c + dc[i];
			if (nr < 0 || nr >= n || nc < 0 || nc >= m || arr[nr][nc] == 0) continue;
			arr[nr][nc] = 0;
			q.push({nr, nc});
		}
	}
}

int main() {
	while (true) {
		scanf("%d %d", &m, &n);
		if (m == 0 && n == 0) break;
		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 1) {
					cnt++; 
					bfs(i, j);
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
