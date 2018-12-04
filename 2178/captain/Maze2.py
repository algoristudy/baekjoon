import queue as Queue

class Maze():
    def __init__(self, N, M, board):
        self.N = N
        self.M = M
        self.max = self.N * self.M
        self.board = [[0] * self.M for _ in range(self.N)]
        for y in range(self.N):
            for x in range(self.M):
                if board[y][x] == '1':
                    self.board[y][x] = self.max
        self.queue = Queue.Queue(self.max)
        # 시작 위치 (1, 1) => 0, 0
        self.x = 0
        self.y = 0
        self.dirX = (-1, 0, 1, 0)
        self.dirY = (0, -1, 0, 1)
        self.board[0][0] = 1
        self.queue.put([0, 0])
        while not self.queue.empty():
            self.BFS()
        print(self.board[self.N - 1][self.M - 1])
    
    def BFS(self):
        position = self.queue.get()
        self.x, self.y = position[0], position[1]
        for i in range(4):
            x = self.x + self.dirX[i]
            y = self.y + self.dirY[i]
            if -1 < x < self.M and -1 < y < self.N and self.board[y][x] > self.board[self.y][self.x]:
                self.board[y][x] = self.board[self.y][self.x] + 1
                self.queue.put([x, y])

if __name__=='__main__':
    with open('../input.txt', 'r') as f:
        testNum = int(f.readline())
        for _ in range(testNum):
            N, M = map(int, f.readline().strip().split(' '))
            board = []
            for _ in range(N):
                board.append(f.readline().strip())
            maze = Maze(N, M, board)