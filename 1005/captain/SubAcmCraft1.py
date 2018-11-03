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

    def setTime(self):
        caseIndex = 0
        for i in range(self.target - 1):
            # print('index : ', i)
            while self.cases[caseIndex][0] == i + 1:
                # print('case index : ', caseIndex)
                if self.completeTime[self.cases[caseIndex][1] - 1] < self.completeTime[i] + self.buildTime[self.cases[caseIndex][1] - 1]:
                    self.completeTime[self.cases[caseIndex][1] - 1] = self.completeTime[i] + self.buildTime[self.cases[caseIndex][1] - 1]
                    # print(self.completeTime)
                caseIndex += 1
                if caseIndex == self.K:
                    return
    
    def getTime(self):
        return self.completeTime[self.target - 1]


if __name__=='__main__':
    testNum = int(sys.stdin.readline())
    results = []
    for _ in range(testNum):
        N, K = map(int, sys.stdin.readline().strip().split(' '))
        buildTime = list(map(int, sys.stdin.readline().strip().split(' ')))
        cases = [[]] * K
        for i in range(K):
            cases[i] = list(map(int, sys.stdin.readline().strip().split(' ')))
        target = int(sys.stdin.readline())
        acmCraft = AcmCraft(N, K, buildTime, cases, target)
        acmCraft.setTime()
        results.append(acmCraft.getTime())
    for result in results:
        print(result)