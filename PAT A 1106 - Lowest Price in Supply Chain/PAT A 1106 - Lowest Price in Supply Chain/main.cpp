//
//  main.cpp
//  PAT A 1106 - Lowest Price in Supply Chain
//
//  Created by 97 on 2019/11/25.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    vector<int> Sub;
    int Level;
};
Node v[100010];
int num[100010];
int N;
double P, R;
int minLeavesLevel = 1000000000;

void BFS(int st){
    v[st].Level = 0;
    queue<int> q;
    q.push(st);
    while (!q.empty()) {
        int which = q.front();
        q.pop();
        if (v[which].Sub.size() == 0) num[v[which].Level]++;
        if (v[which].Sub.size() == 0 && v[which].Level < minLeavesLevel) minLeavesLevel = v[which].Level;
        for (int i = 0; i < v[which].Sub.size(); i++) {
            v[v[which].Sub[i]].Level = v[which].Level + 1;
            q.push(v[which].Sub[i]);
        }
    }
}

int main(){
    scanf("%d %lf %lf", &N, &P, &R);
    for (int i = 0; i < N; i++) {
        int many; scanf("%d", &many);
        for (int j = 0; j < many; j++) {
            int t; scanf("%d", &t);
            v[i].Sub.push_back(t);
        }
    }
    BFS(0);
    double price = P;
    for (int i = 0; i < minLeavesLevel; i++) {
        price = price + price * R / 100;
    }
//    cout << num[2] << endl;
    printf("%.4lf %d", price, num[minLeavesLevel]);
}
