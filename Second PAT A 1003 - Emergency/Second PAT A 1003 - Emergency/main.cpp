//
//  main.cpp
//  Second PAT A 1003 - Emergency
//
//  Created by 97 on 2021/9/20.
//  Copyright © 2021 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

//const int MAXSIZE = 510;
//const int INF = 1000000000;
//
//int N, M, start, ter;
//int Vteams[MAXSIZE];
//int G[MAXSIZE][MAXSIZE];
//
//int d[MAXSIZE];
//bool ever[MAXSIZE];
//int num[MAXSIZE];
//int numPath[MAXSIZE];
//
//void Dijkstra(int s) {
//    fill(d, d + MAXSIZE, INF);
//    d[s] = 0;
//    numPath[s] = 1;
//    num[s] = Vteams[s];
//    for (int i = 0; i < N; i++) {
//        int u = -1;
//        int min = INF;
//        for (int j = 0; j < N; j++) {
//            if (d[j] < min && ever[j] == false) {
//                u = j;
//                min = d[j];
//            }
//        }
//        if (u == -1) return;
//        ever[u] = true;
//        for (int v = 0; v < N; v++) {
//            if (ever[v] == false && G[u][v] + d[u] < d[v]) {
//                d[v] = G[u][v] + d[u];
//                num[v] = num[u] + Vteams[v];
//                numPath[v] = numPath[u];
//            }else if (ever[v] == false && G[u][v] + d[u] == d[v]) {
//                if (num[u] + Vteams[v] > num[v]) num[v] = num[u] + Vteams[v];
//                numPath[v] += numPath[u];
//            }
//        }
//    }
//}
//
//int main() {
//    fill(G[0], G[0] + MAXSIZE * MAXSIZE, INF);
//    scanf("%d%d%d%d", &N, &M, &start, &ter);
//    for (int i = 0; i < N; i++) {
//        scanf("%d", &Vteams[i]);
//    }
//    for (int i = 0; i < M; i++) {
//        int x, y, e;
//        scanf("%d%d%d", &x, &y, &e);
//        G[x][y] = G[y][x] = e;
//    }
//    Dijkstra(start);
//    printf("%d %d", numPath[ter], num[ter]);
//}

const int MaxSize = 510;
const int INF = 1000000000;

int N, M, current, save;
int Vweight[MaxSize];
int G[MaxSize][MaxSize];

int d[MaxSize];
bool ever[MaxSize];
vector<int> pre[MaxSize];

vector<int> tempPath;
vector<int> Path;
int Vsum = 0;
int countPath = 0;

void Dijkstra(int s) {
    fill(d, d + MaxSize, INF);
    d[s] = 0;
    for (int i = 0; i < N; i++) {
        int u = -1;
        int min = INF;
        for (int j = 0; j < N; j++) {
            if (ever[j] == false && d[j] < min) {
                min = d[j];
                u = j;
            }
        }
        if (u == -1) return;
        ever[u] = true;
        for (int v = 0; v < N; v++) {
            if (ever[v] == false && d[u] + G[u][v] < d[v]) {
                d[v] = d[u] + G[u][v];
                pre[v].clear();
                pre[v].push_back(u);
            }else if (ever[v] == false && d[u] + G[u][v] == d[v]) {
                pre[v].push_back(u);
            }
        }
    }
}

void DFS(int which) {
    if (which == current) {
        tempPath.push_back(which);
        countPath++;
        int tempVsum = 0;
        for (int i = 0; i < tempPath.size(); i++) {
            tempVsum += Vweight[tempPath[i]];
        }
        if (tempVsum > Vsum) {
            Vsum = tempVsum;
            Path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(which);
    for (int i = 0; i < pre[which].size(); i++) {
        DFS(pre[which][i]);
    }
    tempPath.pop_back();
}

int main() {
    fill(G[0], G[0] + MaxSize * MaxSize, INF);
    scanf("%d%d%d%d", &N, &M, &current, &save);
    for (int i = 0; i < N; i++) {
        scanf("%d", &Vweight[i]);
    }
    for (int i = 0; i < M; i++) {
        int x, y, e;
        scanf("%d%d%d", &x, &y, &e);
        G[x][y] = G[y][x] = e;
    }
    Dijkstra(current);
    DFS(save);
    printf("%d %d", countPath, Vsum);
}

