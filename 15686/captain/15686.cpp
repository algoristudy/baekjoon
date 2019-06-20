#include <cstdio>
#include <vector>
using namespace std;

int n, m, chicken_distance = 200000;

struct pos {
	int r; 
	int c;
};

int map[50][50], choose[13];
int test[50][50];
vector<pos> chicken;

int diff(int a, int b) {
	return a > b ? a - b : b - a;
}

int distance(int r, int c) {
	pos p;
	int d_min = 101, d;
	for (int i = 0; i < m; i++) {
		p = chicken[choose[i]];
		d = diff(r, p.r) + diff(c, p.c);
		if (d_min > d) d_min = d;
	}
	return d_min;
}

void dfs(int s, int index) {
	// s 시작 인덱스, index 위치
	if (index != m) {
		for (int i = s; i <= chicken.size() - m + index; i++) {
			choose[index] = i;
			dfs(i + 1, index + 1);
		}
	} else {
		int cnt = 0;
		// 치킨 거리 구하기
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 1) {
					cnt += distance(i, j);
				}
			}
		}
		if (chicken_distance > cnt) chicken_distance = cnt;
	}
}

int main() {
	// 데이터 입력
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) {
				chicken.push_back({i, j});
			}
		}
	}
	// 치킨 배치
	dfs(0, 0);
	printf("%d\n", chicken_distance);
	return 0;
}
