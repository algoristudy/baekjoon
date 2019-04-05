#include <cstdio>
#include <queue>
using namespace std;

int const MAX_SIZE = 101;
int const direct[] = {0, 1, 3, 2, 0};
int const dx[] = {0, 1, 0, -1};
int const dy[] = {-1, 0, 1, 0};

struct pos {
    int x; // x 좌표
    int y; // y 좌표
    int d; // 방향
    int cnt; // 명령 횟수
};

int m, n; // 세로 길이, 가로 길이 
int board[MAX_SIZE][MAX_SIZE];
int minCount[MAX_SIZE][MAX_SIZE][4];
pos start, goal;
queue<pos> q;

int change(int d) {
    return direct[d];
}

void bfs() {
    while (!q.empty()) {
        pos cur = q.front();
        // printf("x: %d, y: %d, d: %d, cnt: %d\n", cur.x, cur.y, cur.d, cur.cnt);
        q.pop();
        int nx, ny, nd;
        // 직진
        for (int i = 1; i < 4; i++) {
            nx = cur.x + dx[cur.d] * i;
            ny = cur.y + dy[cur.d] * i;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[ny][nx] == 1) break;
            if (minCount[ny][nx][cur.d] == -1 || minCount[ny][nx][cur.d] > cur.cnt + 1) {
                minCount[ny][nx][cur.d] = cur.cnt + 1;
                q.push(pos({nx, ny, cur.d, cur.cnt + 1}));
            }
        }
        // 우로 회전
        nd = cur.d == 3 ? cur.d - 3 : cur.d + 1;
        if (minCount[cur.y][cur.x][nd] == -1 || minCount[cur.y][cur.x][nd] > cur.cnt + 1) {
            minCount[cur.y][cur.x][nd] = cur.cnt + 1;
            q.push(pos({cur.x, cur.y, nd, cur.cnt + 1}));
        }
        // 좌로 회전
        nd = cur.d == 0 ? cur.d + 3 : cur.d - 1;
        if (minCount[cur.y][cur.x][nd] == -1 || minCount[cur.y][cur.x][nd] > cur.cnt + 1) {
            minCount[cur.y][cur.x][nd] = cur.cnt + 1;
            q.push(pos({cur.x, cur.y, nd, cur.cnt + 1}));
        }
        // for (int i = 0; i < 5; i++) {
        //     for (int j = 0; j < 4; j++) {
        //         for (int k = 0; k < 6; k++) {
        //             printf("%3d ", minCount[i][k][j]);
        //         }
        //         printf("   ");
        //     }
        //     printf("\n");
        // }
    }
}

int main() {
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &board[i][j]);
            for (int k = 0; k < 4; k++) {
                minCount[i][j][k] = -1;
            }
        }
    }
    scanf("%d %d %d", &start.y, &start.x, &start.d);
    scanf("%d %d %d", &goal.y, &goal.x, &goal.d);
    start.d = change(start.d);
    goal.d = change(goal.d);
    minCount[start.y - 1][start.x - 1][start.d] = 0;
    q.push(pos({start.x - 1, start.y - 1, start.d, 0}));
    bfs();
    printf("%d\n", minCount[goal.y - 1][goal.x - 1][goal.d]);
    return 0;
}