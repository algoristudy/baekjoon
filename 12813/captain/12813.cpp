#include <bitset>
#include <iostream>

using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	bitset<100000> A(a), B(b);

	cout << (A & B) << '\n';
	cout << (A | B) << '\n';
	cout << (A ^ B) << '\n';
	cout << ~(A) << '\n';
	cout << ~(B) << '\n';
	return 0;
}