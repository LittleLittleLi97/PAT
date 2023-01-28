//
//  main.cpp
//  PAT A 1013 - Battle Over Cities
//
//  Created by 97 on 2019/10/15.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
#define vmax 1010
using namespace std;

bool Graph[vmax][vmax];
bool ever[vmax];
int N, M, K;

void DFSTraversal(int st){
    ever[st] = true;
    for (int i = 1; i <= N; i++) {
        if (ever[i] == false && Graph[st][i] == true) {
            DFSTraversal(i);
        }
    }
}

int DFS(int which){
    fill(ever, ever + vmax, false);
    ever[which] = true;
    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (ever[i] == false) {
            DFSTraversal(i);
            count++;
        }
    }
    return count - 1;
}

int main(){
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < M; i++) {
        int a, b; scanf("%d %d", &a, &b);
        Graph[a][b] = Graph[b][a] = true;
    }
    for (int i = 0; i < K; i++) {
        int which; scanf("%d", &which);
        int count = DFS(which);
        printf("%d\n", count);
    }
}
