class Encrypt():
    def __init__(self, L, C, words):
        self.L = L
        self.C = C
        self.words = words
        self.words.sort()
        self.encrypt = ['a'] * self.L
        self.vowels = ['a', 'e', 'i', 'o', 'u']
        self.printEncrypt()

    def printEncrypt(self, index = 0, start = 0):
        if index == self.L:
            temp = ''
            consonantCount = 0 # 자음
            vowelCount = 0 # 모음
            for encrypt in self.encrypt:
                if encrypt in self.vowels:
                    vowelCount += 1
                else:
                    consonantCount += 1
                temp += encrypt
            if consonantCount > 1 and vowelCount > 0:
                print(temp)
            return
        
        for i in range(start, self.C - self.L + index + 1):
            self.encrypt[index] = self.words[i]
            self.printEncrypt(index + 1, i + 1)

if __name__=='__main__':
    with open('../input.txt', 'r') as f:
        L, C = map(int, f.readline().strip().split(' '))
        words = list(map(str, f.readline().strip().split(' ')))
        encrypt = Encrypt(L, C, words)