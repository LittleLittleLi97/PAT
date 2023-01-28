//
//  main.cpp
//  PAT A 1090 - Highest Price in Supply Chain
//
//  Created by 97 on 2019/11/25.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

struct Node {
    double Price;
    vector<int> Sub;
};
Node v[100010];
int N;
double P, R;
double maxPrice = -1;
int outCount = 1;

void DFS(int root, int level){
    for (int i = 0; i < v[root].Sub.size(); i++) {
        v[v[root].Sub[i]].Price = v[root].Price + v[root].Price * R / 100;
        if (v[v[root].Sub[i]].Price > maxPrice) {
            maxPrice = v[v[root].Sub[i]].Price;
            outCount = 1;
        }else if (v[v[root].Sub[i]].Price == maxPrice) {
            outCount++;
        }
        DFS(v[root].Sub[i], level + 1);
    }
}

int main(){
    scanf("%d %lf %lf", &N, &P, &R);
    int root = -1;
    for (int i = 0; i < N; i++) {
        int t; scanf("%d", &t);
        if (t == -1) root = i;
        else v[t].Sub.push_back(i);
    }
    v[root].Price = P;
    DFS(root, 0);
    printf("%.2lf %d", maxPrice, outCount);
}
