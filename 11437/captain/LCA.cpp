#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

const int MAX_NODE = 50001;
const int MAX_MATCH = 10001;
int depth[MAX_NODE] = {0, }, parent[16][MAX_NODE] = {0, }, match[MAX_MATCH][2];
vector<int> v[MAX_NODE];
int maxDepth = 1;

void setDepth(int index, int d) {
    if (depth[index]) return;
    depth[index] = d;
    if (d > maxDepth) {
        maxDepth = d;
    }
    while (!v[index].empty()) {
        if (!parent[0][v[index].back()]) {
            parent[0][v[index].back()] = index;            
        }
        setDepth(v[index].back(), d + 1);
        v[index].pop_back();
    }
}
void getLCA(int node1, int node2) {
    int diff = depth[node1] - depth[node2];
    if (diff < 0) {
        int temp = node2;
        node2 = node1;
        node1 = temp;
        diff *= -1;
    }
    int m, temp;
    while (diff) {
        m = floor(log2(diff));
        node1 = parent[m][node1];
        temp = pow(2, m);
        diff = diff % temp;
    }
    if (node1 == node2) {
        printf("%d\n", node1);
    } else {
        while (parent[0][node1] != parent[0][node2]) {
            node1 = parent[0][node1];
            node2 = parent[0][node2];
        }
        printf("%d\n", parent[0][node1]);
    }
}
int main() {
    int N, M, node1, node2;
    scanf("%d", &N);
    for (int i = 0; i < N - 1; i++) {
        scanf("%d %d", &node1, &node2);
        v[node1].push_back(node2);
        v[node2].push_back(node1);
    }
    setDepth(1, 1);
    parent[0][1] = 0;
    for (int i = 1; i < maxDepth - 1; i++) {
        for (int j = 0; j < N + 1; j++) {
            parent[i][j] = parent[i - 1][parent[i - 1][j]];
        }
    }
    scanf("%d", &M);
    int diff;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &node1, &node2);
        match[i][0] = node1;
        match[i][1] = node2;
    }
    for (int i = 0; i < M; i++) {
        getLCA(match[i][0], match[i][1]);
    }
}