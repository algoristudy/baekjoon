import sys

class EASY2048():
    def __init__(self, N, plane):
        self.N = N
        self.plane = plane
        self.temp = []
        for _ in range(self.N):
            self.temp.append([0] * self.N)
        self.max = 0
        self.direct = [0, 0, 0, 0, 0]
        self.play()
        for i in range(4):
            self.direct[0] = i
            for j in range(4):
                self.direct[1] = j
                for k in range(4):
                    self.direct[2] = k
                    for l in range(4):
                        self.direct[3] = l
                        for m in range(4):
                            self.direct[4] = m
                            self.play()

    def play(self):
        for i in range(N):
            for j in range(N):
                self.temp[i][j] = plane[i][j]
        for direct in self.direct:
            if direct == 0:
                for j in range(self.N):
                    moveIndex = 0
                    for i in range(1, self.N):
                        if self.temp[i][j] != 0:
                            # 이동할 경우
                            if self.temp[moveIndex][j] == 0:
                                self.temp[moveIndex][j] = self.temp[i][j]
                                self.temp[i][j] = 0
                            # 숫자가 있을 경우 합쳐지거나 다음칸 이동
                            elif self.temp[moveIndex][j] == self.temp[i][j]:
                                self.temp[moveIndex][j] *= 2
                                self.temp[i][j] = 0
                                moveIndex += 1
                            else:
                                moveIndex += 1
                                if moveIndex != i:
                                    self.temp[moveIndex][j] = self.temp[i][j]
                                    self.temp[i][j] = 0
            elif direct == 1:
                for i in range(self.N):
                    moveIndex = self.N - 1
                    for j in range(self.N -2, -1, -1):
                        if self.temp[i][j] != 0:
                            if self.temp[i][moveIndex] == 0:
                                self.temp[i][moveIndex] = self.temp[i][j]
                                self.temp[i][j] = 0
                            elif self.temp[i][moveIndex] == self.temp[i][j]:
                                self.temp[i][moveIndex] *= 2
                                self.temp[i][j] = 0
                                moveIndex -= 1
                            else:
                                moveIndex -= 1
                                if moveIndex != j:
                                    self.temp[i][moveIndex] = self.temp[i][j]
                                    self.temp[i][j] = 0
            elif direct == 2:
                for j in range(self.N):
                    moveIndex = self.N - 1
                    for i in range(self.N - 2, -1, -1):
                        if self.temp[i][j] != 0:
                            if self.temp[moveIndex][j] == 0:
                                self.temp[moveIndex][j] = self.temp[i][j]
                                self.temp[i][j] = 0
                            elif self.temp[moveIndex][j] == self.temp[i][j]:
                                self.temp[moveIndex][j] *= 2
                                self.temp[i][j] = 0
                                moveIndex -= 1
                            else:
                                moveIndex -= 1
                                if moveIndex != i:
                                    self.temp[moveIndex][j] = self.temp[i][j]
                                    self.temp[i][j] = 0

            elif direct == 3:
                for i in range(self.N):
                    moveIndex = 0
                    for j in range(1, self.N):
                        if self.temp[i][j] != 0:
                            if self.temp[i][moveIndex] == 0:
                                self.temp[i][moveIndex] = self.temp[i][j]
                                self.temp[i][j] = 0
                            elif self.temp[i][moveIndex] == self.temp[i][j]:
                                self.temp[i][moveIndex] *= 2
                                self.temp[i][j] = 0
                                moveIndex += 1
                            else:
                                moveIndex += 1
                                if moveIndex != j:
                                    self.temp[i][moveIndex] = self.temp[i][j]
                                    self.temp[i][j] = 0
        max = 0
        for i in range(self.N):
            for j in range(self.N):
                if self.temp[i][j] > max:
                    max = self.temp[i][j]
        if max > self.max:
            self.max = max
    
    def getMax(self):
        return self.max

if __name__=='__main__':
    N = int(sys.stdin.readline())
    plane = []
    for _ in range(N):
        plane.append(list(map(int, sys.stdin.readline().strip().split(' '))))
    easy2048 = EASY2048(N, plane)
    print(easy2048.getMax())