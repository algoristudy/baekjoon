#include <cstdio>
#include <stdlib.h>
using namespace std;

char c[8] = "0000004";

void next(int i) {
	if (c[i] == '0') c[i] = '4';
	else if (c[i] == '4') c[i] = '7';
	else {
		c[i] = '4';
		next(i - 1);
	}
}

int main() {
	int n, num = 4, i = 7;
	scanf("%d", &n);
	while (n >= atoi(c)) {
		num = atoi(c);
		next(6);
	}
	printf("%d\n", num);
	return 0;
}
