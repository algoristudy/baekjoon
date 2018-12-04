# 2606번 문제
import queue as Queue
import sys

if __name__=='__main__':
    computerCount = int(sys.stdin.readline())
    virus = [False] * computerCount
    connectionCount = int(sys.stdin.readline())
    connections = [Queue.Queue(100) for _ in range(computerCount)]
    for _ in range(connectionCount):
        start, end = map(int, sys.stdin.readline().strip().split(' '))
        connections[start - 1].put(end)
        connections[end - 1].put(start)
    queue = Queue.Queue(connectionCount + 1)
    # 1번 컴퓨터 바이러스 감염
    count = -1
    queue.put(1)
    while not queue.empty():
        start = queue.get() - 1
        if not virus[start]:
            virus[start] = True
            count += 1
            while not connections[start].empty():
                queue.put(connections[start].get())
    print(count)
