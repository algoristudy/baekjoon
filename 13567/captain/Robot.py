import sys

class Robot():
    def __init__(self, M, n, commands):
        self.M = M
        self.n = n
        self.commands = commands
        self.position = [0, 0] # 처음 위치 x = 0, y = 0
        self.direction = 0 # 동 : 0, 남 : 1, 서: 2, 북 : 3
        for command in self.commands:
            # print(command)
            self.setPosition(command[0], int(command[1]))
            if self.position == [-1, -1]:
                break
            # else:
            #     print(self.direction)
            #     print(self.position)


    def setPosition(self, action, value):
        if action == 'MOVE':
            # 이동일 경우
            if self.direction == 0:
                # 동쪽일 경우
                if self.position[0] + value > self.M:
                    self.position = [-1, -1]
                else:
                    self.position[0] += value
            elif self.direction == 1:
                # 남쪽일 경우
                if self.position[1] - value < 0:
                    self.position = [-1, -1]
                else:
                    self.position[1] -= value
            elif self.direction == 2:
                # 서쪽일 경우
                if self.position[0] - value < 0:
                    self.position = [-1, -1]
                else:
                    self.position[0] -= value
            elif self.direction == 3:
                # 북쪽일 경우
                if self.position[1] + value > self.M:
                    self.position = [-1, -1]
                else:
                    self.position[1] += value
        else:
            # 회전일 경우
            if value == 0:
                # 왼쪽으로 회전
                self.direction -= 1
                if self.direction < 0:
                    self.direction = 3
            else:
                self.direction += 1
                if self.direction > 3:
                    self.direction = 0

    def getPosition(self):
        if self.position != [-1, -1]:
            return self.position
        else:
            return -1

if __name__=='__main__':
    results = []
    with open('../input.txt', 'r') as f:
        testNum = int(f.readline())
        for _ in range(testNum):
            M, n = map(int, f.readline().strip().split(' '))
            commands = []
            for _ in range(n):
                commands.append(list(map(str, f.readline().strip().split(' '))))
            robot = Robot(M, n, commands)
            results.append(robot.getPosition())
    for result in results:
        if type(result) == type([]):
            print('{0} {1}'.format(result[0], result[1]))
        else:
            print(result)