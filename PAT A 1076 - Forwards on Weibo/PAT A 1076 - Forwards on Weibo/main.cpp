//
//  main.cpp
//  PAT A 1076 - Forwards on Weibo
//
//  Created by 97 on 2019/10/10.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    int which;
    int Level;
};
int N, L;
vector<int> v[1010];
bool ever[1010];

int BFS(int st){
    queue<Node> q;
    q.push({st, 0});
    ever[st] = true;
    int count = 0;
    while (!q.empty()) {
        Node t = q.front();
        q.pop();
        for (int i = 0; i < v[t.which].size(); i++) {
            if (ever[v[t.which][i]] == false && t.Level + 1 <= L) {
                q.push({v[t.which][i], t.Level + 1});
                count++;
                ever[v[t.which][i]] = true;
            }
        }
    }
    return count;
}

int main(){
    scanf("%d %d", &N, &L);
    for (int i = 1; i <= N; i++) {
        int many; scanf("%d", &many);
        for (int j = 0; j < many; j++) {
            int t; scanf("%d", &t);
            v[t].push_back(i);
        }
    }
    int K; scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        int st; scanf("%d", &st);
        fill(ever, ever + 1010, false);
        int count = BFS(st);
        printf("%d\n", count);
    }
}
