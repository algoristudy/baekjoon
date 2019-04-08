#include<cstdio>
#include<algorithm>
 
using namespace std;

int n;
int house_cost[1000][3];
int result[1000][3];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 3; j++)
      scanf("%d", &house_cost[i][j]);
  for (int i = 0; i < 3; i++) result[0][i] = house_cost[0][i];
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      if (j == 0) result[i][j] = house_cost[i][j] + min(result[i - 1][1], result[i - 1][2]);
      else if (j == 1) result[i][j] = house_cost[i][j] + min(result[i - 1][0], result[i - 1][2]);
      else if (j == 2) result[i][j] = house_cost[i][j] + min(result[i - 1][0], result[i - 1][1]);
    }
  }
  n--;
  int answer = result[n][0] < result[n][1] ? min(result[n][0], result[n][2]) : min(result[n][1], result[n][2]);
  printf("%d\n", answer);
  return 0;
}