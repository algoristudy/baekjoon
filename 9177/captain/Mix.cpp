#include <iostream>
#include <string>

using namespace std;

int DP[201][201];
string str1, str2, str3;
int l1, l2, l3;

int dfs(int i, int j) {
    if (DP[i][j] != -1) return DP[i][j];
    if (i + j == l3 || (i > l1 && j >= l2)) return true;
    auto &ret = DP[i][j] = false;
    if (str1[i] == str3[i + j] && i < l1) ret |= dfs(i + 1, j);
    if (str2[j] == str3[i + j] && j < l2) ret |= dfs(i, j + 1);
    return ret;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> str1 >> str2 >> str3;
        for (int j = 0; j < 201; j++)
            for (int k = 0; k < 201; k++)
                DP[j][k] = -1;
        l1 = str1.size();
        l2 = str2.size();
        l3 = str3.size();
        string result = dfs(0, 0) ? "yes" : "no";
        cout << "Data set " << i + 1 << ": " << result << endl;
    }
}

