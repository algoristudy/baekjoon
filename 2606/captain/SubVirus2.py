# 2606번 문제\
from collections import deque
import sys

if __name__=='__main__':
    computerCount = int(sys.stdin.readline())
    virus = [False] * computerCount
    connectionCount = int(sys.stdin.readline())
    connections = [deque() for _ in range(computerCount)]
    for _ in range(connectionCount):
        start, end = map(int, sys.stdin.readline().strip().split(' '))
        connections[start - 1].append(end)
        connections[end - 1].append(start)
    queue = deque()
    count = -1
    queue.append(1)
    while queue:
        start = queue.popleft() - 1
        if not virus[start]:
            virus[start] = True
            count += 1
            while connections[start]:
                queue.append(connections[start].popleft())
    print(count)
