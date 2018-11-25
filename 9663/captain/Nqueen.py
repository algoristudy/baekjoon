class Nqueen():
    def __init__(self, N):
        self.N = N
        self.boards = [[[0] * self.N for _ in range(self.N)] for _ in range(self.N)]
        self.temp = [[0] * self.N for _ in range(self.N)]
        self.count = 0 
        self.verify()

    def verify(self, boardIndex = 1):
        if boardIndex == self.N:
            for i in range(self.N):
                if self.boards[boardIndex - 1][boardIndex - 1][i] == 0:
                    self.count += 1
            return
        for i in range(self.N):
            # print('\ni : ', i)
            # 초기화
            for y in range(boardIndex - 1, self.N):
                for x in range(self.N):
                    self.boards[boardIndex][y][x] = self.boards[boardIndex - 1][y][x]
            # for board in self.boards[boardIndex]:
            #     print(board)
            if self.boards[boardIndex][boardIndex - 1][i] == 0:
                self.boards[boardIndex][boardIndex - 1][i] = 1
                diff = 0
                for j in range(boardIndex, self.N):
                    diff += 1
                    self.boards[boardIndex][j][i] = 1
                    if i + diff < self.N:
                        self.boards[boardIndex][j][i + diff] = 1
                    if i - diff > -1:
                        self.boards[boardIndex][j][i - diff] = 1
                # for board in self.boards[boardIndex]:
                #     print(board)
                self.verify(boardIndex + 1)

    def getCount(self):
        return self.count

if __name__=='__main__':
    for i in range(15):
        nqueen = Nqueen(i)
        print('index : ', i, ', Count : ', nqueen.getCount())
    # N = int(input())
    # nqueen = Nqueen(N)
    # print(nqueen.getCount())