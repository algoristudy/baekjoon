# 2178번 문제
import queue as Queue

class Maze():
    def __init__(self, N, M, board):
        self.N = N
        self.M = M
        self.board = board
        self.dirX = [-1, 0, 1, 0]
        self.dirY = [0, -1, 0, 1]
        self.x = 0
        self.y = 0
        self.board[self.x][self.y] = 1
        self.queue = Queue.Queue(10000)
        self.queue.put([0, 0])
        while not self.queue.empty():
            self.setCount()
        print(self.board[self.N - 1][self.M - 1])
        for board in self.board:
            print(board)
        
    def setCount(self):
        position = self.queue.get()
        self.x = position[0]
        self.y = position[1]
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
            maxNum = N * M
            board = [[0] * M for _ in range(N)]
            for y in range(N):
                temp = f.readline()
                for x in range(M):
                    if temp[x] == '1':
                        board[y][x] = maxNum
            maze = Maze(N, M, board)
            