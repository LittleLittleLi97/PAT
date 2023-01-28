//
//  main.cpp
//  PAT A 1042 - Shuffling Machine
//
//  Created by 97 on 2019/10/18.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

int shuzu[100];
int order[100];
int K;

int main(){
    scanf("%d", &K);
    for (int i = 1; i <= 54; i++) {
        shuzu[i] = i;
        int t; scanf("%d", &t);
        order[i] = t;
    }
    for (int i = 0; i < K; i++) {
        int t[100];
        for (int j = 1; j <= 54; j++) {
            t[order[j]] = shuzu[j];
        }
        for (int j = 1; j <= 54; j++) {
            shuzu[j] = t[j];
        }
    }
    for (int i = 1; i <= 54; i++) {
        int t = shuzu[i];
        if (t >= 1 && t <= 13) printf("S%d", t);
        else if (t <= 26) printf("H%d", t - 13);
        else if (t <= 39) printf("C%d", t - 26);
        else if (t <= 52) printf("D%d", t - 39);
        else printf("J%d", t - 52);
        if (i != 54) printf(" ");
    }
}
