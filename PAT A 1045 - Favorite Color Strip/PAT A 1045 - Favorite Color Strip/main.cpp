//
//  main.cpp
//  PAT A 1045 - Favorite Color Strip
//
//  Created by 97 on 2019/12/2.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int Favorite[210];
vector<int> order;
int dp[10010];
int N, M, L;
int out = 0;

int main(){
    scanf("%d", &N);
    scanf("%d", &M);
    for (int i = 1; i <= M; i++) {
        int t; scanf("%d", &t);
        Favorite[t] = i;
    }
    scanf("%d", &L);
    for (int i = 0; i < L; i++) {
        int t; scanf("%d", &t);
        if (Favorite[t] > 0) order.push_back(Favorite[t]);
    }
    for (int i = 0; i < order.size(); i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (order[j] <= order[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
            if (dp[i] > out) {
                out = dp[i];
            }
        }
    }
    printf("%d", out);
}
