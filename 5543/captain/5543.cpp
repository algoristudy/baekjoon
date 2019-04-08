#include <cstdio>

using namespace std;

int main() {
  int m1 = 2000, m2 = 2000, m;
  for (int i = 0; i < 3; i++) {
    scanf("%d", &m);
    if (m < m1) m1 = m;
  }
  for (int i = 0; i < 2; i++) {
    scanf("%d", &m);
    if (m < m2) m2 = m;
  }
  printf("%d\n", m1 + m2 - 50);
  return 0;
}
