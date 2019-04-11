#include <cstdio>
#include <vector>
using namespace std;

vector<bool> arr(1001, true);

int main() {
	int n, i = 0, cnt = 0, l;
	scanf("%d", &n);
	l = n;
	while (l) {
		if (arr[i]) {
			if (cnt == 0) {
				printf("%d ", i + 1);
				cnt++;
				l--;
				arr[i] = false;
			} else {
				cnt--;
			}
		}
		i = i == n - 1 ? 0 : i + 1;
	}
	printf("\n");
	return 0;
}
