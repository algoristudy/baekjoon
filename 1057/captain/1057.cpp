#include <cstdio>
using namespace std;
int main() {
	int n, a, b, r = 0;
	scanf("%d %d %d", &n, &a, &b);
	a--; b--;
	while (a != b) {
		a /= 2; b /= 2; r++;
	}
	printf("%d\n", r);
	return 0;
}
