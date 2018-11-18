class CabbageWorm():
    def __init__(self, M, N, plane):
        self.M = M
        self.N = N
        self.plane = plane
        self.wormCount = 0
        self.stack = []
        
    def verify(self):
        # 검증
        for y in range(self.N):
            for x in range(self.M):
                if self.plane[y][x] == 1:
                    self.wormCount += 1
                    self.stack.append([x, y])
                    while self.stack:
                        self.move()

    def move(self):
        x = self.stack[-1:][0][0]
        y = self.stack[-1:][0][1]
        if not self.plane[y][x] == 0:
            self.plane[y][x] = 0
        # 위쪽으로 이동할 수 있는 경우 이동
        if not y - 1 < 0 and self.plane[y - 1][x] != 0:
            self.stack.append([x, y - 1])
        # 왼쪽으로 이동할 수 있는 경우 이동
        elif not x - 1 < 0 and self.plane[y][x - 1] != 0:
            self.stack.append([x - 1, y])
        # 아래쪽으로 이동할 수 있는 경우 이동
        elif not y + 1 == N and self.plane[y + 1][x] != 0:
            self.stack.append([x, y + 1])
        # 오른쪽으로 이동할 수 있는 경우 이동
        elif not x + 1 == M and self.plane[y][x + 1] != 0:
            self.stack.append([x + 1, y])
        else:
            self.stack.pop()
    
    def getWormCount(self):
        return self.wormCount

if __name__=='__main__':
    with open('../input.txt', 'r') as f:
        testNum = int(f.readline())
        for _ in range(testNum):
            # print('')
            M, N, count = map(int, f.readline().strip().split(' '))
            plane = []
            for _ in range(N):
                plane.append([0] * M)
            for _ in range(count):
                x, y = map(int, f.readline().strip().split(' '))
                plane[y][x] = 1
            cabbageWorm = CabbageWorm(M, N, plane)
            cabbageWorm.verify()
            print(cabbageWorm.getWormCount())
            