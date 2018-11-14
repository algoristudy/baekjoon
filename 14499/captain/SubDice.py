class MyMap():
    def __init__(self, N, M, x, y, plane, dice):
        self.N = N     # 세로 크기
        self.M = M     # 가로 크기
        self.x = x     # x 좌표
        self.y = y     # y 좌표
        self.plane = plane  # 평면
        self.dice = dice    # 주사위
        self.results = []   # 결과
        if self.plane[y][x] != 0:   # 평면의 숫자가 0이 아닐 경우 주사위의 바닥에 숫자를 입력
            self.dice.setBottom(self.plane[y][x])
            self.plane[y][x] = 0

    def command(self, command):
        if command == 1:
            if not self.x + 1 == self.M:
                self.x += 1
            else:
                return
        elif command == 2:
            if not self.x - 1 < 0:
                self.x -= 1
            else:
                return
        elif command == 3:
            if not self.y - 1 < 0:
                self.y -= 1
            else:
                return
        elif command == 4:
            if not self.y + 1 == self.N:
                self.y += 1
            else:
                return
        else:
            return
        self.plane[self.y][self.x] = self.dice.command(command, self.plane[self.y][self.x])
        self.results.append(self.dice.getUpper())
    
    def getUpper(self):
        return self.dice.getUpper()

    def getResults(self):
        return self.results

class Dice():
    def __init__(self):
        self.dice = [[0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0]]
        self.temp = [[0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0]]
        self.top = (1, 1)
        self.bottom = (3, 1)
    
    def setBottom(self, value):
        self.dice[3][1] = value

    def command(self, command, plane):
        for y in range(4):
            for x in range(3):
                self.temp[y][x] = self.dice[y][x]
        if command == 1:
            # 동
            self.dice[1][0] = self.temp[3][1]
            self.dice[1][1] = self.temp[1][0]
            self.dice[1][2] = self.temp[1][1]
            self.dice[3][1] = self.temp[1][2]
        elif command == 2:
            # 서
            self.dice[1][0] = self.temp[1][1]
            self.dice[1][1] = self.temp[1][2]
            self.dice[1][2] = self.temp[3][1]
            self.dice[3][1] = self.temp[1][0]
        elif command == 3:
            # 북
            self.dice[0][1] = self.temp[1][1]
            self.dice[1][1] = self.temp[2][1]
            self.dice[2][1] = self.temp[3][1]
            self.dice[3][1] = self.temp[0][1]
        elif command == 4:
            # 남
            self.dice[0][1] = self.temp[3][1]
            self.dice[1][1] = self.temp[0][1]
            self.dice[2][1] = self.temp[1][1]
            self.dice[3][1] = self.temp[2][1]
        if plane: 
            # 주사위와 접촉하는 면이 0이 아닐 경우
            self.dice[3][1] = plane
            return 0
        else:
            return self.dice[3][1]
    
    def getUpper(self):
        return self.dice[1][1]

if __name__=='__main__':
    N, M, x, y, count = map(int, input().strip().split(' '))
    plane = []
    for _ in range(N):
        plane.append(list(map(int, input().strip().split(' '))))
    commands = list(map(int, input().strip().split(' ')))
    dice = Dice()
    myMap = MyMap(N, M, x, y, plane, dice)
    for i in range(count):
        myMap.command(commands[i])
    results = myMap.getResults()
    for result in results:
        print(result)