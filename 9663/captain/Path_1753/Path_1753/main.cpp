//
//  main.cpp
//  Path_1753
//
//  Created by 이희석 on 2018. 11. 25..
//  Copyright © 2018년 Captains. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321
#define MAX_V 20001
#define MAX_E 300001

using namespace std;
int start_node_num, V, E;

typedef struct NODE {
    int end;
    int val;
};

// 각 노드의 엣지를 저장하는 벡터
// 0번 인덱스는 버린다.
vector<NODE> EDGE_arr[MAX_E];
// 출발 노드에서부터의 거리를 저장하는 배열
int dist[MAX_V] = { 0 };

void dijkstra() {
    priority_queue< pair<int,int> > pq;
    pq.push({ 0, start_node_num });
    
    // 노드의 거리 갱신은 V-1 번 만큼 하면 된다.
    while (!pq.empty()){
        int now_node = pq.top().second;
        int cost = -1 * pq.top().first;
        pq.pop();
        
        // 현재 노드에서 부터 주변에 있는 얘들의 값을 갱신한다.
        for (int k = 0; k < EDGE_arr[now_node].size(); k++) {
            int new_val = dist[now_node] + EDGE_arr[now_node][k].val;
            int before_val = dist[EDGE_arr[now_node][k].end];
            
            // 현재 노드로 부터 연결된 엣지의 목적지까지 가는 거리와 기존의 거리를 비교하여,
            // 기존의 것이 더 크면 값을 갱신한다.
            if (new_val < before_val) {
                dist[EDGE_arr[now_node][k].end] = new_val;
                pq.push({ -1*new_val, EDGE_arr[now_node][k].end });
            }
        }
        
    }
}

int main(){
    cin >> V >> E >> start_node_num;
    
    int from, to, val;
    // 간선 연결
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &from, &to, &val);
        EDGE_arr[from].push_back(NODE{ to, val });
    }
    
    // 간선간의 거리 초기화
    for (int i = 1; i <= V; i++) {
        dist[i] = INF;
    }
    dist[start_node_num] = 0;
    
    // 벨만-포드 알고리즘은 복잡도가 O(V*E) 이기 때문에, 이 문제에서는 너무 크다.
    // 다익스트라 알고리즘을 진행한다.
    dijkstra();
    
    // 값을 출력한다.
    for (int i = 1; i <= V; i++) {
        if (dist[i] != INF) printf("%d\n", dist[i] );
        else printf("INF\n");
    }
    
    return 0;
}
