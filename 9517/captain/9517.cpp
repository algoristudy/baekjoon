#include <cstdio>
using namespace std;
int main() {
	int k, n, t, time = 210;
	char f;
	scanf("%d %d", &k, &n);
	while (n--) {
		scanf("%d %c", &t, &f);
		time -= t;
		if (time <= 0) break;
		if (f == 'T') {
			k = k == 8 ? 1 : k + 1;
		}
	}
	printf("%d\n", k);
	return 0;
}
