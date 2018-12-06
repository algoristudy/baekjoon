import sys
def LCS(source, target, getCount = False):
    results = []
    D = [[0] * (len(source) + 1) for _ in range(len(target) + 1)]
    for y in range(1, len(target) + 1):
        for x in range(1, len(source) + 1):
            if source[x - 1] == target[y - 1]:
                D[y][x] = D[y - 1][x - 1] + 1
            else:
                D[y][x] = D[y][x - 1] if D[y][x - 1] > D[y - 1][x] else D[y - 1][x]
    maxCount = D[len(target)][len(source)]
    if getCount:
        return maxCount
    if not maxCount:
        return results
    index = [[] for _ in range(maxCount)]
    count = [0] * maxCount
    for y in range(1, len(target) + 1):
        for x in range(1, len(source) + 1):
            if D[y][x - 1] != D[y][x]:
                if not x - 1 in index[D[y][x - 1]]:
                    index[D[y][x - 1]].append(x - 1)
                    count[D[y][x - 1]] += 1
    
    return ''
    
    # i = 1
    # for x in range(1, len(source) + 1):
    #     for y in range(1, len(target) + 1):
    #         if D[y][x] == i:
    #             result += source[x - 1]
    #             i += 1
    #             if i > lcs:
    #                 return result

if __name__=='__main__':
    sentence = []
    for _ in range(3):
        sentence.append(sys.stdin.readline().strip())
    results = LCS(sentence[1], sentence[2])
    maxCount = 0
    for result in results:
        count = LCS(sentence[0], result, True)
        if count > maxCount:
            maxCount = count
    print(maxCount)