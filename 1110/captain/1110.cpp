#include <cstdio>
using namespace std;

int main() {
	int n, a, b, c, cnt = 0;
	int init[2]; 
	scanf("%d", &n);
	init[0] = a = n / 10;
	init[1] = b = n % 10;
	while (true) {
		cnt++;
		c = a + b;
		c %= 10;
		if (b == init[0] && c == init[1]) break;
		a = b; 
		b = c;
	}
	printf("%d\n", cnt);
	return 0;
}
