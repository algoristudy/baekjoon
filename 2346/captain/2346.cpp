#include<stdio.h>
#include<vector>

using namespace std;

vector<int> balloon(1000, 0);
int result[1000];
int count;

int getNextIndex(int index, int count) {
	int num = balloon[index];
	balloon[index] = 0;
	if (num > 0) {
		while (num != 0)
		{
			if (++index == count) index = 0;
			if (balloon[index] == 0) continue;
			num--;
		}

	}
	else if (num < 0) {
		while (num != 0)
		{
			if (--index == -1) index = count - 1;
			if (balloon[index] == 0) continue;
			num++;
		}
	}
	return index;
	
}

int main() {
	int count;
	scanf("%d", &count);
	int n;
	for (int i = 0; i < count; i++) {
		scanf("%d", &n);
		balloon[i] = n;
	}
	int index = 0;
	result[0] = index + 1;
	for (int i = 1; i < count; i++) {
		index = getNextIndex(index, count);
		result[i] = index + 1;
	}
	for (int i = 0; i < count; i++) {
		printf("%d ", result[i]);
	}

	return 0;
}