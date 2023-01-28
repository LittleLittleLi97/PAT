//
//  main.cpp
//  PAT A 1048 - Find Coins
//
//  Created by 97 on 2019/10/29.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int emerge[1010];
int N, M;

int main(){
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        int t; scanf("%d", &t);
        emerge[t]++;
    }
    for (int i = 1; i < 1010; i++) {
        if (emerge[i] && emerge[M - i]) {
            if (i == M - i) {
                if (emerge[i] >= 2) printf("%d %d", i, M - i);
                else printf("No Solution");
            }
            else printf("%d %d", i, M - i);
            return 0;
        }
    }
    printf("No Solution");
}
