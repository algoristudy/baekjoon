#include <string>
#include <sstream>
#include <iostream>

using namespace std;

int main() {
	string s, n;
	cin >> s;
	stringstream ss(s);
	int count = 0;
	while (getline(ss, n, ',')) {
		count++;
	}
	cout << count;
}