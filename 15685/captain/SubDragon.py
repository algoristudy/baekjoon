import sys

class DragonCurve():
    def __init__(self):
        self.plane = []
        for _ in range(101):
            self.plane.append([0] * 101)
        self.count = 0

    def setDragon(self, x, y, d, g):
        # d : 동(0), 북(1), 서(2), 남(3)
        stack = [d]
        self.plane[y][x] = 1
        for i in range(g + 1):
            index = int(2 ** (i - 1))
            for j in range(index, len(stack)):
                if stack[j] == 0:
                    x += 1
                elif stack[j] == 1:
                    y -= 1
                elif stack[j] == 2:
                    x -= 1
                else:
                    y += 1
                self.plane[y][x] = 1
            for j in range(len(stack) - 1, -1, -1):
                d = stack[j] + 1
                if d == 4:
                    d =0
                stack.append(d)
    
    def getCount(self):
        for y in range(100):
            for x in range(100):
                if self.plane[y][x] == 1:
                    if self.plane[y + 1][x] and self.plane[y][x + 1] and self.plane[y + 1][x + 1]:
                        self.count += 1
        return self.count

if __name__=='__main__':
    dragonCurve = DragonCurve()
    N = int(sys.stdin.readline())
    for _ in range(N):
        x, y, d, g = map(int, sys.stdin.readline().strip().split(' '))
        dragonCurve.setDragon(x, y, d, g)
    print(dragonCurve.getCount())