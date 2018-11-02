class Team():
    def __init__(self):
        self.n = 6
        self.a = [0, 1, 2]
        self.b = [3, 4, 5]
        self.position = 2

    def setNextTeam(self):
        if self.a:
            self.a[self.position] += 1
            if self.a[self.position] == self.n - len(self.a) + 1 + self.position:
                self.position -= 1
                if self.position < 0:
                    self.a = None
                self.setNextTeam()
            if 0 <= self.position < 2:
                self.position += 1
                self.a[self.position] = self.a[self.position - 1] + 1


    # def setNextTeam(self):
    #     self.a[self.position] += 1
    #     if self.a[self.position] == self.n - len(self.a) + 1 + self.position:
    #         self.position -= 1
    #         self.setNextTeam()
    #     if self.position < 0:
    #         return
    #     else:
    #         while self.position != 2:
    #             self.position += 1
    #             self.a[self.position] = self.a[self.position - 1] + 1

    def getATeam(self):
        return self.a

if __name__=='__main__':
    team = Team()
    print(team.getATeam())
    while team.getATeam():
        team.setNextTeam()
        print(team.getATeam())