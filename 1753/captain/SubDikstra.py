import queue, sys
class Path():
    def __init__(self, V, E, startNode, paths):
        self.V = V
        self.E = E
        self.inf = 200001
        self.result = [int(self.inf)] * (self.V + 1) # 각 노드까지 가는 최단거리
        self.paths = paths
        self.startNode = startNode - 1
        self.result[startNode] = 0
        self.priorityQueue = queue.PriorityQueue(maxsize = 300001)
        self.priorityQueue.put([0, startNode])
        while not self.priorityQueue.empty():
            self.setWeight()
        for i in range(1, self.V + 1):
            if self.result[i] == self.inf:
                print('INF')
            else:
                print(self.result[i])

    def setWeight(self):
        # start[0] = node weight
        # start[1] = node number
        start = self.priorityQueue.get()
        while self.paths[start[1]]:
            # end[0] = node number
            # end[1] = path weight
            end = self.paths[start[1]].pop()
            # print('End', end)
            if self.result[end[0]] > start[0] + end[1]:
                self.result[end[0]] = start[0] + end[1]
                self.priorityQueue.put([self.result[end[0]], end[0]])
                # print('result : ', self.result)

if __name__=='__main__':
    V, E = map(int, sys.stdin.readline().strip().split(' '))
    startNode = int(sys.stdin.readline())
    paths = [[] for _ in range(V + 1)]
    for _ in range(E):
        start, end, weight = map(int, sys.stdin.readline().strip().split(' '))
        paths[start].append([end, weight])
    path = Path(V, E, startNode, paths)
