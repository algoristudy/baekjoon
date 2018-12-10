#include <iostream>

#include <queue>

#include <algorithm>

using namespace std;

 

const int MAX = 200;

 

typedef struct

{

        int y, x;

}Dir;

 

//정상적인 상하좌우

Dir moveDir[4] = { { 1, 0 },{ -1, 0 },{ 0, 1 },{ 0, -1 } };

//말의 움직임

Dir knightDir[8] = { { -1, -2 },{ -2, -1 },{ -2, 1 },{ -1, 2 },{ 2, 1 },{ 1, 2 },{ 2, -1 },{ 1, -2 } };

 

int K, W, H;

int board[MAX][MAX];

bool visited[MAX][MAX][30 + 2];

 

int BFS(int y, int x)

{

        queue < pair<pair<int, int>, pair<int, int>>> q; //y, x, K, cnt

        q.push(make_pair(make_pair(y, x), make_pair(0, 0)));

        visited[y][x][0] = 1;

 

        while (!q.empty())

        {

                 int curY = q.front().first.first;

                 int curX = q.front().first.second;

                 int knight = q.front().second.first;

                 int cnt = q.front().second.second;

                 q.pop();

 

                 if (curY == H - 1 && curX == W - 1)

                         return cnt;

 

                 //아직 능력을 쓸 수 있다면

                 if (knight < K)

                 {

                         for (int i = 0; i < 8; i++)

                         {

                                 int nextY = curY + knightDir[i].y;

                                 int nextX = curX + knightDir[i].x;

 

                                 if (0 <= nextY && nextY < H && 0 <= nextX && nextX < W)

                                          if (!visited[nextY][nextX][knight + 1] && !board[nextY][nextX])

                                          {

                                                  visited[nextY][nextX][knight + 1] = true;

                                                  q.push(make_pair(make_pair(nextY, nextX), make_pair(knight + 1, cnt + 1)));

                                          }

                         }

                 }

                 //능력 사용하지 않은 경우

                 for (int i = 0; i < 4; i++)

                 {

                         int nextY = curY + moveDir[i].y;

                         int nextX = curX + moveDir[i].x;

 

                         if (0 <= nextY && nextY < H && 0 <= nextX && nextX < W)

                                 if (!visited[nextY][nextX][knight] && !board[nextY][nextX])

                                 {

                                          visited[nextY][nextX][knight] = true;

                                          q.push(make_pair(make_pair(nextY, nextX), make_pair(knight, cnt + 1)));

                                 }

                 }

        }

        return -1;

}

 

int main(void)

{

        ios_base::sync_with_stdio(0);

        cin.tie(0); //cin 실행속도 향상 위해

        cin >> K >> W >> H;

 

        for (int y = 0; y < H; y++)

                 for (int x = 0; x < W; x++)

                         cin >> board[y][x];

 

        cout << BFS(0, 0) << "\n";

        return 0;

}