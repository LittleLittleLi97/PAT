//
//  main.cpp
//  PAT A 1046 - Shortest Distance
//
//  Created by 97 on 2019/10/18.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;

int dis[100010];
int N;
int many;
int totaldis = 0;
int toi[100010];

int main(){
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        int t; scanf("%d", &t);
        dis[i] = t;
        totaldis += t;
        toi[i] = totaldis;
    }
    scanf("%d", &many);
    for (int i = 0; i < many; i++) {
        int a, b; scanf("%d %d", &a, &b);
        if (a > b) swap(a, b);
        int t = toi[b - 1] - toi[a - 1];
        printf("%d\n", min(t, totaldis - t));
    }
}
