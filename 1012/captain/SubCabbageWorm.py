class CabbageWorm():
    def __init__(self, M, N, plane):
        self.M = M
        self.N = N
        self.plane = plane
        self.wormCount = 0
        self.queue = []
        
    def verify(self):
        # 검증
        for y in range(self.N):
            for x in range(self.M):
                if self.plane[y][x] == 1:
                    self.wormCount += 1
                    self.queue.append([x, y])
                    while self.queue:
                        self.move()

    def move(self):
        x = self.queue[-1:][0][0]
        y = self.queue[-1:][0][1]
        if not self.plane[y][x] == 0:
            self.plane[y][x] = 0
        # 위쪽으로 이동할 수 있는 경우 이동
        if not y - 1 < 0 and self.plane[y - 1][x] != 0:
            self.queue.append([x, y - 1])
            return
        # 왼쪽으로 이동할 수 있는 경우 이동
        if not x - 1 < 0 and self.plane[y][x - 1] != 0:
            self.queue.append([x - 1, y])
            return
        # 아래쪽으로 이동할 수 있는 경우 이동
        if not y + 1 == N and self.plane[y + 1][x] != 0:
            self.queue.append([x, y + 1])
            return
        # 오른쪽으로 이동할 수 있는 경우 이동
        if not x + 1 == M and self.plane[y][x + 1] != 0:
            self.queue.append([x + 1, y])
            return
        self.queue.pop()
    
    def getWormCount(self):
        return self.wormCount

if __name__=='__main__':
    testNum = int(input())
    results = []
    for _ in range(testNum):
        M, N, count = map(int, input().split(' '))
        plane = []
        for _ in range(N):
            plane.append([0] * M)
        for _ in range(count):
            x, y = map(int, input().split(' '))
            plane[y][x] = 1
        cabbageWorm = CabbageWorm(M, N, plane)
        cabbageWorm.verify()
        results.append(cabbageWorm.getWormCount())
    for result in results:
        print(result)