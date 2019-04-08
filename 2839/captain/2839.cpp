#include <cstdio>

using namespace std;

int main() {
  int n, q, temp, cnt = -1;
  scanf("%d", &n);
  q = n / 5;
  for (int i = q; i >= 0; i--) {
    temp = n - 5 * i;
    if (temp % 3 == 0) {
      cnt = i + temp / 3;
      break;
    } 
  }
  printf("%d\n", cnt);
}
