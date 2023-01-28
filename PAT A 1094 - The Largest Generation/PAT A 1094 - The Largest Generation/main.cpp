//
//  main.cpp
//  PAT A 1094 - The Largest Generation
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
Node v[110];
int N, M;
int num[110];

void BFS(int st){
    v[st].Level = 1;
    queue<int> q;
    q.push(st);
    while (!q.empty()) {
        int ID = q.front();
        q.pop();
        num[v[ID].Level]++;
//        printf("- %d\n", num[v[ID].Level]);
        for (int i = 0; i < v[ID].Sub.size(); i++) {
            v[v[ID].Sub[i]].Level = v[ID].Level + 1;
            q.push(v[ID].Sub[i]);
        }
    }
}

int main(){
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int ID, many; scanf("%d %d", &ID, &many);
        for (int j = 0; j < many; j++) {
            int t; scanf("%d", &t);
            v[ID].Sub.push_back(t);
        }
    }
//    cout << v[1].Sub[1] << endl;
    BFS(1);
    int index = 1;
    for (int i = 1; i < N; i++) {
//        printf("%d ", num[i]);
        if (num[i] > num[index]) index = i;
    }
    printf("%d %d", num[index], index);
}
