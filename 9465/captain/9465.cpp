#include <cstdio>
using namespace std;

int stamp[2][100001];
int DP[2][100001] = {{0, }, {0, }};

int larger(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int t, n, m;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &m);
				stamp[i][j] = m;
			}
		}
		DP[0][1] = stamp[0][1];
		DP[1][1] = stamp[1][1];
		for (int j = 2; j <= n; j++) {
			DP[0][j] = stamp[0][j] + larger(DP[1][j - 1], larger(DP[0][j - 2], DP[1][j - 2]));
			DP[1][j] = stamp[1][j] + larger(DP[0][j - 1], larger(DP[0][j - 2], DP[1][j - 2]));
		}
		printf("%d\n", larger(DP[0][n], DP[1][n]));
	}
	return 0;
}
