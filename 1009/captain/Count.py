class Count():
    def __init__(self):
        self.list = {}
        self.list[1] = [1]
        self.list[2] = [2, 4, 8, 6]
        self.list[3] = [3, 9, 7, 1]
        self.list[4] = [4, 6]
        self.list[5] = [5]
        self.list[6] = [6]
        self.list[7] = [7, 9, 3, 1]
        self.list[8] = [8, 4, 2, 6]
        self.list[9] = [9, 1]

    def getCount(self, a, b):
        a = a % 10
        if a == 0:
            return 10
        index = (b % len(self.list[a])) - 1
        if index < 0:
            index = len(self.list[a]) - 1
        return self.list[a][index]
        
if __name__=='__main__':
    results = []
    count = Count()
    with open('../input.txt', 'r') as f:
        testNum = int(f.readline())
        results = [0] * testNum
        for i in range(testNum):
            a, b = map(int, f.readline().strip().split(' '))
            results[i] = count.getCount(a, b) 
    for result in results:
        print(result)