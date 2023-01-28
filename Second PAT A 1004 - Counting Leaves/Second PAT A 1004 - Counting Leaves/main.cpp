//
//  main.cpp
//  Second PAT A 1004 - Counting Leaves
//
//  Created by 97 on 2021/9/22.
//  Copyright © 2021 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

const int MaxSize = 110;

int N, M;
vector<int> v[MaxSize];
struct Node {
    int whichNode;
    int layer;
};
int out[MaxSize];
int MaxLevel = 0;

void BFS(int start) {
    queue<Node> q;
    Node t;
    t.whichNode = start;
    t.layer = 0;
    q.push(t);
    while (!q.empty()) {
        t = q.front();
        q.pop();
        if (v[t.whichNode].size() == 0) out[t.layer]++;
        if (t.layer > MaxLevel) MaxLevel = t.layer;
        for (int i = 0; i < v[t.whichNode].size(); i++) {
            Node will;
            will.whichNode = v[t.whichNode][i];
            will.layer = t.layer + 1;
            q.push(will);
        }
    }
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        int ID, K;
        scanf("%d%d", &ID, &K);
        for (int j = 0; j < K; j++) {
            int t;
            scanf("%d", &t);
            v[ID].push_back(t);
        }
    }
    BFS(1);
    bool flag = false;
    for (int i = 0; i <= MaxLevel; i++) {
        if (flag == true) printf(" ");
        flag = true;
        printf("%d", out[i]);
    }
}
