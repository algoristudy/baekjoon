import sys
word1 = None
word2 = None
word3 = None
word1Length = 0
word2Length = 0
word3Length = 0
result = 'no'

def verify(index1, index2, index3):
    if index3 == word3Length:
        global result
        result = 'yes'
    if index1 != word1Length and word1[index1] == word3[index3]:
        verify(index1 + 1, index2, index3 + 1)
    if index2 != word2Length and word2[index2] == word3[index3]:
        verify(index1, index2 + 1, index3 + 1)

if __name__=='__main__':
    case = int(sys.stdin.readline())
    word = [[] for _ in range(1000)]
    for i in range(case):
        word[i] = list(map(str, sys.stdin.readline().strip().split(' ')))
    for i in range(case):
        result = 'no'
        word1, word2, word3 = map(str, word[i])
        word1Length = len(word1)
        word2Length = len(word2)
        word3Length = len(word3)
        result = verify(0, 0, 0)
        print('Data set {0}: {1}'.format(i + 1, 'yes' if result else 'no'))