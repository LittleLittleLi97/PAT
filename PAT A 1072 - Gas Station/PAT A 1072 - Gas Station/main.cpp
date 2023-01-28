//
//  main.cpp
//  PAT A 1072 - Gas Station
//
//  Created by 97 on 2019/11/30.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <string>
#include <map>
#define MaxSize 1020
#define INF 1000000000
using namespace std;

int G[MaxSize][MaxSize];
map<string, int> mStationToInt;
map<int, string> mIntToStation;
vector<int> Station;
bool ever[MaxSize];
int dis[MaxSize];
int mapSize = 1;
int N, M, K, D;
string outStation;
double outMinDis = -1;
double outTotal = INF;

void Dijkstra(int st){
    fill(dis, dis + MaxSize, INF);
    fill(ever, ever + MaxSize, false);
    dis[st] = 0;
    for (int i = 0; i < mapSize; i++) {
        int u = -1;
        int mindis = INF;
        for (int j = 1; j < mapSize; j++) {
            if (ever[j] == false && dis[j] < mindis) {
                mindis = dis[j];
                u = j;
            }
        }
        if (u == -1) return;
        ever[u] = true;
        for (int v = 1; v < mapSize; v++) {
            if (ever[v] == false) {
                if (G[u][v] + dis[u] < dis[v]) {
                    dis[v] = G[u][v] + dis[u];
                }
            }
        }
    }
}

int Change(string a){
    if (mStationToInt[a] == 0) {
        mStationToInt[a] = mapSize;
        mIntToStation[mapSize] = a;
        mapSize++;
        if (a[0] == 'G') Station.push_back(mStationToInt[a]);
    }
    return mStationToInt[a];
}

int main(){
    scanf("%d%d%d%d", &N, &M, &K, &D);
    fill(G[0], G[0] + MaxSize * MaxSize, INF);
    for (int i = 0; i < K; i++) {
        char a[5], b[5]; int dis;
        scanf("%s %s %d", a, b, &dis);
        int x = Change(a); int y = Change(b);
        G[x][y] = G[y][x] = dis;
    }
//    cout << mapSize << endl;
//    cout << Station.size() << endl;
    for (int i = 0; i < Station.size(); i++) {
        Dijkstra(Station[i]);
//        cout << "OK" << endl;
        double total = 0;
        double mindis = INF;
        bool flag = false;
        for (int j = 1; j < mapSize; j++) {
//            cout << dis[j] << " ";
            if (mIntToStation[j][0] != 'G' && dis[j] != INF) {
                if (dis[j] > D) {
                    flag = true;
                    break;
                }
                total += dis[j];
                if (dis[j] < mindis) {
                    mindis = dis[j];
                }
            }
        }
        if (flag == false) {
            if (mindis > outMinDis) {
                outMinDis = mindis;
                outTotal = total;
                outStation = mIntToStation[Station[i]];
            }else if (mindis == outMinDis && total < outTotal) {
                outTotal = total;
                outStation = mIntToStation[Station[i]];
            }
        }
    }
    if (outMinDis != -1) {
        printf("%s\n", outStation.c_str());
        printf("%.1lf %.1lf", outMinDis, outTotal / N);
    }else printf("No Solution");
}
