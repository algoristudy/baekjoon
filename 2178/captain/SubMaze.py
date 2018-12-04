# 2178번 문제
import queue as Queue
import sys

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
        self.queue = Queue.Queue()
        self.queue.put([0, 0])
        while not self.queue.empty():
            self.setCount()
        print(self.board[self.N - 1][self.M - 1])
        
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
    N, M = map(int, sys.stdin.readline().strip().split(' '))
    maxNum = 10000
    board = [[0] * M for _ in range(N)]
    for y in range(N):
        temp = sys.stdin.readline()
        for x in range(M):
            if temp[x] == '1':
                board[y][x] = maxNum
    maze = Maze(N, M, board)