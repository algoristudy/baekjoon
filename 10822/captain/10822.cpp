#include <string>
#include <sstream>
#include <iostream>

using namespace std;

int main() {
	string s, n;
	int total = 0;
	cin >> s;
	stringstream ss(s);
	while (getline(ss, n, ',')) {
		total += stoi(n);
	}
	cout << total;
}