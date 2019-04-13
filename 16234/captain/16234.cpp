#include <cstdio>
#include <queue>
using namespace std;

struct pos {
	int r;
	int c;
};

int n, L, R;
int arr[101][101];
bool visit[101][101];
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

inline int abs(int a, int b) {
	return a > b ? a - b : b - a; 
}

bool bfs(int r, int c) {
	int sum = 0, avg, nr, nc, diff;
	queue<pos> q1, q2;
	q1.push({r, c});
	q2.push({r, c});
	sum += arr[r][c];
	visit[r][c] = true;
	while (!q1.empty()) {
		r = q1.front().r;
		c = q1.front().c;
		q1.pop();
		for (int i = 0; i < 4; i++) {
			nr = r + dr[i];
			nc = c + dc[i];
			if (nr < 0 || nr >= n || nc < 0 || nc >= n || visit[nr][nc]) continue;
			diff = abs(arr[r][c], arr[nr][nc]);
			// printf("r : %d, c : %d, diff = %d\n", nr, nc, diff);
			if (diff < L || diff > R) continue;
			q1.push({nr, nc});
			q2.push({nr, nc});
			sum += arr[nr][nc];
			visit[nr][nc] = true;
		}
	}
	avg = sum / q2.size();
	while (!q2.empty()) {
		pos p = q2.front();
		q2.pop();
		arr[p.r][p.c] = avg;
	}
	return sum == avg ? false : true;
}

int main() {
	int cnt = -1;
	bool flag = true;
	scanf("%d %d %d", &n, &L, &R);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	while (flag) {
		cnt++;
		flag = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				visit[i][j] = false;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visit[i][j]) {
					flag = bfs(i, j) || flag;
				}
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}
