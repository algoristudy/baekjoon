#include <cstdio>
using namespace std;

int map[301][301];

int main() {
	int n, m, k, r1, c1, r2, c2;
	long sum = 0;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	scanf("%d", &k);
	while (k--) {
		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		sum = 0;
		for (int i = r1; i <= r2; i++) {
			for (int j = c1; j <= c2; j++) {
				sum += map[i][j];
			}
		}
		printf("%ld\n", sum);
	}

	return 0;
}
