#include <cstdio>
#include <vector>
#include <algorithm> 
using namespace std;

vector<int> input(49);
int value[6];
int k, s;
void bfs(int index, int start) {
  if (index == 6) {
    for (int i = 0; i < 6; i++) {
      printf("%d ", value[i]);
    }
    printf("\n");
  } else {
    for (int i = start; i <= k - 6 + index; i++) {
      value[index] = input[i];
      bfs(index + 1, i + 1);
    }
  }
}

int main() {
  while (true) {
    scanf("%d ", &k);
    input.resize(k);
    if (k == 0) break;
    for (int i = 0; i < k; i++) {
      scanf(" %d", &input[i]);
    }
    sort(input.begin(), input.end());
    // 화면 출력
    bfs(0, 0);
    // 한줄 띄우기
    printf("\n");
  }
  return 0;
}