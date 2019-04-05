#include <cstdio>
#include <queue>

using namespace std;
unsigned int result[100001];

int main() {
	int n, index = 0;
	long x;
	priority_queue<long> pq;
	scanf("%d", &n);
	while (n--) {
		scanf(" %d", &x);
		if (x == 0) {
			if (pq.empty()) {
				result[index++] = 0;
			}
			else {
				result[index++] = -1 * pq.top();
				pq.pop();
			}
		}
		else {
			pq.push(x * -1);
		}
	}
	for (int i = 0; i < index; i++) {
		printf("%d\n", result[i]);
	}
	return 0;
}