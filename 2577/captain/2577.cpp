#include <cstdio>

using namespace std;

int main() {
  long total = 1;
  int n, num[10];
  for (int i = 0; i < 10; i++) num[i] = 0;
  for (int i = 0; i < 3; i++) {
    scanf("%d", &n);
    total *= n;
  }
  while (total != 0) {
    n = total % 10;
    num[n]++;
    total /= 10;
  }
  for (int i = 0; i < 10; i++) printf("%d\n", num[i]);
}
