import sys
class AcmCraft():
    def __init__(self, N, K, buildTime, cases, target):
        self.N = N
        self.K = K
        self.buildTime = buildTime
        self.completeTime = [0] * self.N
        self.completeTime[0] = self.buildTime[0]
        self.cases = cases
        self.target = target
        self.setTime(0)

    def setTime(self, start):
        while self.cases[start]:
            case = self.cases[start].pop()
            if self.completeTime[case - 1] < self.completeTime[start] + self.buildTime[case - 1]:
                self.completeTime[case - 1] = self.completeTime[start] + self.buildTime[case - 1]
            self.setTime(case - 1)

    def getTime(self):
        return self.completeTime[self.target - 1]

if __name__=='__main__':
    results = []
    testNum = int(sys.stdin.readline())
    for _ in range(testNum):
        N, K = map(int, sys.stdin.readline().strip().split(' '))
        buildTime = list(map(int, sys.stdin.readline().strip().split(' ')))
        cases = []
        for _ in range(K):
            cases.append([])
        for i in range(K):
            index, goal = map(int, sys.stdin.readline().strip().split(' '))
            cases[index - 1].append(goal)
        target = int(sys.stdin.readline())
        acmCraft = AcmCraft(N, K, buildTime, cases, target)
        results.append(acmCraft.getTime())
    for result in results:
        print(result)