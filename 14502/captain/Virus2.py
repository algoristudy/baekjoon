class Virus():
    def __init__(self, N, M, plane):
        self.N = N    # 세로 높이 
        self.M = M    # 가로 높이
        self.plane = plane # 초기 배열
        self.initTestPlane()
        self.stack = [[0, 0]] * (self.M * self.N)
        self.stackIndex = 0
        self.count = 0
        self.maxCount = 0
        self.test()
        
    def initTestPlane(self):
        self.testPlane = []
        for y in range(N):
            temp = [0] * M
            self.testPlane.append(temp)
        self.resetTestPlane()
        self.emptyPlace = []
        self.originVirus = []
        for y in range(N):
            for x in range(M):
                if self.plane[y][x] == 0:
                    self.emptyPlace.append([x, y])
                elif self.plane[y][x] == 2:
                    self.originVirus.append([x, y])

    def resetTestPlane(self):
        # 테스트 plane을 초기화
        for y in range(N):
            for x in range(M):
                if not self.testPlane[y][x] == self.plane[y][x]:
                    self.testPlane[y][x] = self.plane[y][x]
        # for p in self.testPlane:
        #     print(p)

    def setTestPlane(self, position):
        self.testPlane[position[1]][position[0]] = 1

    def setVirus(self, x, y):
        # 북쪽방향 이동이 가능하면 이동
        if y - 1 >= 0 and self.testPlane[y - 1][x] == 0:
            self.testPlane[y - 1][x] = 2
            self.setVirus(x, y - 1)
        # 동쪽방향 이동이 가능하면 이동
        if x + 1 < self.M and self.testPlane[y][x + 1] == 0:
            self.testPlane[y][x + 1] = 2
            self.setVirus(x + 1, y)
        # 남쪽방향 이동이 가능하면 이동
        if y + 1 < self.N and self.testPlane[y + 1][x] == 0:
            self.testPlane[y + 1][x] = 2
            self.setVirus(x, y + 1)
        # 서쪽방향 이동이 가능하면 이동
        if x - 1 >= 0 and self.testPlane[y][x - 1] == 0:
            self.testPlane[y][x - 1] = 2
            self.setVirus(x - 1, y)

    def test(self):
        for i in range(len(self.emptyPlace) - 2):
            for j in range(i + 1, len(self.emptyPlace) - 1):
                for k in range(j + 1, len(self.emptyPlace)):
                    self.resetTestPlane()
                    self.setTestPlane(self.emptyPlace[i])
                    self.setTestPlane(self.emptyPlace[j])
                    self.setTestPlane(self.emptyPlace[k])
                    self.count = len(self.emptyPlace) - 3
                    # 바이러스 확산
                    for virus in self.originVirus:
                        self.setVirus(virus[0], virus[1])
                    # 카운트 계산
                    count = 0
                    for y in range(self.N):
                        for x in range(self.M):
                            if self.testPlane[y][x] == 0:
                                count += 1
                    if count > self.maxCount:
                        self.maxCount = count

    def getMaxCount(self):
        return self.maxCount
                
if __name__=='__main__':
    results = []
    with open('../input.txt', 'r') as f:
        testNum = int(f.readline())
        for _ in range(testNum):
            # N 세로 크기, M 가로 크기
            N, M = map(int, f.readline().strip().split(' '))
            plane = []
            for _ in range(N):
                plane.append(list(map(int, f.readline().strip().split(' '))))
            virus = Virus(N, M, plane)
            results.append(virus.getMaxCount())
    for result in results:
        print(result)