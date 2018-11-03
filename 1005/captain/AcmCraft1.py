class AcmCraft():
    def __init__(self, N, K, buildTime, cases, target):
        self.N = N
        self.K = K
        self.buildTime = buildTime
        # [10, 1, 100, 10]
        self.completeTime = [0] * self.N
        self.completeTime[0] = self.buildTime[0]
        self.cases = cases
        self.target = target

    def getTime(self):
        caseIndex = 0
        for i in range(self.target - 1):
            print('index : ', i)
            while self.cases[caseIndex][0] == i + 1:
                print('case index : ', caseIndex)
                if self.completeTime[self.cases[caseIndex][1] - 1] < self.completeTime[i] + self.buildTime[self.cases[caseIndex][1] - 1]:
                    self.completeTime[self.cases[caseIndex][1] - 1] = self.completeTime[i] + self.buildTime[self.cases[caseIndex][1] - 1]
                    print(self.completeTime)
                caseIndex += 1
                if caseIndex == self.K:
                    break
        return self.completeTime[self.target - 1]


if __name__=='__main__':
    with open('../input.txt', 'r') as f:
        testNum = int(f.readline())
        for _ in range(testNum):
            N, K = map(int, f.readline().strip().split(' '))
            buildTime = list(map(int, f.readline().strip().split(' ')))
            cases = [[]] * K
            for i in range(K):
                cases[i] = list(map(int, f.readline().strip().split(' ')))
            target = int(f.readline())
            acmCraft = AcmCraft(N, K, buildTime, cases, target)
            print(acmCraft.getTime())