# 2606번 문제
# import queue as Queue
from collections import deque

if __name__=='__main__':
    with open('../input.txt', 'r') as f:
        computerCount = int(f.readline())
        virus = [False] * computerCount
        connectionCount = int(f.readline())
        connections = [deque() for _ in range(computerCount)]
        for _ in range(connectionCount):
            start, end = map(int, f.readline().strip().split(' '))
            connections[start - 1].append(end)
        queue = deque()
        count = -1
        # 1번 컴퓨터 바이러스 감염
        queue.append(1)
        while queue:
            start = queue.popleft() - 1
            if not virus[start]:
                virus[start] = True
                count += 1
                while connections[start]:
                    queue.append(connections[start].popleft())
        print(count)
