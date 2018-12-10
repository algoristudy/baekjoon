# 1726번 문제
# M = 세로, N = 가로
# 동 : 1, 서 : 2, 남 : 3, 북 : 4
import queue as Queue

dx = (1, 0, -1, 0)  # 동 -> 북 -> 서 -> 남
dy = (0, -1, 0, 1)
M = N = None
goal = []
direct = 0
queue = Queue.Queue()

def bfs(count = 1):
    curState = queue.get()
    x = curState[0]
    y = curState[1]
    i = curState[2]
    cnt = curState[3]
    if x == goal[1] - 1 and y == goal[0] - 1:
        if i == changeDirect(goal[2]):
            print(board[y][x])
        else:
            print(board[y][x] + 1)
    if count:
        count = board[y][x]
    for j in range(4):
        if -1 < x + dx[i] < N and -1 < y + dy[i] < M and board[y + dy[i]][x + dx[i]] == 0:
            if j == 0:
                if cnt == 3:
                    board[y + dy[i]][x + dx[i]] = count + 2
                    queue.put([x + dx[i], y + dy[i], i, 1])
                elif cnt == 0:
                    board[y + dy[i]][x + dx[i]] = count + 1
                    queue.put([x + dx[i], y + dy[i], i, cnt + 1])
                else:
                    board[y + dy[i]][x + dx[i]] = count
                    queue.put([x + dx[i], y + dy[i], i, cnt + 1])
            elif j == 2:
                board[y + dy[i]][x + dx[i]] = count + 3
                queue.put([x + dx[i], y + dy[i], i, 1])
            else:
                board[y + dy[i]][x + dx[i]] = count + 2
                queue.put([x + dx[i], y + dy[i], i, 1])
        i = i - 1 if i > -1 else 3

def changeDirect(direct):
    if direct == 2 or direct == 3:
        return direct
    elif direct == 1:
        return 0
    elif direct == 4:
        return 1

if __name__=='__main__':
    with open('../input.txt', 'r') as f:
        M, N = map(int, f.readline().strip().split(' '))
        board = []
        for _ in range(M):
            board.append(list(map(int, f.readline().strip().split(' '))))
        start = list(map(int, f.readline().strip().split(' ')))
        goal = list(map(int, f.readline().strip().split(' ')))
        board[start[0] - 1][start[1] - 1] = -1
        queue.put([start[1] - 1, start[0] - 1, changeDirect(start[2]), 0])
        bfs(0)
        while not queue.empty():
            bfs()
            # print('')
            # for b in board:
            #     print(b)