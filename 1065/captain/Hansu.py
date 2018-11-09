class Hansu():
    def __init__(self, number):
        self.number = number
        self.count = 99

    def getCount(self):
        # 수가 100보다 작은 경우 모든 수가 한수
        if self.number < 100:
            return self.number
        else:
            temp = [0] * 3
            for i in range(100, self.number + 1):
                temp[0] = int(i / 100)
                temp[1] = int((i % 100) / 10)
                temp[2] = i % 10
                if temp[0] - temp[1] == temp[1] - temp[2]:
                    self.count += 1
            return self.count

if __name__=='__main__':
    hansu = Hansu(int(input()))
    print(hansu.getCount())