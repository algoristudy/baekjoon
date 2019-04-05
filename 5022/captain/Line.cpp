#include <cstdio>
#include <queue>
using namespace std;

int const MAX_SIZE = 101;
int const dx[] = {-1, 1, 0, 0};
int const dy[] = {0, 0, -1, 1};

struct pos {
    int x;
    int y;
    int cnt;
};

int n, m; // 높이 n, 너비 m
pos A1, A2, B1, B2;
bool board[MAX_SIZE][MAX_SIZE];
int minCount = 0;
queue<pos> q;

void initBoard() {
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            board[j][i] = false;
        }
    }
}

void getCount(pos A1, pos A2, pos B1, pos B2) {
    int x1 = A1.x, y1 = A1.y, x2 = A2.x, y2 = A2.y;
    int nx, ny;
    for (int i = 0; i < 2; i++) {
        initBoard();
        int count = 0;
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        count += x2 - x1;
        count += y2 - y1;
        if (i == 0) {
            // x축 먼저
            for (int i = x1; i <= x2; i++) board[y1][i] = true;
            for (int i = y1; i <= y2; i++) board[i][x2] = true;
        } else {
            // y축 먼저
            for (int i = y1; i <= y2; i++) board[i][x1] = true;
            for (int i = x1; i <= x2; i++) board[y2][i] = true;
        }
        while (!q.empty()) q.pop();
        q.push(pos({B1.x, B1.y, 0}));
        while (!q.empty()) {
            pos cur = q.front();
            q.pop();
            if (cur.x == B2.x && cur.y == B2.y) {
                count += cur.cnt;
                if (minCount == 0 || count < minCount) {
                    minCount = count;
                }
                break;
            }
            for (int i = 0; i < 4; i++) {
                nx = cur.x + dx[i];
                ny = cur.y + dy[i];
                if (nx > -1 && nx <= m && ny > -1 && ny <= n && !board[ny][nx]) {
                    board[ny][nx] = true;
                    q.push(pos({nx, ny, cur.cnt + 1}));
                }
            }
        }

        printf("\n\n");
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                printf("%3d ", board[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    scanf("%d %d", &A1.x, &A1.y);
    scanf("%d %d", &A2.x, &A2.y);
    scanf("%d %d", &B1.x, &B1.y);
    scanf("%d %d", &B2.x, &B2.y);

    getCount(A1, A2, B1, B2);
    getCount(B1, B2, A1, A2);

    if (minCount) {
        printf("%d\n", minCount);
    } else {
        printf("IMPOSSIBLE\n");
    }
    
    return 0;
}