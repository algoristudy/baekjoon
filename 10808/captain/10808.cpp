#include <cstdio>

using namespace std;

char c[101], a[26], i = 0;

int main() {
	scanf("%s", c);
	while (c[i]) {
		a[c[i++] - 'a']++;
	}
	for (i = 0; i < 26; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}