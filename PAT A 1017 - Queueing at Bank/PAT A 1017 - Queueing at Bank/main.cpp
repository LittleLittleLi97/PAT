//
//  main.cpp
//  PAT A 1017 - Queueing at Bank
//
//  Created by 97 on 2019/11/3.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Person {
    int ArriveTime;
    int ProcessTime;
};
vector<Person> v;
int N, K;
int stTime, edTime;
int Windows[110];
int TotalTime = 0;

int ChangeTime(int hh, int mm, int ss){
    return hh * 3600 + mm * 60 + ss;
}

bool cmp(Person a, Person b){
    return a.ArriveTime < b.ArriveTime;
}

int main(){
    stTime = ChangeTime(8, 0, 0);
    edTime = ChangeTime(17, 0, 0);
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) {
        int hh, mm, ss, ptmin; scanf("%d:%d:%d %d", &hh, &mm, &ss, &ptmin);
        int at = ChangeTime(hh, mm, ss);
        int pt = ChangeTime(0, ptmin, 0);
        if (pt > 3600) pt = 3600;
        if (at > edTime) continue;
        v.push_back({at, pt});
    }
    sort(v.begin(), v.end(), cmp);
    fill(Windows, Windows + K, stTime);
//    for (int i = 0; i < v.size(); i++) {
//        cout << v[i].ArriveTime << " " << v[i].ProcessTime << endl;
//    }
    for (int i = 0; i < v.size(); i++) {
        int u = 0; //找到最近的开放窗口
        for (int j = 0; j < K; j++) {
            if (Windows[j] < Windows[u]) u = j;
        }
//        if (v[i].ArriveTime < stTime) {
            if (v[i].ArriveTime <= Windows[u]) {
                TotalTime += Windows[u] - v[i].ArriveTime;
                Windows[u] += v[i].ProcessTime;
            }else {
                Windows[u] = v[i].ArriveTime + v[i].ProcessTime;
            }
//        for (int j = 0; j < K; j++) {
//            cout << Windows[j] << " ";
//        }
//        cout << endl;
//        cout << (double)TotalTime<< endl;
//        }
    }
    printf("%.1lf", (double)TotalTime / 60 / v.size());
}

