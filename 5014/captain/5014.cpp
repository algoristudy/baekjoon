#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

vector<bool> visit(1000001, false); 

int main() {
  int f, s, g, u, d, result = -1;
  queue<pair<int, int>> q;
  scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
  if (s == g) {
    printf("0\n");
    return 0; 
  }
  q.push({s, 0});
  visit[s] = true;
  while(!q.empty()) {
    pair<int, int> c = q.front();
    q.pop();
    int nextFloor;
    // 위쪽이 가능할 경우 추가
    nextFloor = c.first + u;
    if (nextFloor <= f && !visit[nextFloor]) {
      if (nextFloor == g) {
        result = c.second + 1;
        break; 
      }
      visit[nextFloor] = true;
      q.push({nextFloor, c.second + 1});
    }
    nextFloor = c.first - d;
    // 아래 쪽이 가능할 경우 추가
    if (nextFloor > 0 && !visit[nextFloor]) {
      if (nextFloor == g) {
        result = c.second + 1;
        break;
      }
      visit[nextFloor] = true;
      q.push({nextFloor, c.second + 1});
    }
  }

  if (result == -1) {
    printf("use the stairs\n");
  } else {
    printf("%d\n", result);
  }
  
  return 0;
}