#include <cstdio>

using namespace std;

int result[10001];
int stack[10001];

int main() {
	int n, value, sp = 0, index = 0;
	char c[6];
	scanf("%d", &n);
	while (n--) {
		scanf("%s", c);
		if (c[0] == 'p') {
			if (c[1] == 'u') {
				scanf(" %d", &value);
				stack[sp++] = value;
			}
			else if(c[1] == 'o') {
				result[index++] = sp == 0 ? -1 : stack[--sp];
			}
		}
		else if (c[0] == 's') {
			result[index++] = sp;
		}
		else if (c[0] == 'e') {
			result[index++] = sp == 0 ? 1 : 0;
		}
		else if (c[0] == 't') {
			result[index++] = sp == 0 ? -1 : stack[sp - 1];
		}
	}
	for (int i = 0; i < index; i++) {
		printf("%d\n", result[i]);
	}
	return 0;
}