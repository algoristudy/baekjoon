import sys
class Game():
    def __init__(self, playerCount, scores, arr, mafiaIndex):
        self.playerCount = playerCount    # 게임 플레이어 수
        self.initScores = scores          # 초기 점수
        self.arr = arr                    # 죽었을 경우 점수
        self.mafiaIndex = mafiaIndex      # 마피아 인덱스
        self.nightCount = 0               # 저녁 카운트
        self.initSetting()                # 초기화
        self.maxCount = int(self.playerCount / 2)
        if self.nightCount:
            self.nightCount = 0
        else:
            self.play()

    def initSetting(self):
        # 플레이어 수가 홀수 일 경우 낮, 점수가 가장 높고, 동일한 경우 인덱스가 빠른 사람이 죽음
        if self.playerCount % 2 == 1:
            index = self.initScores.index(max(self.initScores))
            # 마피아가 처음부터 죽는 경우
            if index == self.mafiaIndex:
                self.nightCount += 1
                return
            self.initScores[index] = 0
        
        self.killingList = []
        self.scores = []
        for _ in range(int(self.playerCount / 2) + 1):
            self.killingList.append([1] * self.playerCount)
            self.scores.append([0] * self.playerCount)
        for i in range(self.playerCount):
            self.scores[0][i] = self.initScores[i]
            if self.initScores[i] == 0:
                self.killingList[0][i] = 0
        self.killingList[0][self.mafiaIndex] = 0
    
    def play(self, nightCount = 0):
        # print(self.killingList[nightCount])
        # print(self.scores[nightCount])
        # 밤일 경우 임의의 대상을 죽임
        nightCount += 1
        if self.nightCount < nightCount:
            self.nightCount = nightCount
        for i in range(self.playerCount):
            if self.nightCount == self.maxCount:
                return
            for j in range(self.playerCount):
                self.killingList[nightCount][j] = self.killingList[nightCount - 1][j]
            # 사람을 죽일 경우
            if self.killingList[nightCount - 1][i] == 1:
                self.killingList[nightCount][i] = 0
                for j in range(self.playerCount):
                    if j == i:
                        self.scores[nightCount][j] = 0
                    elif self.scores[nightCount - 1][j] != 0:
                        self.scores[nightCount][j] = self.scores[nightCount - 1][j] + self.arr[i][j]
                # 낮 점수가 높음 사람이 죽음
                index = self.scores[nightCount].index(max(self.scores[nightCount]))
                if index == self.mafiaIndex:
                    continue
                self.killingList[nightCount][index] = 0
                for j in range(self.playerCount):
                    if j == index:
                        self.scores[nightCount][j] = 0
                    elif self.scores[nightCount][j] != 0:
                        self.scores[nightCount][j] += self.arr[i][j]
                self.play(nightCount)

    def getCount(self):
        return self.nightCount                

if __name__=='__main__':
    playerCount = int(sys.stdin.readline())
    scores = list(map(int, sys.stdin.readline().strip().split(' ')))
    arr = []
    for _ in range(playerCount):
        arr.append(list(map(int, sys.stdin.readline().strip().split(' '))))
    mafiaIndex = int(sys.stdin.readline())
    game = Game(playerCount, scores, arr, mafiaIndex)
    print(game.getCount())