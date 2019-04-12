#include <cstdio>
#include <vector>
#define INF 100001
#define SIZE 101
using namespace std;

vector<vector<int>> arr(SIZE, vector<int>(SIZE, INF));

int main() {
	int n, m, from, to, cost;
	scanf("%d %d", &n, &m);
	while (m--) {
		scanf("%d %d %d", &from, &to, &cost);
		if (arr[from][to] > cost) arr[from][to] = cost;
	}
	for (int i = 1; i <= n; i++) arr[i][i] = 0;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j]) arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", arr[i][j] == INF ? 0 : arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
