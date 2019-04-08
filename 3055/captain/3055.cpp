#include <cstdio>
using namespace std;

struct pos {
	int r;
	int c;
};

char map[51][51];
int r, c, cnt = 0;
pos s;
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

int wf, we, mf, me;
pos wq[3000], mq[3000];

int solve() {
	while (true) {
		wf = we = mf = me = 0;
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				int nr, nc;
				if (map[i][j] == '*') {
					// 물일 경우 
					for (int k = 0; k < 4; k++) {
						nr = i + dr[k];
						nc = j + dc[k];
						if (nr < 1 || nr > r || nc < 1 || nc > c) continue;
						// printf("nr: %d, nc: %d\n", nr, nc);
						if (map[nr][nc] == 'S' || map[nr][nc] == '.') wq[we++] = {nr, nc};
					}
				} else if (map[i][j] == 'S') {
					for (int k = 0; k < 4; k++) {
						nr = i + dr[k];
						nc = j + dc[k];
						if (nr < 1 || nr > r || nc < 1 || nc > c) continue;
						if (map[nr][nc] == '.') mq[me++] = {nr, nc};
						else if (map[nr][nc] == 'D') return ++cnt;
					}
				}
			}
		}
		if (mf == me) return -1;
		while (wf != we) {
			pos p = wq[wf++];
			map[p.r][p.c] = '*';
		}
		while (mf != me) {
			pos p = mq[mf++];
			if (map[p.r][p.c] == '.') map[p.r][p.c] = 'S';
		}
		// for (int i = 1; i <= r; i++) {
		// 	for (int j = 1; j <= c; j++) {
		// 		printf("%c ", map[i][j]);
		// 	}
		// 	printf("\n");
		// }
		cnt++;
	}
}

int main() {
	char s[51];
	int count; 
	scanf("%d %d\n", &r, &c);
	for (int i = 1; i <= r; i++) {
		scanf("%s", s);
		for (int j = 0; j < c; j++) {
			map[i][j + 1] = s[j];
		}
	}
	count = solve();
	if (count == -1) printf("KAKTUS\n");
	else printf("%d\n", cnt);
	return 0;
}
