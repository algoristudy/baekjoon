#include <cstdio>
#define MAX 1001
#define MOD 10007
using namespace std;

int DP[MAX][MAX];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	DP[1][0] = DP[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (i == j || j == 0) DP[i][j] = 1;
			else DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j]) % MOD;
		}
	}
	printf("%d\n", DP[n][m]);
	return 0;
}
