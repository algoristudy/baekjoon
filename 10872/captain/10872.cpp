#include <cstdio>

using namespace std;

int main() {
  long t = 1;
  int n;
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) t *= i;
  printf("%ld\n", t);
}
