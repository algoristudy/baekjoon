#include <cstdio>
using namespace std;

long long DP[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

int main() {
	int n;
	int sum = 10, m = 10, tmp;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		sum = 0;
		for (int j = 0; j < 10; j++) {
			tmp = DP[j];
			DP[j] = m % 10007;
			sum += DP[j];
			m -= tmp;
		}
		m = sum;
	}
	printf("%d\n", sum % 10007);
	return 0;
}
