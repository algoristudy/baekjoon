#include<stdio.h>
#include<vector>
#include<stdlib.h>
using namespace std;

const int MAX_COUNT = 600001;
vector<char> words;

int main() {
	char word[MAX_COUNT];
	scanf("%s", word);
	int index = 0;
	for (char x : word) {
		if (x == '\0') break;
		words.push_back(x);
		index++;
	}
	int count;
	scanf("%d", &count);
	for (int i = 0; i < count; i++) {
		char command;
		scanf(" %c", &command);
		if (command == 'L') {
			if (index > 0) index--;
		}
		else if (command == 'D') {
			if (index != words.size()) index++;
		}
		else if (command == 'B') {
			if (index > 0) {
				index--;
				words.erase(words.begin() + index);
			}
		}
		else if (command == 'P') {
			char alphabet;
			scanf(" %c", &alphabet);
			words.insert(words.begin() + index, alphabet);
			index++;
		}
	}
	for (int i = 0; i < words.size(); i++) {
		printf("%c", words[i]);
	}
	printf("\n");
	return 0;
}