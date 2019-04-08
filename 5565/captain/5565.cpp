#include <cstdio>
using namespace std;
int main() {
	int total, price;
	scanf("%d", &total);
	for (int i = 0; i < 9; i++) {
		scanf("%d", &price);
		total -= price;
	}
	printf("%d\n", total);
	return 0;
}
