//
//  main.cpp
//  PAT A 1116 - Come on Les't C
//
//  Created by 97 on 2019/12/6.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;

int Rank[10010];
bool ever[10010];
int N, K;

bool IsPrime(int a){
    if (a <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}

int main(){
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        int t; scanf("%d", &t);
        Rank[t] = i;
    }
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        int which; scanf("%d", &which);
        printf("%04d: ", which);
        if (ever[which] == true) {
            printf("Checked\n");
            continue;
        }
        if (Rank[which] == 0) {
            printf("Are you kidding?\n");
            continue;
        }
        if (Rank[which] == 1) {
            printf("Mystery Award\n");
        }else if (IsPrime(Rank[which]) == true) {
            printf("Minion\n");
        }else printf("Chocolate\n");
        ever[which] = true;
    }
}
