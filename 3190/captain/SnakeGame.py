#-*- coding:utf-8 -*-
class SnakeGame():
    def __init__(self):
        self.size = int(input().strip()) # 보드의 크기
        self.appleCount = int(input().strip()) # 사과 갯수
        self.applePosition = []
        for _ in range(self.appleCount):
            self.applePosition.append(list(map(int, input().strip().split(' ')))) # 사과 위치
        self.rotationCount = int(input().strip()) # 방향 전환 횟수
        self.rotations = []
        for _ in range(self.rotationCount):
            self.rotations.append(list(map(str, input().strip().split(' ')))) # 방향 전환 내역
        self.time = 0
        self.direction = 0 # 동 : 0, 남 : 1, 서 : 2, 북 : 3
        self.initPlane()
        self.headPosition = [0, 0]
        self.tailPosition = [0, 0]
        self.snake = [[0, 0]]

    def initPlane(self):
        self.plane = []
        for _ in range(self.size):
            self.plane.append([' '] * self.size)
        for position in self.applePosition:
            # print(position)
            self.plane[position[0] - 1][position[1] - 1] = 'A'
        self.plane[0][0] = '0'
        # for plane in self.plane:
        #     print(plane)

    def move(self):
        index = 0
        rotation = self.rotations[index]
        while True:
            self.time += 1
            if self.direction == 0:
                self.headPosition = [self.headPosition[0] + 1, self.headPosition[1]]
                if not self.isDead(self.headPosition[0], self.headPosition[1]):
                    # 죽지 않을 경우
                    if not self.isApple(self.headPosition[0], self.headPosition[1]):
                        # 사과가 없을 경우 이동
                        tailPosition = self.snake.pop(0)
                        self.plane[tailPosition[1]][tailPosition[0]] = ' '
                    self.plane[self.headPosition[1]][self.headPosition[0]] = '0'
                    self.snake.append(self.headPosition)
                else:
                    return self.time
            elif self.direction == 1:
                self.headPosition = [self.headPosition[0], self.headPosition[1] + 1]
                if not self.isDead(self.headPosition[0], self.headPosition[1]):
                    # 죽지 않을 경우
                    if not self.isApple(self.headPosition[0], self.headPosition[1]):
                        # 사과가 없을 경우 이동
                        tailPosition = self.snake.pop(0)
                        self.plane[tailPosition[1]][tailPosition[0]] = ' '
                    self.plane[self.headPosition[1]][self.headPosition[0]] = '0'
                    self.snake.append(self.headPosition)
                else:
                    return self.time
            elif self.direction == 2:
                self.headPosition = [self.headPosition[0] - 1, self.headPosition[1]]
                if not self.isDead(self.headPosition[0], self.headPosition[1]):
                    # 죽지 않을 경우
                    if not self.isApple(self.headPosition[0], self.headPosition[1]):
                        # 사과가 없을 경우 이동
                        tailPosition = self.snake.pop(0)
                        self.plane[tailPosition[1]][tailPosition[0]] = ' '
                    self.plane[self.headPosition[1]][self.headPosition[0]] = '0'
                    self.snake.append(self.headPosition)
                else:
                    return self.time
            elif self.direction == 3:
                self.headPosition = [self.headPosition[0], self.headPosition[1] - 1]
                if not self.isDead(self.headPosition[0], self.headPosition[1]):
                    # 죽지 않을 경우
                    if not self.isApple(self.headPosition[0], self.headPosition[1]):
                        # 사과가 없을 경우 이동
                        tailPosition = self.snake.pop(0)
                        self.plane[tailPosition[1]][tailPosition[0]] = ' '
                    self.plane[self.headPosition[1]][self.headPosition[0]] = '0'
                    self.snake.append(self.headPosition)
                else:
                    return self.time
            
            if self.time == int(rotation[0]):
                self.rotate(rotation[1])
                index += 1
                if index != self.rotationCount:
                    rotation = self.rotations[index]

            # print('\ntime : ', self.time, '\n')
            # for plane in self.plane:
            #     print(plane)
            
    def isDead(self, x, y):
        if self.direction == 0:
            if x == self.size or self.plane[y][x] == '0':
                return True
        elif self.direction == 1:
            if y == self.size or self.plane[y][x] == '0':
                return True
        elif self.direction == 2:
            if x < 0 or self.plane[y][x] == '0':
                return True
        elif self.direction == 3:
            if y < 0 or self.plane[y][x] == '0':
                return True
        return False


    def isApple(self, x, y):
        if self.plane[y][x] == 'A':
            return True
        else:
            return False

    def rotate(self, direction):
        if direction == 'D':
            self.direction += 1
            if self.direction == 4:
                self.direction = 0
        elif direction == 'L':
            self.direction -= 1
            if self.direction == -1:
                self.direction = 3

if __name__=='__main__':
    snakeGame = SnakeGame()
    print(snakeGame.move())