//
//  main.cpp
//  PAT A 1078 - Hashing
//
//  Created by 97 on 2019/11/13.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int MSize, N;
bool Hash[10010];

bool getPrim(int a){
    if (a <= 1) return false;
    for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) return false;
    }
    return true;
}

int main(){
    scanf("%d %d", &MSize, &N);
    while (!getPrim(MSize)) {
        MSize++;
    }
    for (int i = 0; i < N; i++) {
        int t; scanf("%d", &t);
        if (Hash[t % MSize] == false) {
            Hash[t % MSize] = true;
            printf("%d", t % MSize);
        }else {
            bool flag = false;
            for (int j = 1; j < MSize; j++) {
                int position = (t + j * j) % MSize;
                if (Hash[position] == false) {
                    Hash[position] = true;
                    flag = true;
                    printf("%d", position);
                    break;
                }
            }
            if (flag == false) printf("-");
        }
        if (i != N - 1) printf(" ");
    }
}
