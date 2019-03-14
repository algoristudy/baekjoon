#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
const unsigned int MAX_COUNT = 500000;

using namespace std;

unordered_map<string, bool> dic;

int main() {
	int N, M;
	vector<string> list;
	list.resize(MAX_COUNT);

	scanf("%d %d", &N, &M);
	
	string word;
	while (N--) {
		cin >> word;
		dic[word] = true;
	}
	int index = 0;
	while (M--) {
		cin >> word;
		if (dic[word]) {
			list[index] = word;
			index++;
		}
	}
	list.resize(index);
	sort(list.begin(), list.end());
	printf("%d\n", index);
	for (int i = 0; i < index; i++) {
		cout << list[i] << '\n';
	}

	return 0;
}