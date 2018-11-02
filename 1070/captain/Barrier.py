#-*-coding utf-8-*-

class Barrier():
    def __init__(self, N, M, plane, height):
        self.N = N
        self.M = M
        self.plane = plane
        self.height = height
        self.minCount = 1     # 장벽을 놓는 최소 개수
        self.minHeight = -1   # 장벽들의 합
        self.findCaptital()   # 수도의 위치
        self.initPositions()  # 장벽을 놓아야 하는 위치
        self.initTestPlane()  # 테스트를 할 판을 초기화 함
        self.sucess = False   # 방어에 성공한 경우 True

    def findCaptital(self):
        # 수도의 위치를 찾아서 x, y에 입력
        for y in range(N):
            for x in range(M):
                if self.plane[y][x] == '*':
                    self.x = x
                    self.y = y
                    return
    
    def initPositions(self):
        # 장벽을 쌓을 위치를 확인
        self.positions = []   # 장벽을 놓을 위치
        for y in range(N):
            for x in range(M):
                if self.plane[y][x] == '-' or self.plane[y][x] == '*':
                    temp.append(self.plane[y][x])
                else:
                    self.positions.append([x, y])
        # print(self.positions)
    
    def initTestPlane(self):
        self.testPlane = []
        for y in range(N):
            temp = []
            for x in range(M):
                if self.plane[y][x] == '-':
                    temp.append('-')
                else:
                    temp.append('')
            self.testPlane.append(temp)
        # for plane in self.testPlane:
        #     print(plane)

    def setTestPlane(self, barriers):
        for barrier in barriers:
            self.testPlane[barrier[1]][barrier[0]] = '-'
        # for plane in self.testPlane:
        #     print(plane)
        
    def move(self, x, y):
        # x, y 이동해야 하는 값, 초기값은 수도의 위치
        # print('x : ', x, ', y : ', y)
        if self.testPlane[y][x] == '-':
            return True
        # 경계에 도착한 경우, 즉 외부에서 침입이 가능한 경우
        elif x == 0 or x == M - 1 or y == 0 or y == N - 1:
            return False  # 실패의 False를 보냄
        else:
            self.testPlane[y][x] = '-'
            # print('x : ', x, ', y : ', y)
            # for plane in self.testPlane:
            #     print(plane)
            # 위쪽 방향으로 이동
            if not self.move(x, y - 1):
                return False
            # 우측 방향으로 이동
            if not self.move(x + 1, y):
                return False
            # 아래 방향으로 이동
            if not self.move(x, y + 1):
                return False
            # 좌측 방향으로 이동
            if not self.move(x - 1, y):
                return False
        return True

    def setBarrierHeight(self, barriers):
        height = 0
        for barrier in barriers:
            index = ord(self.plane[barrier[1]][barrier[0]]) - 65
            height += self.height[index]
        if self.minHeight < 0:
            self.minHeight = height
            # print(self.minHeight)
        elif height < self.minHeight:
            self.minHeight = height
            # print(self.minHeight)

    def test(self, barriers):
        self.initTestPlane()
        self.setTestPlane(barriers)
        if self.move(self.x, self.y):
            # print(barriers)
            # 방어에 성공한 경우
            if not self.sucess:
                self.sucess = True
            # 장벽의 높이를 계산하는 로직
            self.setBarrierHeight(barriers)

    def getHeight(self):
        return self.minHeight

    def verify(self):
        barriers = []
        for i in range(4):
            barriers.append([])
            for j in range(len(self.positions) - i):
                barriers[0] = self.positions[j]
                if i == 0:
                    # print(barrier)
                    self.test(barriers)
                    continue
                if self.sucess:
                    break
                for k in range(j + 1, len(self.positions) - i + 1):
                    barriers[1] = self.positions[k]
                    if i == 1:
                        # print(barrier)
                        self.test(barriers)
                        continue
                    if self.sucess:
                        break
                    for l in range(k + 1, len(self.positions) - i + 2):
                        barriers[2] = self.positions[l]
                        if i == 2:
                            # print(barrier)
                            self.test(barriers)
                            continue
                        if self.sucess:
                            break
                        for m in range(l + 1, len(self.positions) - i + 3):
                            barriers[3] = self.positions[m]
                            # print(barrier)
                            self.test(barriers)


if __name__=='__main__':
    with open('../input.txt', 'r') as f:
        testNum = int(f.readline())
        for _ in range(testNum):
            N, M = map(int, f.readline().strip().split(' '))
            plane = []
            for _ in range(N):
                temp = []
                line = f.readline()
                for i in range(M):
                    temp.append(line[i])
                plane.append(temp)
            height = list(map(int, f.readline().strip().split(' ')))
            barrier = Barrier(N, M, plane, height)
            barrier.verify()
            print(barrier.getHeight())
