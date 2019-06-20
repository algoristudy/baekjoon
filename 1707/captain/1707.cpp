#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

char nodeColor[20001];
vector<int> V[20001];
bool result;

int main() {
  int k, v, e;
  scanf("%d", &k);
  while (k--) {
    scanf("%d %d", &v, &e);
    // 초기화
    result = true;
    for (int i = 1; i <= v; i++) {
      nodeColor[i] = 0;
      V[i].clear();
    }
    while (e--) {
      int a, b;
      scanf("%d %d", &a, &b);
      V[a].push_back(b);
      V[b].push_back(a);
    }
    
    for (int i = 1; i <= v && result; i++) {
      if (nodeColor[i] == 0) {
        queue<pair<int, int>> q;
        nodeColor[i] = 1; 
        q.push({i, 1}); // index, color : -1, 0, 1
        while(!q.empty() && result) {
          pair<int, int> node = q.front();
          q.pop();
          for (int j = 0; j < V[node.first].size(); j++) {
            int target = V[node.first][j];
            if (nodeColor[target] == 0) {
              nodeColor[target] = node.second * -1;
              q.push({target, node.second * -1});
            } else if (nodeColor[target] == node.second) {
              result = false;
              break;
            }
          }
        }
      }
    }
    

    printf("%s\n", result ? "YES" : "NO");
  }
  
  return 0;
}