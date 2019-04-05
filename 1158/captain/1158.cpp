#include <iostream>
#include <unordered_map>
#include <cstdio>
#include <vector>

using namespace std;

struct List
{
	int before;
	int next;
};

vector<List> l;

int getNext(int index)
{
	return l[index].next;
}

void del(int index)
{
	int before = l[index].before;
	int next = l[index].next;
	l[before].next = next;
	l[next].before = before;
}

int main()
{
	int N, M;
	cin >> N >> M;
	int remain = N;
	int result[5000];

	l.resize(N);
	for (int i = 0; i < N; i++)
	{
		l[i].before = i - 1 < 0 ? N - 1 : i - 1;
		l[i].next = i + 1 == N ? 0 : i + 1;
	}
	int current = M - 1;
	result[0] = current + 1;
	del(current);
	remain--;
	for (int i = 1; i < N; i++)
	{
		int count = remain >= M ? M : M - remain;
		for (int j = 0; j < count; j++)
		{
			current = getNext(current);
		}
		result[i] = current + 1;
		del(current);
		remain--;
	}
	//<3, 6, 2, 7, 5, 1, 4>
	printf("<");
	for (int i = 0; i < N - 1; i++)
	{
		printf("%d, ", result[i]);
	}
	printf("%d>", result[N - 1]);
	return 0;
}