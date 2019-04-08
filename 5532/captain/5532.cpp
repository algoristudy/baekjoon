#include <cstdio>
#include <math.h>
using namespace std;
int main() {
	float l, a, b, c, d, work;
	int days;
	scanf("%f %f %f %f %f", &l, &a, &b, &c, &d);
	work = a/c > b/d ? ceil(a / c) : ceil(b / d);
	days = l - work;
	printf("%d\n", days);
	return 0;
}
