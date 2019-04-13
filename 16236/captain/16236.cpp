#include <cstdio>
#include <queue>
#define MAX 1000
using namespace std;

struct pos {
	int r;
	int c;
};

struct element {
	int r;
	int c;
	int cnt;
};

int n;
int map[21][21];
bool fish[21][21];
bool visit[21][21];
bool flag = false;
int shark_size = 2;
int eat_cnt = 0;
int cnt = 0;
int dr[] = {-1, 0, 0, 1};
int dc[] = {0, -1, 1, 0};
pos shark_pos;

void initFish() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fish[i][j] = false;
			visit[i][j] = false;
			flag = false;
		}
	}
}

element search() {
	// bfs 이용 상어와 먹이간의 최단거리를 구함
	int r, c, cnt = 0, nr, nc, m = 1000;
	queue<element> q;
	initFish();
	q.push({shark_pos.r, shark_pos.c, 1});
	visit[shark_pos.r][shark_pos.c] = true;
	while (!q.empty()) {
		r = q.front().r;
		c = q.front().c;
		cnt = q.front().cnt;
		if (cnt > m) break;
		q.pop();
		// printf("r : %d, c : %d, cnt : %d\n", r, c, cnt);
		for (int i = 0; i < 4; i++) {
			nr = r + dr[i];
			nc = c + dc[i];
			if (nr < 0 || nr >= n || nc < 0 || nc >= n || map[nr][nc] > shark_size || visit[nr][nc]) continue;
			if (map[nr][nc] != 0 && map[nr][nc] < shark_size) {
				m = cnt;
				fish[nr][nc] = true;
				flag = true;
			}
			if (!flag) {
				q.push({nr, nc, cnt + 1});
				visit[nr][nc] = true;
			}
		}
	}
	if (flag) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (fish[i][j]) return {i, j, m};
			}
		}
	}
	return {-1, -1, 0};
}

int main() {
	element e;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) shark_pos = {i, j};
		}
	}
	while (true) {
		map[shark_pos.r][shark_pos.c] = 0;
		e = search(); // 목표로 하는 물고기 위치
		if (e.r == -1) break; // 더 이상 물고기가 없을 경우
		// printf("size = %d, eat_cnt : %d,\t\tr : %d, c : %d, cnt : %d\n", shark_size, eat_cnt + 1, e.r, e.c, e.cnt);
		shark_pos = {e.r, e.c};
		cnt += e.cnt;
		eat_cnt++;
		if (eat_cnt == shark_size) {
			shark_size++;
			eat_cnt = 0;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
