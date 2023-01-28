//
//  main.cpp
//  PAT A 1091 - Acute Stroke
//
//  Created by 97 on 2019/11/23.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <queue>
#define MaxSize 1300
#define IncSize 6
using namespace std;

struct Node {
    int x, y, z;
};

int Model[60][MaxSize][MaxSize];
int M, N, L, T;
bool ever[60][MaxSize][MaxSize];

int IncX[IncSize] = {1, -1, 0, 0, 0, 0};
int IncY[IncSize] = {0, 0, 1, -1, 0, 0};
int IncZ[IncSize] = {0, 0, 0, 0, 1, -1};

int total = 0;

bool pd(Node t){
    if (t.x < 0 || t.x >= L || t.y < 0 || t.y >= M || t.z < 0 || t.z >= N) return false;
    if (ever[t.x][t.y][t.z] == true) return false;
    if (Model[t.x][t.y][t.z] == 0) return false;
    return true;
}

void BFS(Node st, int &count){
    queue<Node> q;
    q.push(st);
    while (!q.empty()) {
        Node t = q.front();
        q.pop();
        ever[t.x][t.y][t.z] = true;
        count++;
        for (int i = 0; i < 6; i++) {
            int newX = t.x + IncX[i];
            int newY = t.y + IncY[i];
            int newZ = t.z + IncZ[i];
            if (pd({newX, newY, newZ}) == true) {
                q.push({newX, newY, newZ});
                ever[newX][newY][newZ] = true;
            }
        }
    }
}

int main(){
    scanf("%d%d%d%d", &M, &N, &L, &T);
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < N; k++) {
                scanf("%d", &Model[i][j][k]);
            }
        }
    }
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < N; k++) {
                int count = 0;
                if (ever[i][j][k] == false && Model[i][j][k] == 1) BFS({i, j, k}, count);
                if (count >= T) total += count;
            }
        }
    }
    printf("%d", total);
}
