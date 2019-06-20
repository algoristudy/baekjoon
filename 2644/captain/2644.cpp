#include <cstdio>
#include <queue>
using namespace std;

static int INF = 999999;
int dist[102];
bool link[102][102];

int main() {
  int personCount, caseCount, person1, person2, parent, child;
  scanf("%d %d %d %d", &personCount, &person1, &person2, &caseCount);
  for (int i = 1; i <= personCount; i++) {
    dist[i] = INF;
    for (int j = 1; j <= personCount; j++) link[i][j] = false; 
  }
  while(caseCount--) {
    scanf("%d %d", &parent, &child);
    link[parent][child] = true;
    link[child][parent] = true;
  }
  queue<pair<int, int>> q;
  dist[person1] = 0;
  q.push({person1, 0});
  while (!q.empty()) {
    pair<int, int> person = q.front();
    q.pop();
    for (int i = 1; i <= personCount; i++) {
      if (link[person.first][i] && dist[i] > person.second + 1) {
        dist[i] = person.second + 1;
        if (i == person2) break;
        q.push({i, person.second + 1});
      }
    }
  }
  printf("%d\n", dist[person2] == INF ? -1 : dist[person2]);
  return 0;
}