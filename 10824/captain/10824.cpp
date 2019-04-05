#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
	string line, s, n[5];
	getline(cin, line);
	stringstream ss(line);
	char i = 0;
	long long total = 0;
	while (getline(ss, s, ' ')) {
		n[i++] = s;
	}
	total += stoll(n[0] + n[1]);
	total += stoll(n[2] + n[3]);
	cout << total;
	return 0;
}