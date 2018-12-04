import queue as Queue

class Search():
    def __init__(self):
        with open('../input.txt', 'r') as f:
            self.N, self.T, self.startNode = map(int, f.readline().strip().split(' '))
            self.moves = [[0, 0] for _ in range(self.T)] # 간선을 넣을 리스트 초기화
            self.queueSize = [0] * (self.N + 1)
            self.result = Queue.Queue()
            for i in range(self.T):
                self.moves[i][0], self.moves[i][1] = map(int, f.readline().strip().split(' '))
                self.queueSize[self.moves[i][0]] += 1
                self.queueSize[self.moves[i][1]] += 1
            # DFS
            self.initTrunks()
            self.stack = [self.startNode]
            while self.stack:
                self.DFS()
            self.printResult()
            # BFS 
            self.initTrunks()
            self.queue = Queue.Queue(self.T)
            self.queue.put(self.startNode)
            self.BFS()
            self.printResult()

    
    def initTrunks(self):
        self.trunks = [Queue.PriorityQueue(self.queueSize[i]) for i in range(self.N + 1)]
        for move in self.moves:
            self.trunks[move[0]].put(move[1])
            self.trunks[move[1]].put(move[0])
        self.check = [True] * (self.N + 1)
        self.result.put(self.startNode)
        self.check[self.startNode] = False

    def DFS(self):
        startNode = self.stack[-1]
        while not self.trunks[startNode].empty():
            nextNode = self.trunks[startNode].get()
            if self.check[nextNode]:
                self.result.put(nextNode)
                self.check[nextNode] = False
                self.stack.append(nextNode)
                return
        self.stack.pop()

    def BFS(self):
        while not self.queue.empty():
            startNode = self.queue.get()
            while not self.trunks[startNode].empty():
                nextNode = self.trunks[startNode].get()
                if self.check[nextNode]:
                    self.result.put(nextNode)
                    self.check[nextNode] = False
                    self.queue.put(nextNode)


    def printResult(self):
        result = ''
        while not self.result.empty():
            result += str(self.result.get()) + ' '
        print(result.strip())

if __name__=='__main__':
    search = Search()