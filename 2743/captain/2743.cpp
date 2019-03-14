#include <cstdio>

int main() {
	char c[101], i = 0;
	scanf("%s", c);
	while (c[i]) i++;
	printf("%d", i);
	return 0;
}