#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <vector>
 
#define MAX 1000*1000*1000 + 1
using namespace std;
 
int min(int a, int b) { return (a < b ? a : b); }
 
int init(vector<int>& tree, vector<int>&arr, int node, int start, int end) {
    if (start == end) return tree[node] = arr[start];
    else return tree[node] = min(init(tree, arr, node * 2, start, (start + end) / 2), init(tree, arr, node * 2 + 1, (start + end) / 2 + 1, end));
}
 
int retMinimun(vector<int>& tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) return MAX;
    if (left <= start && end <= right) return tree[node];
    return min(retMinimun(tree, node * 2, start, (start + end) / 2, left, right), retMinimun(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}
 
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    vector<int> arr(N);
 
    int h = (int)ceil(log2(N));
    int tree_size = (1 << (h + 1));
    vector<int> tree(tree_size, MAX);
 
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
 
    init(tree, arr, 1, 0, N - 1);
    int a, b;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n",retMinimun(tree, 1, 0, N - 1, a - 1, b - 1));
    }
    return 0;
}