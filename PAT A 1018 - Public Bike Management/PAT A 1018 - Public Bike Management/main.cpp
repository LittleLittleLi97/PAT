//
//  main.cpp
//  PAT A 1018 - Public Bike Management
//
//  Created by 97 on 2019/11/10.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#define MaxSize 510
#define INF 1000000000
using namespace std;

int G[MaxSize][MaxSize];
int Weight[MaxSize];
bool ever[MaxSize];
vector<int> Pre[MaxSize];
int dis[MaxSize];
int Capacity, N, Save, M;
int minNeed = INF;
int minTake = INF;
vector<int> Path, tempPath;

void Dijkstra(int st){
    fill(dis, dis + MaxSize, INF);
    dis[st] = 0;
    for (int i = 0; i <= N; i++) {
        int u = -1;
        int mindis = INF;
        for (int j = 0; j <= N; j++) {
            if (ever[j] == false && dis[j] < mindis) {
                mindis = dis[j];
                u = j;
            }
        }
        if (u == -1) return;
        ever[u] = true;
        for (int v = 0; v <= N; v++) {
            if (ever[v] == false) {
                if (G[u][v] + dis[u] < dis[v]) {
                    dis[v] = G[u][v] + dis[u];
                    Pre[v].clear();
                    Pre[v].push_back(u);
                }else if (G[u][v] + dis[u] == dis[v]) {
                    Pre[v].push_back(u);
                }
            }
        }
    }
}

void DFS(int st){
    if (st == 0) {
        tempPath.push_back(st);
        int half = Capacity / 2;
        int take = 0;
        int need = 0;
        for (long int i = tempPath.size() - 2; i >= 0; i--) {
//            printf("where: %d now: %d weight:%d\n", i, tempPath[i], Weight[tempPath[i]]);
            int t = Weight[tempPath[i]] - half;
            if (t > 0) {
                take += t;
            }else {
                if (abs(t) - take > 0) {
                    need += abs(t) - take;
                    take = 0;
                }else {
                    take = take - abs(t);
                }
            }
        }
        if (need < minNeed) {
            minNeed = need;
            minTake = take;
            Path = tempPath;
        }else if (need == minNeed && take < minTake) {
            minTake = take;
            Path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(st);
    for (int i = 0; i < Pre[st].size(); i++) {
//        printf("Enter: %d\n", Pre[st][i]);
        DFS(Pre[st][i]);
    }
    tempPath.pop_back();
}

int main(){
    scanf("%d%d%d%d", &Capacity, &N, &Save, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &Weight[i]);
    }
    fill(G[0], G[0] + MaxSize * MaxSize, INF);
    for (int i = 0 ; i < M; i++) {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        G[a][b] = G[b][a] = c;
    }
    Dijkstra(0);
    DFS(Save);
    printf("%d ", minNeed);
    for (long int i = Path.size() - 1; i >= 0; i--) {
        printf("%d", Path[i]);
        if (i != 0) printf("->");
    }
    printf(" %d", minTake);
}
