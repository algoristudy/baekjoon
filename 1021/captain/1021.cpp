#include <cstdio>
using namespace std;

struct element {
	int value;
	int pre;
	int next;
	bool isEmpty = true;
};

class Queue {
	private:
		element queue[101];
		int size = 0;
		int index = -1;
		int front = 0;
		int end = 0;
		void setNextIndex() {
			int cnt = 0;
			do {
				index = index == 100 ? 0 : index + 1;
				if (++cnt > 100) break;
			} while (!queue[index].isEmpty);
		}
	public:
		Queue() {}
		void push(int value) {
			setNextIndex();
			queue[index].value = value;
			queue[index].pre = end;
			queue[index].next = front;
			queue[index].isEmpty = false;
			queue[end].next = index;
			queue[front].pre = index;
			end = index;
			size++;
		}
		void pop() {
			queue[front].isEmpty = true;
			int next = queue[front].next;
			int pre = queue[front].pre;
			queue[next].pre = pre;
			queue[pre].next = next;
			front = next;
			size--;
		}
		void left() {
			front = queue[front].next;
			end = queue[end].next;
		}
		void right() {
			front = queue[front].pre;
			end = queue[end].pre;
		}
		// int front() {
		// 	return queue[front].value;
		// }
		// int end() {
		// 	return queue[end].value;
		// }
		int find(int value) {
			int cnt = 0;
			int f = front;
			while (queue[f].value != value) {
				cnt++;
				f = queue[f].next;
			}
			return cnt;
		}
		int solve(int value) {
			int cnt = 0, find_cnt;
			find_cnt = find(value);
			if (find_cnt <= size / 2) {
				cnt = find_cnt;
				while(find_cnt--) {
					left();
				}
				pop();
			} else {
				find_cnt = size - find_cnt;
				cnt = find_cnt;
				while (find_cnt--) {
					right();
				}
				pop();
			}
			return cnt;
		}
};

int main() {
	int n, m, k, cnt = 0;
	Queue queue;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) queue.push(i);
	for (int i = 0; i < m; i++) {
		scanf("%d", &k);
		cnt += queue.solve(k);
	}
	printf("%d\n", cnt);
	return 0;
}
