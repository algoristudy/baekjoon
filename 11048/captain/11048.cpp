// #include <cstdio>
// using namespace std;

// int DP[1001][1001];

// int max(int a, int b) {
// 	return a > b ? a : b;
// }

// int main() {
// 	int n, m;
// 	scanf("%d %d", &n, &m); 
// 	for (int i = 0; i <= m; i++) DP[0][i] = 0;
// 	for (int i = 1; i <= n; i++) DP[i][0] = 0;
// 	for (int i = 1; i <= n; i++) {
// 		for (int j = 1; j <= m; j++) {
// 			scanf("%d", &DP[i][j]);
// 		}
// 	}
// 	for (int i = 1; i <= n; i++) {
// 		for (int j = 1; j <= m; j++) {
// 			DP[i][j] = DP[i][j] + max(DP[i][j - 1], DP[i - 1][j]);
// 		}
// 	}
// 	printf("%d\n", DP[n][m]);
// 	return 0;
// }

#include <cstdio>
#include <vector>
using namespace std;

vector<int> DP(1001, 0);

char buf[1<<19];
int idx = 1<<19;

int max(int a, int b) {
	return a > b ? a : b;
}

inline char read()
{
    if (idx == 1<<19)
    {
        fread(buf, 1, 1<<19, stdin);
        idx = 0;
    }
    return buf[idx++];
}

inline int readInt()
{
    int sum = 0;
    char now = read();
    
    while (now == 10 || now == 32) now = read();
    while (now >= 48 && now <= 57)
    {
        sum = sum*10 + now-48;
        now = read();
    }
    
    return sum;
}

int main() {
	int n = readInt();
	int m = readInt();
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= m; j++) {
			DP[j] = max(DP[j - 1], DP[j]) + readInt();
		}
	}
	printf("%d\n", DP[m]);
	return 0;
}