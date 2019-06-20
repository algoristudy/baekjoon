#include <cstdio>
#include <vector>
#define MAX 100000
using namespace std;

struct pos {
	int r;
	int c;
};

int n, m, h, min_cnt = MAX;
vector<vector<bool>> ladder(32, vector<bool>(12, false));
vector<vector<bool>> test(32, vector<bool>(12, false));
vector<pos> possible;
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
pos choose[4];

int down(int index) {
	for (int i = 1; i <= h; i++) {
		if (ladder[i][index]) index++;
		else if (ladder[i][index - 1]) index--;
	}
	return index;
}

void dfs(int s, int index, int cnt) {
	// 시작 위치, int cnt
	if (index != cnt) {
		for (int i = s; i <= possible.size() - cnt; i++) {
			// choose[index] = possible[i];
			pos p = possible[i];
			ladder[p.r][p.c] = true;
			dfs(i + 1, index + 1, cnt);
			ladder[p.r][p.c] = false;
		}
	} else {
		// 검증하는 단계
		// test 초기화
		// for (int i = 1; i <= h; i++) {
		// 	for (int j = 1; j <= n; j++) {
		// 		if (test[i][j] != ladder[i][j]) test[i][j] = ladder[i][j];
		// 	}
		// }
		// for (int i = 0; i < cnt; i++) {
		// 	pos p = choose[i];
		// 	test[p.r][p.c] = true;
		// }
		// 검사
		for (int i = 1; i <= n; i++) {
			if (i != down(i)) break;
			if (i == n) {
				min_cnt = cnt;
				return;
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &h);
	while (m--) {
		int i, j;
		scanf("%d %d", &i, &j);
		ladder[i][j] = true;
	}
	// 사다리를 놓을 수 있는 위치를 정리
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (ladder[i][j]) continue;
			if (ladder[i][j - 1] || ladder[i][j + 1]) continue;
			possible.push_back({i, j});
		}
	}
	// 홀수 개수가 4개 이상일 경우;
	int odd_count = 0;
	for (int i = 1; i <= n; i++) {
		int l_count = 0;
		for (int j = 1; j <= h; j++) {
			if (ladder[j][i]) l_count++;
		}
		if (l_count % 2 == 1) odd_count++;
	}
	// 검증
	for (int i = odd_count ; i < 4; i++) {
		if (i > possible.size()) break;
		dfs(0, 0, i); 
		if (min_cnt != MAX) break;
	}
	printf("%d\n", min_cnt == MAX ? -1 : min_cnt);
	return 0;
}
