import sys
class AcmCraft():
    def __init__(self, N, K, buildTime, forward, reserve, target):
        self.N = N
        self.K = K
        self.buildTime = buildTime
        self.times = [0] * self.N
        self.forward = forward
        self.reverse = reverse
        self.target = target
        self.useable = [0] * self.N
        self.useable[self.target - 1] = 1
        self.setForward()
        for i in range(self.N):
            if self.useable[i] == 1 and self.times[i] == 0:
                self.setTime(i, self.buildTime[i])

    def setForward(self):
        for i in range(self.target - 1, -1, -1):
            if self.useable[i] == 1:
                for goal in self.reverse[i]:
                    if self.useable[goal - 1] == 0:
                        self.useable[goal - 1] = 1
        for i in range(self.N):
            if self.useable[i] == 0:
                self.forward[i] = []
            else:
                self.forward[i].sort()

    def setTime(self, index, value):
        if self.times[index] < value:
            self.times[index] = value
            # print(self.times)
            for i in self.forward[index]:
                self.setTime(i - 1, self.times[index] + self.buildTime[i - 1])

    def getTime(self):
        return self.times[self.target - 1]

if __name__=='__main__':
    results = []
    testNum = int(sys.stdin.readline())
    for _ in range(testNum):
        N, K = map(int, sys.stdin.readline().strip().split(' '))
        buildTime = list(map(int, sys.stdin.readline().strip().split(' ')))
        forward = [[] for _ in range(N)]
        reverse = [[] for _ in range(N)]
        for _ in range(K):
            a, b = map(int, sys.stdin.readline().strip().split(' '))
            forward[a - 1].append(b)
            reverse[b - 1].append(a)

        target = int(sys.stdin.readline())
        acmCraft = AcmCraft(N, K, buildTime, forward, reverse, target)
        results.append(acmCraft.getTime())
    for result in results:
        print(result)
            