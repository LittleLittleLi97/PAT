//
//  main.cpp
//  PAT A 1111 - Online Map
//
//  Created by 97 on 2019/12/3.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define MaxSize 510
#define INF 1000000000
using namespace std;

void Print_Path(vector<int> v);

int GLength[MaxSize][MaxSize];
int GTime[MaxSize][MaxSize];
bool ever[MaxSize];
int dis[MaxSize];
int spend[MaxSize];
vector<int> disPre[MaxSize];
vector<int> Path, tempPath;
vector<int> timePre[MaxSize];
int N, M;
int Start, End;
int outDis_Dis = INF;
int outDis_Time = INF;
long int outIntersection = INF;
vector<int> timePath, timeTempPath;
int outTime = INF;
long int outTime_Intersection = INF;

void Dijstra_Length(int st){
    fill(ever, ever + MaxSize, false);
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
                if (GLength[u][v] + dis[u] < dis[v]) {
                    dis[v] = GLength[u][v] + dis[u];
                    disPre[v].clear();
                    disPre[v].push_back(u);
                }else if (GLength[u][v] + dis[u] == dis[v]) {
                    disPre[v].push_back(u);
                }
            }
        }
    }
}

void DFS_Length(int st){
    if (st == Start) {
        tempPath.push_back(st);
        int tDis = 0;
        int tTime = 0;
        for (int i = 0; i < tempPath.size() - 1; i++) {
            tDis += GLength[tempPath[i]][tempPath[i + 1]];
            tTime += GTime[tempPath[i]][tempPath[i + 1]];
        }
        if (tDis < outDis_Dis) {
            outDis_Dis = tDis;
            outDis_Time = tTime;
            outIntersection = tempPath.size();
            Path = tempPath;
        }else if (tDis == outDis_Dis) {
            if (tTime < outDis_Time) {
                outDis_Time = tTime;
                outIntersection = tempPath.size();
                Path = tempPath;
            }else if (tTime == outDis_Time) {
                if (tempPath.size() < outIntersection) {
                    outIntersection = tempPath.size();
                    Path = tempPath;
                }
            }
        }
        tempPath.pop_back();
    }
    tempPath.push_back(st);
    for (int i = 0; i < disPre[st].size(); i++) {
        DFS_Length(disPre[st][i]);
    }
    tempPath.pop_back();
}

void Dijkstra_Time(int st){
    fill(dis, dis + MaxSize, INF);
    fill(ever, ever + MaxSize, false);
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
                if (GTime[u][v] + dis[u] < dis[v]) {
                    dis[v] = GTime[u][v] + dis[u];
                    timePre[v].clear();
                    timePre[v].push_back(u);
                }else if (GTime[u][v] + dis[u] == dis[v]) {
                    timePre[v].push_back(u);
                }
            }
        }
    }
}

void DFS_Time(int st){
    if (st == Start) {
        timeTempPath.push_back(st);
        int tTime = 0;
        for (int i = 0; i < timeTempPath.size() - 1; i++) {
            tTime += GTime[timeTempPath[i]][timeTempPath[i + 1]];
        }
//        Print_Path(timeTempPath); printf("\n");
//        printf("time %d - size %ld", tTime, timeTempPath.size()); printf("\n");
        if (tTime < outTime) {
            outTime = tTime;
            outTime_Intersection = timeTempPath.size();
            timePath = timeTempPath;
        }else if (tTime == outTime) {
            if (timeTempPath.size() < outTime_Intersection) {
                outTime_Intersection = timeTempPath.size();
                timePath = timeTempPath;
            }
        }
        timeTempPath.pop_back();
    }
    timeTempPath.push_back(st);
    for (int i = 0; i < timePre[st].size(); i++) {
        DFS_Time(timePre[st][i]);
    }
    timeTempPath.pop_back();
}

void Print_Path(vector<int> v){
    for (long int i = v.size() - 1; i >= 0; i--) {
        printf("%d", v[i]);
        if (i != 0) {
            printf(" -> ");
        }
    }
}

int main(){
    scanf("%d %d", &N, &M);
    fill(GLength[0], GLength[0] + MaxSize * MaxSize, INF);
    fill(GTime[0], GTime[0] + MaxSize * MaxSize, INF);
    for (int i = 0; i < M; i++) {
        int x, y, flag, len, t;
        scanf("%d%d%d%d%d", &x, &y, &flag, &len, &t);
        GLength[x][y] = GLength[y][x] = len;
        GTime[x][y] = GTime[y][x] = t;
    }
    scanf("%d%d", &Start, &End);
    Dijstra_Length(Start);
    DFS_Length(End);
    Dijkstra_Time(Start);
    DFS_Time(End);
//    cout << timePre[1][0] << endl;
    if (Path == timePath) {
        printf("Distance = %d; Time = %d: ", outDis_Dis, outTime);
        Print_Path(Path);
    }else {
        printf("Distance = %d: ", outDis_Dis);
        Print_Path(Path);
        printf("\n");
        printf("Time = %d: ", outTime);
        Print_Path(timePath);
    }
}
