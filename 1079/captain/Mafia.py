class Mafia():
    def __init__(self, playerCount, scores, relativeScore, playerIndex):
        self.playerCount = playerCount
        self.scores = scores
        self.relativeScore = relativeScore
        self.playerIndex = playerIndex
        self.select = [52] * self.playerCount
        for i in range(self.playerCount):
            if i != self.playerIndex:
                for j in range(self.playerCount):
                    if j != self.playerIndex and i != j:
                        diff = self.relativeScore[i][j] - self.relativeScore[i][self.playerIndex]
                        # print('i : ', i, ', j : ', j, ', diff : ', diff)
                        if self.select[i] > diff:
                            self.select[i] = diff
        self.select[self.playerIndex] = -52
        print(self.select)
        self.nightCount = 0
        while self.scores[playerIndex] != 0 and self.playerCount != 1:
            # print(self.playerCount)
            self.play()

    def play(self):
        if self.playerCount % 2 == 0:
            self.nightCount += 1
            # 짝수 일 경우 밤 마피아 -> 시민 죽임
            # 내 점수를 낮출 수 있는 사람을 죽임
            # 1. 내 점수가 가장 낮아 질 수 있는 경우를 선택
            index = -1
            if self.select.count(max(self.select)) == 1:
                index = self.select.index(max(self.select))
            # 2. 점수가 동일한 경우 점수가 낮은 사람을 죽임
            else:
                score = max(self.scores)
                select = max(self.select)
                index = self.select.index(select)
                for i in range(len(self.scores)):
                    if i != self.playerIndex and select == self.select[i]:
                        if score > self.scores[i]:
                            score = self.scores[i]
                            index = i
            # i = 죽일 사람 인덱스
            print('night : ', index, ' is dead')
            self.scores[index] = 0
            for j in range(len(self.scores)):
                if self.scores[j] != 0:
                    self.scores[j] += self.relativeScore[index][j]
            self.select[index] = -52
            self.playerCount -= 1
        else:
            # 홀수 일 경우 낮 시민 -> 점수가 높은 사람 죽임
            index = self.scores.index(max(self.scores))
            print('day : ', index, ' is dead')
            self.scores[index] = 0
            self.select[index] = -52
            self.playerCount -= 1

    def getNightCount(self):
        return self.nightCount

if __name__=='__main__':
    with open('./input.txt', 'r') as f:
        playerCount = int(f.readline())
        scores = list(map(int, f.readline().strip().split(' ')))
        relativeScore = []
        for i in range(playerCount):
            relativeScore.append(list(map(int, f.readline().strip().split(' '))))
        playerIndex = int(f.readline()) - 1
        mafia = Mafia(playerCount, scores, relativeScore, playerIndex)
        print(mafia.getNightCount())