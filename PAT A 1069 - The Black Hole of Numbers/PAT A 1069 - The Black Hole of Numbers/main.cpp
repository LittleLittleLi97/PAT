//
//  main.cpp
//  PAT A 1069 - The Black Hole of Numbers
//
//  Created by 97 on 2019/11/7.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int a[4];

void toints(int t){
    for (int i = 0; i < 4; i++) {
        a[i] = t % 10;
        t /= 10;
    }
}

int tonumber(){
    int out = 0;
    for (int i = 0; i < 4; i++) {
        out = out * 10 + a[i];
    }
    return out;
}

bool cmp(int x, int y){
    return x > y;
}

int main(){
    int N;
    scanf("%d", &N);
    while (true) {
        toints(N);
        sort(a, a + 4);
        int xiao = tonumber();
        sort(a, a + 4, cmp);
        int da = tonumber();
        N = da - xiao;
        printf("%04d - %04d = %04d\n", da, xiao, N);
        if (N == 6174 || N == 0) {
            break;
        }
    }
}
