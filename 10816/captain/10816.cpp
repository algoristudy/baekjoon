#include <stdio.h>
#include <unordered_map>

using namespace std;

int input[500000];

int main() {
	int count, num;
	unordered_map<int, int> cards;
	scanf("%d", &count);
	while (count--) {
		scanf(" %d", &num);
		++cards[num];
	}
	scanf("%d", &count);
	for (int i = 0; i < count; i++) {
		scanf(" %d", &num);
		input[i] = num;
	}
	for (int i = 0; i < count; i++) {
		printf("%d ", cards[input[i]]);
	}
	printf("\n");
	return 0;
}