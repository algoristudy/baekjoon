class Team():
    def __init__(self, count, stat):
        self.count = count
        self.stat = stat
        self.lastPosition = int(count / 2 - 1)
        self.position = int(self.lastPosition)
        self.diff = -1
        self.teamCount = int(count / 2)
        self.startTeam = [0] * self.teamCount
        self.linkTeam = [0] * self.teamCount
        for i in range(self.teamCount):
            self.startTeam[i] = i
        self.setNextLinkTeam()

    def setNextStartTeam(self):
        if self.startTeam:
            self.startTeam[self.position] += 1
            if self.startTeam[self.position] == self.count - self.teamCount + 1 + self.position:
                self.position -= 1
                if self.position < 0:
                    self.startTeam = None
                self.setNextStartTeam()
            if 0 <= self.position < self.lastPosition:
                self.position += 1
                self.startTeam[self.position] = self.startTeam[self.position - 1] + 1

    def setNextLinkTeam(self):
        if self.startTeam:
            startIndex = 0
            linkIndex = 0
            for i in range(self.count):
                if startIndex < self.teamCount and self.startTeam[startIndex] == i:
                    startIndex += 1
                else:
                    self.linkTeam[linkIndex] = i
                    linkIndex += 1
        else:
            self.linkTeam = None

    def setMinDiff(self):
        if self.diff == 0:
            return
        diff = 0
        for i in range(self.teamCount - 1):
            for j in range(i + 1, self.teamCount):
                a = self.startTeam[i]
                b = self.startTeam[j]
                diff += self.stat[a][b]
                diff += self.stat[b][a]
                a = self.linkTeam[i]
                b = self.linkTeam[j]
                diff -= self.stat[a][b]
                diff -= self.stat[b][a]
        if diff < 0:
            diff *= -1

        if self.diff < 0:
            self.diff = diff
        else:
            if diff < self.diff:
                self.diff = diff

    def getDiff(self):
        return self.diff

    def getStartTeam(self):
        return self.startTeam

    def getLinkTeam(self):
        return self.linkTeam
        

if __name__=='__main__':
    count = int(input())
    stat = []
    for _ in range(count):
        stat.append(list(map(int, input().strip().split(' '))))
    team = Team(count, stat)
    while team.getStartTeam():
        team.setMinDiff()
        if team.getDiff() == 0:
            break
        team.setNextStartTeam()
        team.setNextLinkTeam()
    print(team.getDiff())