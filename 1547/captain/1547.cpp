#include <cstdio>
using namespace std;
int main() {
	int n, a, b, pos = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		if (pos == a) pos = b;
		else if (pos == b) pos = a;
	}
	printf("%d\n", pos);
	return 0;
}
