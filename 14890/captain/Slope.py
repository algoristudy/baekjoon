class Slope():
    def __init__(self, size, length, plane):
        self.size = size
        self.length = length
        self.plane = plane
        self.street = []
        self.count = 0
        self.slope = []
        for _ in range(self.size):
            self.slope.append(0)
            self.street.append(0)

    def initSlope(self):
        for i in range(self.size):
            self.slope[i] = 0

    def verify(self):
        for i in range(self.size):
            self.setStreet('row', i)
            self.initSlope()
            self.count += self.verifyStreet()

        for i in range(self.size):
            self.setStreet('col', i)
            self.initSlope()
            self.count += self.verifyStreet()

    def getCount(self):
        return self.count

    def setStreet(self, direction, index):
        if direction == 'row':
            for i in range(self.size):
                self.street[i] = self.plane[index][i]
        else:
            for i in range(self.size):
                self.street[i] = self.plane[i][index]

    def verifyStreet(self):
        for i in range(self.size - 1):
            # 경사로를 놓치 않아도 되는 경우
            if self.street[i] == self.street[i + 1]:
                continue
            # 한칸 내려가서 우측에 경사로를 놓을 경우
            elif self.street[i] - self.street[i + 1] == 1:
                # 범위를 벗어 나는 경우
                if i + self.length >= self.size:
                    return 0
                # 슬로프 구간에 높낮이가 변하는 경우
                for j in range(i + 1, i + self.length):
                    if not self.street[j] == self.street[j + 1]:
                        return 0
                for j in range(i + 1, i + self.length + 1):
                    self.slope[j] = 1
            # 한칸 올라가서 좌측에 경사로를 놓을 경우
            elif self.street[i] - self.street[i + 1] == -1:
                # 범위를 벗어나는 경우
                if i - self.length + 1 < 0:
                    return 0
                elif not self.slope[i - self.length + 1] == 0:
                    return 0
                for j in range(i - self.length + 1, i + 1):
                    self.slope[j] = 1
            else:
                return 0
        return 1


if __name__ == '__main__':
    size, length = map(int, input().strip().split(' '))
    plane = []
    for _ in range(size):
        plane.append(list(map(int, input().strip().split(' '))))
    slope = Slope(size, length, plane)
    slope.verify()
    print(slope.getCount())