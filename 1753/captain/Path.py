class Path():
    def __init__(self, V, E, start, cases):
        self.V = V                  # V : 정점 개수
        self.E = E                  # E : 간선 개수
        self.start = start - 1      # start : 시작점
        self.cases = cases          # cases : 이동 경로
        self.path = [[-1] * self.V for _ in range(self.V)]
        for i in range(self.V):
            self.path[i][i] = 0
        for case in self.cases:
            print('\n case : ', case)
            start = case[0] - 1
            end = case[1] - 1
            value = case[2]
            if self.path[start][end] == -1 or self.path[start][end] > value:
                self.setPath(case[0] - 1, case[1] - 1, value)
            for path in self.path:
                print(path)

    def setPath(self, start, end, value):
        # print('setPath, start : ', start, ', end  : ', end, ', value : ', value)
        self.path[start][end] = value
        for i in range(self.V):
            if self.path[i][start] > 0 and (self.path[i][end] == -1 or self.path[i][start] + value < self.path[i][end]):
                self.setPath(i, end, self.path[i][start] + value)
    
    def printResult(self):
        for i in range(self.V):
            if self.path[self.start][i] == -1:
                print('INF')
            else:
                print(self.path[self.start][i])

if __name__=='__main__':
    with open('../input.txt', 'r') as f:
        V, E = map(int, f.readline().strip().split(' '))
        start = int(f.readline())
        cases = []
        for _ in range(E):
            cases.append(list(map(int, f.readline().strip().split(' '))))
        path = Path(V, E, start, cases)
        path.printResult()
        