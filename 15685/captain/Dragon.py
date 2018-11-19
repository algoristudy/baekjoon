class DragonCurve():
    def __init__(self):
        self.plane = []
        for _ in range(101):
            self.plane.append([0] * 101)

    def setDragon(self, x, y, d, g):
        # d : 동(0), 북(1), 서(2), 남(3)
        stack = [d]
        for _ in range(g + 1):

        

if __name__=='__main__':
    with open('../input.txt', 'r') as f:
        testNum = int(f.readline())
        for _ in range(testNum):
            dragonCurve = DragonCurve()
            N = int(f.readline())
            for _ in range(N):
                x, y, d, g = map(int, f.readline().strip().split(' '))
                dragonCurve.setDragon(x, y, d, g)
            