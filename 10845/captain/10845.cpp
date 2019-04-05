#include <cstring>
#include <string>
using namespace std;

int queue[10001];
int result[10001];
int f = 0, b = 0;

void push(int n) {
	queue[b++] = n;
}

int pop() {
	return f == b ? -1 : queue[f++];
}

int size() {
	return b - f;
}

int empty() {
	return f == b ? 1 : 0;
}

int front() {
	return f == b ? -1 : queue[f];
}

int back() {
	return f == b ? -1 : queue[b - 1];
}

int main() {
	int N, num, i = 0;
	scanf("%d", &N);
	char s[6];
	while (N--) {
		scanf("%s", s);
		if (!strcmp(s, "push")) {
			scanf(" %d", &num);
			push(num);
		}
		else if (!strcmp(s, "pop")) {
			result[i++] = pop();
		}
		else if (!strcmp(s, "size")) {
			result[i++] = size();
		}
		else if (!strcmp(s, "empty")) {
			result[i++] = empty();
		}
		else if (!strcmp(s, "front")) {
			result[i++] = front();
		}
		else if (!strcmp(s, "back")) {
			result[i++] = back();
		}
	}
	for (int j = 0; j < i; j++) {
		printf("%d\n", result[j]);
	}
	return 0;
}