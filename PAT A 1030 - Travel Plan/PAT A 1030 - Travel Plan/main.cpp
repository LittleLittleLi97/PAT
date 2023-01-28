//
//  main.cpp
//  PAT A 1030 - Travel Plan
//
//  Created by 97 on 2019/10/11.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define MaxSize 510
#define INF 1000000000
using namespace std;

int LenGraph[MaxSize][MaxSize];
int CostGraph[MaxSize][MaxSize];
bool ever[MaxSize];
int dis[MaxSize];
vector<int> Pre[MaxSize];
vector<int> Path, tempPath;
int N, M, Start, End;
int minLen = INF;
int minCost = INF;

void Dijkstra(int st){
    fill(dis, dis + MaxSize, INF);
    dis[st] = 0;
    for (int i = 0; i < N; i++) {
        int u = -1;
        int mindis = INF;
        for (int j = 0; j < N; j++) {
            if (ever[j] == false && dis[j] < mindis) {
                mindis = dis[j];
                u = j;
            }
        }
        if (u == -1) return;
        ever[u] = true;
        for (int v = 0; v < N; v++) {
            if (ever[v] == false) {
                if (LenGraph[u][v] + dis[u] < dis[v]) {
                    dis[v] = LenGraph[u][v] + dis[u];
                    Pre[v].clear();
                    Pre[v].push_back(u);
                }else if (LenGraph[u][v] + dis[u] == dis[v]) {
                    Pre[v].push_back(u);
                }
            }
        }
    }
}

void DFS(int st){
    if (st == Start) {
        tempPath.push_back(st);
        int len = 0;
        int cost = 0;
        for (long int i = tempPath.size() - 1; i >= 1 ; i--) {
            int now = tempPath[i];
            int next = tempPath[i - 1];
            len += LenGraph[now][next];
            cost += CostGraph[now][next];
        }
        if (len < minLen) {
            minLen = len;
            minCost = cost;
            Path = tempPath;
        }else if (len == minLen && cost < minCost) {
            minCost = cost;
            Path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(st);
    for (int i = 0; i < Pre[st].size(); i++) {
        DFS(Pre[st][i]);
    }
    tempPath.pop_back();
}

int main(){
    scanf("%d%d%d%d", &N, &M, &Start, &End);
    fill(LenGraph[0], LenGraph[0] + MaxSize * MaxSize, INF);
    fill(CostGraph[0], CostGraph[0] + MaxSize * MaxSize, INF);
    for (int i = 0; i < M; i++) {
        int a, b, len, cost; scanf("%d%d%d%d", &a, &b, &len, &cost);
        LenGraph[a][b] = LenGraph[b][a] = len;
        CostGraph[a][b] = CostGraph[b][a] = cost;
    }
    Dijkstra(Start);
    DFS(End);
    for (long int i = Path.size() - 1; i >= 0; i--) {
        printf("%d", Path[i]);
        if (i != 0) printf(" ");
    }
    printf(" %d %d", minLen, minCost);
}
