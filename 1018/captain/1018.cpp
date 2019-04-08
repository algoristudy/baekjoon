#include <cstdio>
using namespace std;

char board[51][51];

int get_count(int r, int c) {
	int wc = 0;
	int bc = 0;
	char color = 'W';
	for (int i = r; i < r + 8; i++) {
		for (int j = c; j < c + 8; j++) {
			// 화이트로 시작할 경우
			if (board[i][j] != color) wc++;
			if (board[i][j] == color) bc++;
			color = color == 'W' ? 'B' : 'W';
		}
		color = color == 'W' ? 'B' : 'W';
	}
	return wc < bc ? wc : bc;
}

int main() {
	int n, m, min_count = 64;
	char c[51];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", c);
		for (int j = 0; j < m; j++) {
			board[i][j] = c[j];
		}
	}
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			int cnt = get_count(i, j);
			if (min_count > cnt) min_count = cnt;
		}
	}
	printf("%d\n", min_count);
	return 0;
}
