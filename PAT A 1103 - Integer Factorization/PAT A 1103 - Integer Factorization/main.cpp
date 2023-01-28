//
//  main.cpp
//  PAT A 1103 - Integer Factorization
//
//  Created by 97 on 2019/11/22.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;

int N, K, P;
int Table[410];
int maxFacSum = -1;
vector<int> out, temp;

void DFS(int index, int sum, int nowK, int facSum){
    if (sum == N && nowK == K) {
        if (facSum > maxFacSum) {
            out = temp;
            maxFacSum = facSum;
        }
        return;
    }
    if (sum > N || nowK > K) return;
    if (index > 0) {
        temp.push_back(index);
        DFS(index, sum + Table[index], nowK + 1, facSum + index);
        temp.pop_back();
        DFS(index - 1, sum, nowK, facSum);
    }
}

int main(){
    scanf("%d%d%d", &N, &K, &P);
    int maxnum = 0;
    for (int i = 0; i < N; i++) {
        if (pow(i, P) <= N) {
            Table[i] = pow(i, P);
            maxnum = i;
        }
    }
    for (int i = maxnum; i > 0; i--) {
        DFS(i, 0, 0, 0);
    }
    printf("%d\n", Table[4]);
    for (int i = 0; i < out.size(); i++) {
        printf("%d ", out[i]);
    }
}
