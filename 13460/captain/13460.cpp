#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

struct pos {
	int r;
	int c;
};

struct triple {
	pos red;
	pos blue;
	int cnt;
};

int map[11][11];
int n, m;
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
pos R, B, O;

pair<pos, pos> nextPos(pos red, pos blue, int d) {
	// red : 빨간공의 위치
	// blue : 파란공의 위치
	// d : 방향 인덱스
	int nr, nc;
	int index[] = {1, 0};
	bool reverse = false;
	pos ball[2] = {red, blue};
	if ((d == 0 && red.r < blue.r)
		|| (d == 1 && red.c < blue.c)
		|| (d == 2 && red.r > blue.r)
		|| (d == 3 && red.c > blue.c)) {
		ball[0] = blue; ball[1] = red;
		reverse = true;
	} 
	for (int i = 0; i < 2; i++) {
		while (true) {
			nr = ball[i].r + dr[d];
			nc = ball[i].c + dc[d];
			// printf("%s r : %d, c: %d\n", i == 0 ? "red" : "blue", nr, nc);
			if (map[nr][nc] == '#' || (ball[index[i]].r == nr && ball[index[i]].c == nc)) break;
			else if (map[nr][nc] == 'O') {
				ball[i] = {0, 0};
				break;
			}
			ball[i] = {nr, nc};
		}
	}
	return reverse ? make_pair(ball[1], ball[0]) : make_pair(ball[0], ball[1]);
}

int bfs() {
	queue<triple> q;
	pair<pos, pos> nPos;
	pos red, blue;
	int cnt = 1;
	q.push({R, B, cnt});
	while (!q.empty()) {
		red = q.front().red;
		blue = q.front().blue;
		cnt = q.front().cnt;
		if (cnt == 11) break;
		q.pop();
		// printf("\nred : %d %d , blue : %d %d, cnt : %d\n\n", red.r, red.c, blue.r, blue.c, cnt);
		for (int i = 0; i < 4; i++) {
			nPos = nextPos(red, blue, i);
			if (nPos.second.r == 0) continue;
			if (nPos.first.r == red.r && nPos.first.c == red.c && nPos.second.r == blue.r && nPos.second.c == blue.c) continue;
			if (nPos.first.r == 0) return cnt;
			q.push({nPos.first, nPos.second, cnt + 1});
		}
	}
	return -1;
}

int main() {
	char c[11];

	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		scanf("%s", c);
		for (int j = 0; j < m; j++) {
			map[i][j] = c[j];
			if (c[j] == 'O') O = {i, j};
			else if (c[j] == 'R') R = {i, j};
			else if (c[j] == 'B') B = {i, j};
		}
	}
	printf("%d\n", bfs());
	return 0;
}
