
plane = [['-', '0', '-', '-', '-', '-', '-' ],
        ['-', '0', '0', '0', '0', '0', '-' ],
        ['-', '0', '-', '-', '-', '-', '-' ]]

M = 7
N = 3

for p in plane:
    print(p)

temp = list(plane)
def move(x, y):
    if temp[y][x] == '-':
        print('x : ', x, ', y : ', y, ' already exist')
        return True
    # 경계에 도착한 경우
    elif x == 0 or x == M - 1 or y == 0 or y == N - 1:
        return False
    else:
        print('x : ', x, ', y : ', y, ' move')
        temp[y][x] = '-'
        for t in temp:
            print(t)
        # 위쪽 방향으로 이동
        if not move(x, y - 1):
            return False
        # 우측 방향으로 이동
        if not move(x + 1, y):
            return False
        # 아래 방향으로 이동
        if not move(x, y + 1):
            return False
        # 좌측 방향으로 이동
        if not move(x - 1, y):
            return False
    return True

if not move(5, 1):
    print('Fail')
else:
    print('Success')