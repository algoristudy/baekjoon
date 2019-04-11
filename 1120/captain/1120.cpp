#include <iostream>
#include <string>
using namespace std;

int main() {
	string a, b;
	int min_cnt = 51;
	cin >> a >> b;
	for (int i = 0; i <= b.length() - a.length(); i++) {
		int cnt = 0;
		for (int j = 0; j < a.length(); j++) {
			if (a[j] != b[j + i]) cnt++;
		}
		if (min_cnt > cnt) min_cnt = cnt;
	}
	cout << min_cnt << "\n";
	return 0;
}
