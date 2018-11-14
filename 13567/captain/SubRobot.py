import sys

class Robot():
    def __init__(self, M, n, commands):
        self.M = M
        self.n = n
        self.commands = commands
        self.position = [0, 0] # 처음 위치 x = 0, y = 0
        self.direction = 0 # 동 : 0, 남 : 1, 서: 2, 북 : 3
        for command in self.commands:
            self.position = self.getNewPosition(command[0], int(command[1]))
            if self.position == -1:
                break


    def getNewPosition(self, action, value):
        if action == 'MOVE':
            # 이동일 경우
            if self.direction == 0:
                # 동쪽일 경우
                if self.position[0] + value > self.M:
                    return -1
                else:
                    return [self.position[0] + value, self.position[1]]
            elif self.direction == 1:
                # 남쪽일 경우
                if self.position[1] - value < 0:
                    return -1
                else:
                    return [self.position[0], self.position[1] - value]
            elif self.direction == 2:
                # 서쪽일 경우
                if self.position[0] - value < 0:
                    return -1
                else:
                    return [self.position[0] - value, self.position[1]]
            elif self.direction == 3:
                # 북쪽일 경우
                if self.position[1] + value > self.M:
                    return -1
                else:
                    return [self.position[0], self.position[1] + value]
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
            return self.position

    def getPosition(self):
        return self.position

if __name__=='__main__':
    results = []
    M, n = map(int, sys.stdin.readline().strip().split(' '))
    commands = []
    for _ in range(n):
        commands.append(list(map(str, sys.stdin.readline().strip().split(' '))))
    robot = Robot(M, n, commands)
    results.append(robot.getPosition())
    for result in results:
        if result == -1:
            print(result)
        else:
            print(result[0], result[1])