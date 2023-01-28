//
//  main.cpp
//  PAT A 1014 - Waiting in Line
//
//  Created by 97 on 2019/10/17.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1000000000
using namespace std;

struct Node {
    int th;
    int doTime;
    int enterTime;
    int doneTime;
};

queue<Node> q[22];
int N, M, K, Q;
vector<Node> v;

void Enter(Node t){
    int u = -1;
    long int size = INF;
    for (int i = 0; i < N; i++) {
        if (q[i].size() < M) {
            if (q[i].size() < size) {
                size = q[i].size();
                u = i;
            }
        }
    }
    if (u != -1) {
        if (q[u].empty()) {
            t.doneTime = 8 * 60 + t.doTime;
            t.enterTime = 8 * 60;
        }else {
            t.doneTime = q[u].back().doneTime + t.doTime;
            t.enterTime = q[u].back().doneTime;
        }
        q[u].push(t);
    }else {
        int minth = 0;
        for (int i = 0; i < N; i++) {
            if (q[i].front().doneTime < q[minth].front().doneTime) {
                minth = i;
            }
        }
        t.doneTime = t.doTime + q[minth].back().doneTime;
        t.enterTime = q[minth].back().doneTime;
        q[minth].push(t);
        q[minth].pop();
    }
    v.push_back(t);
}

void changeTime(int doneTime, int &hh, int &mm){
    hh = doneTime / 60;
    mm = doneTime % 60;
}

bool cmp(Node a, Node b){
    return a.th < b.th;
}

int main(){
    scanf("%d%d%d%d", &N, &M, &K, &Q);
    for (int i = 0; i < K; i++) {
        Node t; scanf("%d", &t.doTime);
        t.th = i + 1;
        Enter(t);
    }
    sort(v.begin(), v.end(), cmp);
//    printf("\n");
//    for (int i = 0; i < v.size(); i++) {
//        printf("%d - %d - %d\n", v[i].th, v[i].doTime, v[i].doneTime);
//    }
    for (int i = 0; i < Q; i++) {
        int which; scanf("%d", &which);
        int hh = 0, mm = 0;
        changeTime(v[which - 1].doneTime, hh, mm);
        if (v[which - 1].enterTime >= 17 * 60) printf("Sorry\n");
        else printf("%02d:%02d\n", hh, mm);
    }
}
