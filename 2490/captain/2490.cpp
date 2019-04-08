#include <cstdio>

using namespace std;

int main() {
  int cnt, n, m = 3;
  char result[] = {'E', 'A', 'B', 'C', 'D'};
  while (m--) {
    cnt = 0;
    for (int i = 0; i < 4; i++) {
      scanf("%d", &n);
      if (n == 0) cnt++;
    }
    printf("%c\n", result[cnt]);
  }
}
