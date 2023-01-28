//
//  main.cpp
//  PAT A 1087 - All Roads Lead to Rome
//
//  Created by 97 on 2019/12/1.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#define MaxSize 210
#define INF 1000000000
using namespace std;

int G[MaxSize][MaxSize];
int Weight[MaxSize];
map<string, int> mStringToInt;
map<int, string> mIntToString;
bool ever[MaxSize];
int dis[MaxSize];
vector<int> Pre[MaxSize];
vector<int> Path, tempPath;
int MapSize = 1;
int N, K;
char Start[5];
int outNum = 0;
int outCost = INF;
int outHappiness = -1;
int outAverageHappiness = -1;

void Dijkstra(int st){
    fill(dis, dis + MaxSize, INF);
    dis[st] = 0;
    for (int i = 0; i < N; i++) {
        int u = -1;
        int mindis = INF;
        for (int j = 1; j < MapSize; j++) {
            if (ever[j] == false && dis[j] < mindis) {
                mindis = dis[j];
                u = j;
            }
        }
        if (u == -1) return;
        ever[u] = true;
        for (int v = 1; v < MapSize; v++) {
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
    if (st == mStringToInt[Start]) {
        tempPath.push_back(st);
        int cost = 0;
        int happiness = 0;
        for (int i = 0; i < tempPath.size() - 1; i++) {
            cost += G[tempPath[i]][tempPath[i + 1]];
            happiness += Weight[tempPath[i]];
        }
        int averageHappiness = happiness / (tempPath.size() - 1);
        if (cost < outCost) {
            outCost = cost;
            outHappiness = happiness;
            outAverageHappiness = averageHappiness;
            outNum = 1;
            Path = tempPath;
        }else if (cost == outCost) {
            outNum++;
            if (happiness > outHappiness) {
                outHappiness = happiness;
                outAverageHappiness = averageHappiness;
                Path = tempPath;
            }else if (happiness == outHappiness) {
                if (averageHappiness > outAverageHappiness) {
                    outAverageHappiness = averageHappiness;
                    Path = tempPath;
                }
            }
        }
        tempPath.pop_back();
    }
    tempPath.push_back(st);
    for (int i = 0; i < Pre[st].size(); i++) {
        DFS(Pre[st][i]);
    }
    tempPath.pop_back();
}

void Change(string a){
    if (mStringToInt[a] == 0) {
        mStringToInt[a] = MapSize;
        mIntToString[MapSize] = a;
        MapSize++;
    }
}

int main(){
    scanf("%d%d", &N, &K);
    scanf("%s", Start);
    Change(Start);
    for (int i = 0; i < N - 1; i++) {
        char where[5]; int t;
        scanf("%s %d", where, &t);
        Change(where);
        Weight[mStringToInt[where]] = t;
    }
    fill(G[0], G[0] + MaxSize * MaxSize, INF);
    for (int i = 0; i < K; i++) {
        char a[5], b[5]; int cost;
        scanf("%s %s %d", a, b, &cost);
        int x = mStringToInt[a];
        int y = mStringToInt[b];
        G[x][y] = G[y][x] = cost;
    }
    Dijkstra(mStringToInt[Start]);
    DFS(mStringToInt["ROM"]);
    printf("%d %d %d %d\n", outNum, outCost, outHappiness, outAverageHappiness);
    for (long int i = Path.size() - 1; i >= 0; i--) {
        printf("%s", mIntToString[Path[i]].c_str());
        if (i != 0) printf("->");
    }
}
