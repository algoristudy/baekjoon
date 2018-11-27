class Nqueen():
    def __init__(self, N):
        self.N = N
        self.count = 0
        self.board = [0] * (self.N ** 2)
        self.verifyY = [0] * self.N
        self.verifyL = [0] * (self.N * 2 - 1)
        self.verifyR = [0] * (self.N * 2 - 1)
        self.nextTargets = [0] * (self.N ** 2)
        self.findCount()

    def getCount(self):
        return self.count

    def setVerify(self, x, y, value):
        self.verifyY[x] = value
        self.verifyL[x + y] = value
        self.verifyR[self.N - x + y - 1] = value

    def findNextTargets(self, depth):
        nextTargetCount = 0
        for i in range(self.N):
            if not self.verifyY[i] and not self.verifyL[i + depth] and not self.verifyR[self.N - i + depth - 1]:
                self.nextTargets[self.N * depth + nextTargetCount] = i
                nextTargetCount += 1
        # print(nextTargets)
        return nextTargetCount

    def backtracking(self, depth):
        # print('depth : ', depth)
        if depth == self.N - 1:
            self.count += 1
        else:
            depth += 1
            depthIndex = self.N * depth
            nextTargetCount = self.findNextTargets(depth)
            for i in range(nextTargetCount):
                x = self.nextTargets[depthIndex + i]
                self.board[depthIndex + x] = 1
                self.setVerify(x, depth, 1)
                self.backtracking(depth)
                self.setVerify(x, depth, 0)
                self.board[depthIndex + x] = 0

    def findCount(self):
        testNum = int(self.N / 2) 
        for i in range(testNum):
            # print(i)
            self.board[i] = 1
            self.setVerify(i, 0, 1)
            self.backtracking(0)
            self.setVerify(i, 0, 0)
            self.board[i] = 0

        self.count *= 2

        if self.N % 2:
            # print(testNum)
            self.board[testNum] = 1
            self.setVerify(testNum, 0, 1)
            self.backtracking(0)
            self.setVerify(testNum, 0, 0)
            self.board[testNum] = 0

if __name__=='__main__':
    N = int(input())
    nqueen = Nqueen(N)
    print(nqueen.getCount())