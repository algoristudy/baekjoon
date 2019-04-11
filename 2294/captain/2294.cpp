#include <cstdio>
#include <algorithm>
using namespace std;

// int DP[102][10001];
int arr[102];
int DP[10001] = {0, };

int main() {
	int n, k, cnt = 10001;
	scanf("%d %d", &n, &k);
	arr[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n + 1);
	for(int i = 1; i <= k; i++) DP[i] = 10001;
	for(int i = 1; i <= n; i++) {
		for (int j = arr[i]; j <= k; j++) {
			DP[j] = min(DP[j], DP[j - arr[i]] + 1);
		}
	}
	printf("%d\n", DP[k] == 10001 ? -1 : DP[k]);
	return 0;
}
