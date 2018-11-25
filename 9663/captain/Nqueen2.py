class Nqueen():
    def __init__(self, N):
        self.N = N
        self.board = [0] * self.N
        self.count = 0
        self.flag = False
        self.path()

    def path(self, row = 0):
        if row == self.N:
            self.count += 1
            return
        for i in range(self.N):
            self.flag = True
            for j in range(row):
                if self.board[j] == i or abs(row - j) == abs(i - self.board[j]):
                    self.flag = False
                    break
            if self.flag:
                self.board[row] = i
                self.path(row + 1)

    def getCount(self):
        return self.count

if __name__=='__main__':
    N = int(input())
    nqueen = Nqueen(N)
    print(nqueen.getCount())