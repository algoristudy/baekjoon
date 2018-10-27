class Mini():
    def __init__(self, size, aList, bList):
        self.size = size
        self.aList = aList
        self.bList = bList
        self.sum = 0

    def getSum(self):
        self.aList.sort()
        self.bList.sort()
        self.bList.reverse()
        for i in range(self.size):
            self.sum += self.aList[i] * self.bList[i]
        return self.sum


if __name__=='__main__':
    size = int(input())
    aList = list(map(int, input().strip().split(' ')))
    bList = list(map(int, input().strip().split(' ')))
    mini = Mini(size, aList, bList)
    print(mini.getSum())
    # with open('../input.txt', 'r') as f:
    #     size = int(f.readline())
    #     aList = list(map(int, f.readline().strip().split(' ')))
    #     bList = list(map(int, f.readline().strip().split(' ')))
    #     mini = Mini(size, aList, bList)
    #     print(mini.getSum())