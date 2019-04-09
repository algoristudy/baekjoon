#include <cstdio>
using namespace std;

int arr[101], DP[10001] = {1, };

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = arr[i]; j <= k; j++) {
			DP[j] += DP[j - arr[i]];
		}
	}
	printf("%d\n", DP[k]);
	return 0;
}
