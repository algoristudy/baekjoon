#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int arr[21];

int main() {
	int n, k, i, idx = 0;
	string str_arr, token;
	cin >> n >> k >> str_arr;
	stringstream ss(str_arr);
	while (getline(ss, token, ',')) {
		arr[idx++] = atoi(token.c_str());
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < n - i; j++) {
			arr[j] = arr[j + 1] - arr[j];
		}
	}
	for (i = 0; i < n - k - 1; i++) {
		cout << arr[i] << ',';
	}
	cout << arr[i] << '\n';
	return 0;
}


// #include <cstdio>

// using namespace std;

// int arr[21];

// int main() {
// 	int n, k;
// 	scanf("%d %d", &n, &k);
// 	for (int i = 0; i < n; i++) scanf("%d", arr + i);
// 	for (int i = 0; i < n; i++) printf("%d ", arr[i]);
// 	return 0;
// }