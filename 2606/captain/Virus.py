# 2606번 문제
import queue as Queue

if __name__=='__main__':
    with open('../input.txt', 'r') as f:
        computerCount = int(f.readline())
        virus = [False] * (computerCount + 1)
        connectionCount = int(f.readline())
        connections = [Queue.Queue(100) for _ in range(computerCount + 1)]
        for _ in range(connectionCount):
            start, end = map(int, f.readline().strip().split(' '))
            connections[start].put(end)
        queue = Queue.Queue(connectionCount)
        # 1번 컴퓨터 바이러스 감염
        queue.put(1)
        while not queue.empty():
            start = queue.get()
            virus[start] = True
            while not connections[start].empty():
                queue.put(connections[start].get())
        print(virus.count(True) - 1)
