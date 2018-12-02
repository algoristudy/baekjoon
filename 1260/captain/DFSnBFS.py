import queue as Queue
import sys

class DFSBFS():
    def __init__(self):
        self.N, self.T, self.startNode = map(int, sys.stdin.readline().strip().split(' '))
        self.dfsTrunks = [Queue.PriorityQueue() for _ in range(self.T)]
        self.bfsTrunks = [Queue.PriorityQueue() for _ in range(self.T)]
        self.dfsResult = Queue.Queue(self.T)
        self.bfsResult = Queue.Queue(self.T)
        for _ in range(self.T):
            start, end = map(int, sys.stdin.readline().strip().split(' '))
            self.dfsTrunks[start].put(end)
            self.bfsTrunks[start].put(end)
        self.DFS(self.startNode)
        self.BFS(self.startNode)
        self.printResult(self.dfsResult)
        self.printResult(self.bfsResult)
        
    def DFS(self, startNode):
        print(startNode)
        self.dfsResult.put(startNode)
        # if not startNode in self.dfsResult:
        #     self.dfsResult.append(startNode)
        while not self.dfsTrunks[startNode].empty():
            self.DFS(self.dfsTrunks[startNode].get())

    def BFS(self, startNode):
        print('BFS')
        queue = Queue.Queue(self.T)
        queue.put(startNode)
        while not queue.empty():
            startNode = queue.get()
            self.bfsResult.put(startNode)
            # if not startNode in self.bfsResult:
            #     self.bfsResult.append(startNode)
            while not self.bfsTrunks[startNode].empty():
                queue.put(self.bfsTrunks[startNode].get())

    def printResult(self, queue):
        result = ''
        resultList = [0] * self.N
        index = -1
        while not queue.empty():
            r = queue.get()
            if not r in resultList:
                result = str(r) + ' '
                index += 1
                resultList[index] = r
        print(result.strip())


if __name__=='__main__':
    dfsbfs = DFSBFS()