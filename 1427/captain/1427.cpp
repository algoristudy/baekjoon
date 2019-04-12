#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(int a, int b) {
	return a > b;
}

int main() {
	char s[11];
	vector<char> v;
	scanf("%s", s);
	for (int i = 0; s[i] != '\0'; i++) {
		v.push_back(s[i]);
	}
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < v.size(); i++) {
		printf("%c", v[i]);
	}
	printf("\n");

	return 0;
}
