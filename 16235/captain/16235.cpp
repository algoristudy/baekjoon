#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int>> have(11, vector<int>(11, 5));
vector<vector<int>> tree_count(11, vector<int>(11, 0));
vector<vector<int>> death_energy(11, vector<int>(11, 0));
vector<vector<int>> death_count(11, vector<int>(11, 0));
int give[11][11], orchard[11][11][1000];
int n, m;
int dr[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dc[] = {0, 1, 0, -1, 1, -1, 1, -1};

void spring() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// 어린 나무부터 나이를 먹는다.
			for (int k = tree_count[i][j] - 1; k >= 0; k--) {
				if (have[i][j] < orchard[i][j][k]) {
					// 영양분이 부족하여 먹지 못하는 경우 death에 영양분 추가
					death_energy[i][j] += orchard[i][j][k] / 2;
					death_count[i][j]++;
				} else {
					// 영양분을 먹고, 나이가 1살 늘어남
					have[i][j] -= orchard[i][j][k]++;
				}
			}
		}
	}
}

void summer() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (death_count[i][j]) {
				// 에너지 토양에 반납 후 초기화
				have[i][j] += death_energy[i][j];
				death_energy[i][j] = 0;
				// 죽은 나무 배제 나무 위치 재배치
				for (int k = 0; k < tree_count[i][j] - death_count[i][j]; k++) {
					orchard[i][j][k] = orchard[i][j][k + death_count[i][j]];
				}
				tree_count[i][j] -= death_count[i][j];
				death_count[i][j] = 0;
			}
		}
	}
}

void fall() {
	int nr, nc;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < tree_count[i][j]; k++) {
				if (orchard[i][j][k] % 5 == 0) {
					for (int l = 0; l < 8; l++) {
						nr = i + dr[l];
						nc = j + dc[l];
						if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
						orchard[nr][nc][tree_count[nr][nc]++] = 1;
					}
				}
			}
		}
	}
}

void winter() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			have[i][j] += give[i][j];
		}
	}
}

int main() {
	int k, sum = 0;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &give[i][j]);
		}
	}
	for (int i = 0; i < m; i++) {
		int r, c, y;
		scanf("%d %d %d", &r, &c, &y);
		orchard[r - 1][c - 1][tree_count[r - 1][c - 1]++] = y;
	}
	while (k--) {
		// 봄, 여름
		spring();
		summer();
		fall();
		winter();
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum += tree_count[i][j];
		}
	}
	printf("%d\n", sum);
	return 0;
}
