import sys
class Path():
    def __init__(self):
        self.V, self.E = map(int, sys.stdin.readline().strip().split(' '))
        self.start = int(sys.stdin.readline()) - 1
        self.cases = [[0] * 3 for _ in range(self.E)]
        for i in range(self.E):
            self.cases[i][0], self.cases[i][1], self.cases[i][2] = map(int, sys.stdin.readline().strip().split(' '))
        self.stack = []
        self.path = [[11] * self.V for _ in range(self.V)]
        for i in range(self.V):
            self.path[i][i] = 0
        for case in self.cases:
            start = case[0] - 1
            end = case[1] - 1
            weight = case[2]
            if self.path[start][end] > weight:
                self.stack.append([start, end, weight])
                while self.stack:
                    self.setPath()

    def setPath(self):
        start = self.stack[-1][0]
        end = self.stack[-1][1]
        weight = self.stack[-1][2]
        self.path[start][end] = weight
        for i in range(self.V):
            if self.path[i][start] > 0 and self.path[i][start] + weight < self.path[i][end]:
                self.stack.append([i, end, self.path[i][start] + weight])
                return
        self.stack.pop()
    
    def printResult(self):
        for i in range(self.V):
            if self.path[self.start][i] == 11:
                print('INF')
            else:
                print(self.path[self.start][i])

if __name__=='__main__':
    path = Path()
    path.printResult()
        