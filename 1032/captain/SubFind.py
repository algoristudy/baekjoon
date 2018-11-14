import sys

class Find():
    def __init__(self, count, results):
        self.count = count
        self.results = results
        self.temp = list(self.results[0])
        self.temp.pop()
        for i in range(len(self.temp)):
            for result in self.results:
                if not self.temp[i] == result[i]:
                    self.temp[i] = '?'
                    break
        self.search = ''
        for temp in self.temp:
            self.search += temp
        print(self.search)


if __name__=='__main__':
    count = int(sys.stdin.readline())
    results = []
    for _ in range(count):
        results.append(sys.stdin.readline())
    find = Find(count, results)