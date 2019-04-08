#include <cstdio>

using namespace std;

int main() {
  int cnt = 0, n, m;
  scanf("%d", &n);
  for (int i = 0; i < 5; i++) {
    scanf("%d", &m);
    if (n == m) cnt++;
  }
  printf("%d\n", cnt);
}
