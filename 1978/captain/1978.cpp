#include <cstdio>
using namespace std;

bool isPrime[1001] = {false, false, };

int main() {
	int n, m, cnt = 0;
	for (int i = 2; i < 1001; i++) isPrime[i] = true;
	for (int i = 2; i < 1001; i++) {
		if (isPrime[i]) {
			for (int j = i * 2; j < 1001; j += i) isPrime[j] = false;
		}
	}
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &m);
		if (isPrime[m]) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
