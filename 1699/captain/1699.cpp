#include <cstdio>
#define INF 100001

using namespace std;

int arr[INF]; 

inline int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	int n, m = 2, p = m * m;
	scanf("%d", &n);
	for (int i = 0; i <= n; i++) arr[i] = i;
	while (n >= p) {
		for (int i = p; i <= n; i++) {
			arr[i] = min(arr[i], arr[i - p] + 1);
		}
		m++;
		p = m * m;
	}
	printf("%d\n", arr[n]);
	return 0;
}
