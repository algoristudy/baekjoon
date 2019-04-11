#include <cstdio>
#include <vector>
using namespace std;

vector<int> park(101, 0); 

int main() {
	int a, b, c, s, e, sum = 0;
	scanf("%d %d %d", &a, &b, &c);
	for (int i = 0; i < 3; i++) {
		scanf("%d %d", &s, &e);
		for (int j = s + 1; j <= e; j++) {
			park[j]++;
		}
	}
	for (int i = 0; i < 101; i++) {
		if (park[i] == 1) sum += a;
		else if (park[i] == 2) sum += 2 * b;
		else if (park[i] == 3) sum += 3 * c;
	}
	printf("%d\n", sum);
	
	return 0;
}
