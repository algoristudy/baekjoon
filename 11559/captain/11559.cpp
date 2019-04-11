#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

char board[12][6];
char test[12][6];

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

queue<pair<int, int>> board_queue;

void initTest() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			test[i][j] = board[i][j];
		}
	}
}

bool bfs(int row, int col, char c) {
	int cnt = 1;
	queue<pair<int, int>> q;
	queue<pair<int, int>> bq;
	test[row][col] = '.';
	q.push(make_pair(row, col));
	bq.push(make_pair(row, col));
	while (!q.empty()) {
		row = q.front().first;
		col = q.front().second;
		q.pop();
		int nr, nc;
		for (int i = 0; i < 4; i++) {
			nr = row + dr[i];
			nc = col + dc[i];
			if (nr < 0 || nr >= 12 || nc < 0 || nc >= 6) continue;
			if (test[nr][nc] == c) {
				test[nr][nc] = '.';
				cnt++;
				q.push(make_pair(nr, nc));
				bq.push(make_pair(nr, nc));
			}
		}
	}
	if (cnt >= 4) {
		while (!bq.empty()) {
			board_queue.push(bq.front());
			bq.pop();
		}
	}
	return cnt >= 4 ? true : false;
}

void board_reset() {
	int r, c;
	while (!board_queue.empty()) {
		r = board_queue.front().first;
		c = board_queue.front().second;
		board_queue.pop();
		board[r][c] = '.';
	}
	for (int i = 0; i < 6; i++) {
		int bottom = -1;
		for (int j = 11; j >= 0; j--) {
			if (board[j][i] == '.') {
				bottom = j;
				break;
			}
		}
		if (bottom == -1) continue;
		for (int j = bottom; j >= 0; j--) {
			if (board[j][i] != '.') {
				board[bottom--][i] = board[j][i];
				board[j][i] = '.';
			}
		}
	}
}

int main() {
	int cnt = 0;
	char c[7];
	// 입력
	for (int i = 0; i < 12; i++) {
		scanf("%s", c);
		for (int j = 0; j < 6; j++) {
			board[i][j] = c[j];
		}
	}
	// 처리
	while (true) {
		initTest();
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (test[i][j] != '.') {
					bfs(i, j, test[i][j]);
				}
			}
		}
		if (board_queue.empty()) break;
		board_reset();
		cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
