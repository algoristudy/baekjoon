#include <cstdio>
using namespace std;

int n;

char screen[101][101];
bool visit[101][101];
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

void init(char c) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (screen[i][j] == 'G') screen[i][j] = c;
			visit[i][j] = false;
		}
	}
}

void dfs(int r, int c) {
	int nr, nc;
	visit[r][c] = true;
	for (int i = 0; i < 4; i++) {
		nr = r + dr[i];
		nc = c + dc[i];
		if (nr < 0 || nr >= n || nc < 0 || nc >= n || visit[nr][nc] || screen[r][c] != screen[nr][nc]) continue;
		dfs(nr, nc);
	}
}

int main() {
	char c[101], color[2] = {'G', 'R'};
	int cnt;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", c);
		for (int j = 0; j < n; j++) {
			screen[i][j] = c[j];
		}
	}
	for (int i = 0; i < 2; i++) {
		cnt = 0;
		init(color[i]);
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (!visit[j][k]) {
					cnt++;
					dfs(j, k);
				}
			}
		}
		printf("%d ", cnt); 
	}
	printf("\n");
	return 0;
}
