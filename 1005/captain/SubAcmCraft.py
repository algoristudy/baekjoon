import sys
class AcmCraft():
    def __init__(self, N, K, buildTime, cases, target):
        self.N = N
        self.K = K
        self.buildTime = buildTime
        self.cases = cases
        self.target = target
        self.completeTime = [0] * self.N
        self.completeTime[self.target - 1] = self.buildTime[self.target - 1]
        self.queue = []
        self.queue.append(self.target - 1)
        while self.queue:
            self.setTime()

    def setTime(self):
        start = self.queue[-1:][0]
        if self.cases[start]:
            case = self.cases[start].pop(0) - 1
            if self.completeTime[case] < self.completeTime[start] + self.buildTime[case]:
                self.completeTime[case] = self.completeTime[start] + self.buildTime[case]
                print(self.completeTime)
            self.queue.append(case)
            return
        self.queue.pop()

    def getTime(self):
        minTime = 0
        for time in self.completeTime:
            if minTime < time:
                minTime = time
        return minTime

if __name__=='__main__':
    testNum = int(sys.stdin.readline())
    results = [0] * testNum
    for i in range(testNum):
        N, K = map(int, sys.stdin.readline().strip().split(' '))
        buildTime = list(map(int, sys.stdin.readline().strip().split(' ')))
        cases = []
        for _ in range(K):
            cases.append([])
        for _ in range(K):
            goal, index = map(int, sys.stdin.readline().strip().split(' '))
            cases[index - 1].append(goal)
        # print(cases)
        target = int(sys.stdin.readline())
        acmCraft = AcmCraft(N, K, buildTime, cases, target)
        results[i] = acmCraft.getTime()
    for result in results:
        print(result)