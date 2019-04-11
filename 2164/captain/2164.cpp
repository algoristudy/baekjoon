#include <cstdio>
#include <vector>
using namespace std;

vector<bool> cards(500000, true);

int main() {
	int n, i = 0, cnt = 0;
	bool remove = true;
	scanf("%d", &n);
	while (true) {
		if (cards[i]) {
			if (remove) {
				cards[i] = false;
				cnt++;
				if (cnt == n) {
					printf("%d\n", i + 1);
					break;
				}
				remove = false;
			} else {
				remove = true;
			}
		}
		i++;
		if (i == n) i = 0;
	}
	return 0;
}
