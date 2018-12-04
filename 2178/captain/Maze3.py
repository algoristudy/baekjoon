import sys
import queue as Queue

def maze():
    N, M = map(int, sys.stdin.readline().split())
    board = [[0] * M for _ in range(N)]
    for y in range(N):
        temp = sys.stdin.readline()
        for x in range(M):
            board[y][x] = int(temp[x])
    visit = [[0] * M for _ in range(N)]
    queue = Queue.Queue()
    dirX = (-1, 0, 1, 0)
    dirY = (0, -1, 0, 1)
    visit[0][0] = 1
    queue.put([0, 0])
    while not queue.empty():
        x, y = queue.get()
        for i in range(4):
            nextX = x + dirX[i]
            nextY = y + dirY[i]
            if -1 < nextX < M and -1 < nextY < N:
                if not visit[nextY][nextX] and board[nextY][nextX]:
                    visit[nextY][nextX] = visit[y][x] + 1
                    queue.put([nextX, nextY])
    return visit[N - 1][M - 1]

if __name__=='__main__':
    print(maze())