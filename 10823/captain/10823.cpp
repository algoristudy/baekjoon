#include <string>
#include <sstream>
#include <iostream>

using namespace std;

int main() {
	string s = "" , line, n;
	int total = 0;
	
	while (getline(cin, line)) {
		if (!line.length()) break;
		s += line;
	}
	stringstream ss(s);
	while (getline(ss, n, ',')) {
		total += stoi(n);
	}
	cout << total;
	
	return 0;
}