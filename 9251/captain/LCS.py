def getCount(source, target):
    DP = [[0] * (len(source) + 1) for _ in range(len(target) + 1)]
    for y in range(1, len(target) + 1):
        for x in range(1, len(source) + 1):
            if source[x - 1] == target[y - 1]:
                DP[y][x] = DP[y - 1][x - 1] + 1
            else:
                DP[y][x] = DP[y - 1][x] if DP[y - 1][x] > DP[y][x - 1] else DP[y][x - 1]
    return DP[len(target)][len(source)]
if __name__=='__main__':
    with open('../input.txt', 'r') as f:
        source = f.readline().strip()
        target = f.readline().strip()
        print(getCount(source, target))