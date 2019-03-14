#include <cstdio>

using namespace std;

char result[201];

int main() {
	char i, n;
	scanf("%d", &i);
	while (i--) {
		scanf("%d", &n);
		result[n + 100]++;
	}
	scanf("%d", &n);
	printf("%d", result[n + 100]);
	return 0;
}