import sys
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
            consonantCount = 0
            vowelCount = 0
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
    L, C = map(int, sys.stdin.readline().strip().split(' '))
    words = list(map(str, sys.stdin.readline().strip().split(' ')))
    encrypt = Encrypt(L, C, words)