#include <cstdio>
using namespace std;
long DP[101] = {0, 1, 1};
int main() {
	for (int i = 3; i < 101; i++) {
		DP[i] = DP[i - 2] + DP[i - 3];
	}
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("%ld\n", DP[n]);
	}
	return 0;
}
