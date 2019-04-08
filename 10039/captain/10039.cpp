#include <cstdio>
using namespace std;
int main() {
  int score, total = 0;
  for (int i = 0; i < 5; i++) {
    scanf("%d", &score);
    total += score < 40 ? 40 : score;
  }
  printf("%d\n", total / 5);
}
