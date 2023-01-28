//
//  main.cpp
//  PAT A 1117 - Eddington Number
//
//  Created by 97 on 2019/12/6.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int dis[100010];
int N;

bool cmp(int x, int y){
    return x > y;
}

int main(){
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        int t; scanf("%d", &t);
        dis[i] = t;
    }
    sort(dis + 1, dis + N + 1, cmp);
    int out = 1;
    while (out <= N && dis[out] > out) {
        out++;
    }
    printf("%d", out - 1);
}
