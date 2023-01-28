//
//  main.cpp
//  PAT A 1003 - Emergency
//
//  Created by 97 on 2019/10/2.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
#define MaxSize 510
#define INF 1000000000
using namespace std;

int G[MaxSize][MaxSize];
int Weight[MaxSize];
bool ever[MaxSize];
int dis[MaxSize];
int gather[MaxSize];
int road[MaxSize];
int N, M, now, save;

void Dijkstra(int st){
    fill(dis, dis + MaxSize, INF);
    dis[st] = 0;
    gather[st] = Weight[st];
    road[st] = 1;
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
                if (G[u][v] + dis[u] < dis[v]) {
                    dis[v] = G[u][v] + dis[u];
                    gather[v] = gather[u] + Weight[v];
                    road[v] = road[u];
                }else if (G[u][v] + dis[u] == dis[v]) {
                    if (gather[u] + Weight[v] > gather[v]) {
                        gather[v] = gather[u] + Weight[v];
                    }
                    road[v] += road[u];
                }
            }
        }
    }
}

int main(){
    scanf("%d%d%d%d", &N, &M, &now, &save);
    for (int i = 0; i < N; i++) {
        scanf("%d", &Weight[i]);
    }
    fill(G[0], G[0] + MaxSize * MaxSize, INF);
    for (int i = 0; i < M; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        G[a][b] = G[b][a] = c;
    }
    Dijkstra(now);
    printf("%d %d", road[save], gather[save]);
}
