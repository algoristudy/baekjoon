import queue as Queue
# 동 : 1, 서 : 2, 남 : 3, 북 : 4
dx = (1, 0, -1, 0)  # 동 -> 북 -> 서 -> 남
dy = (0, -1, 0, 1)

def bfs():
    current = queue.get()
    count = current[0]
    x = current[1]
    y = current[2]
    d = current[3]
    print('\ncount : {0}, x : {1}, y : {2}, d: {3}'.format(count, x, y, d))
    if x == gx and y == gy:
        print(count if d == gd else count + 1)
        while not queue.empty():
            queue.get()
        return
    # 직진
    for i in range(1, 4):
        nx = x + dx[d] * i
        ny = y + dy[d] * i
        if -1 < nx < N and -1 < ny < M and (board[ny][nx] == 0 or board[ny][nx] > count + 1):
            board[ny][nx] = count + 1
            queue.put([count + 1, nx, ny, d])
    
    # left 회전 d + 1 
    nd = d + 1 if d < 3 else 0
    nx = x + dx[nd]
    ny = y + dy[nd]
    if -1 < nx < N and -1 < ny < M and (board[ny][nx] == 0 or board[ny][nx] > count + 2):
        queue.put([count + 1, x, y, nd])
    
    # right 회전 d - 1
    nd = d - 1 if d > 0 else 3
    nx = x + dx[nd]
    ny = y + dy[nd]
    if -1 < nx < N and -1 < ny < M and (board[ny][nx] == 0 or board[ny][nx] > count + 2):
        queue.put([count + 1, x, y, nd])


def direct(d):
    if d == 2 or d == 3:
        return d
    elif d == 1:
        return 0
    elif d == 4:
        return 1

if __name__=='__main__':
    with open('../input.txt', 'r') as f:
        M, N = map(int, f.readline().strip().split(' '))
        board = []
        for _ in range(M):
            board.append(list(map(int, f.readline().strip().split(' '))))
        start = list(map(int, f.readline().strip().split(' ')))
        goal = list(map(int, f.readline().strip().split(' ')))
        gx = goal[1] - 1
        gy = goal[0] - 1
        gd = direct(goal[2])
        board[start[0] - 1][start[1] - 1] = -1
        queue = Queue.PriorityQueue()
        queue.put([0, start[1] - 1, start[0] - 1, direct(start[2])])
        while not queue.empty():
            bfs()
            for b in board:
                print(b)