//
//  main.cpp
//  PAT A 1007 - Maxmium Subsequence Sum
//
//  Created by 97 on 2019/10/14.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Node {
    int i;
    int j;
};
int a[10010];
int dp[10010];
Node position[10010];
int N;

int main(){
    scanf("%d", &N);
    dp[0] = -10;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &a[i]);
        int t = dp[i - 1] + a[i];
        if (t > a[i]) {
            dp[i] = t;
            position[i].i = position[i - 1].i;
            position[i].j = i;
        }else {
            dp[i] = a[i];
            position[i].i = i;
            position[i].j = i;
        }
    }
    int outIndex = 0;
    for (int i = 1; i <= N; i++) {
        if (dp[i] > dp[outIndex]) {
            outIndex = i;
        }
    }
    if (dp[outIndex] < 0) printf("0 %d %d", a[1], a[N]);
    else printf("%d %d %d", dp[outIndex], a[position[outIndex].i], a[position[outIndex].j]);
}
