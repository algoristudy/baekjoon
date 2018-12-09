#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;

int DP[101][101][101];

int max(int a, int b) {
    return a > b ? a : b;
}

int LCS(string str1, string str2, string str3) {
    int i, j, k;
    for (i = 1; i < str1.size() + 1; i++) {
        for (j = 1; j < str2.size() + 1; j++) {
            for (k = 1; k < str3.size() + 1; k++) {
                if (str1[i - 1] == str2[j - 1] && str1[i - 1] == str3[k - 1]) {
                    DP[k][j][i] = DP[k - 1][j - 1][i - 1] + 1;
                } else {
                    DP[k][j][i] = max(DP[k - 1][j][i], max(DP[k][j - 1][i], DP[k][j][i - 1]));
                }
            }
        }
    }
    return DP[--k][--j][--i];
}

int main() {
    string str1, str2, str3;
    cin >> str1 >> str2 >> str3;
    int count = LCS(str1, str2, str3);
    cout << count << endl;
    return 0;
}