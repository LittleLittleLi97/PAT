//
//  main.cpp
//  PAT A 1089 - Inser or Merge
//
//  Created by 97 on 2019/11/6.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
int a[110];
int b[110];
int c[110];
int d[110];

bool isLike(int num[]){
    for (int i = 0; i < N; i++) {
        if (b[i] != num[i]) {
            return false;
        }
    }
    return true;
}

void PrintOut(int num[]){
    for (int i = 0; i < N; i++) {
        printf("%d", num[i]);
        if (i != N - 1) printf(" ");
    }
}

int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
        d[i] = c[i] = a[i];
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &b[i]);
    }
    bool flag = false;
    for (int i = 1; i < N; i++) {
        int t = c[i];
        for (int j = i - 1; j >= 0; j--) {
            if (c[j] > t) {
                c[j + 1] = c[j];
                c[j] = t;
            }
        }
//        PrintOut(c);
//        printf("\n");
        if (flag == true) {
            PrintOut(c);
            break;
        }
        if (isLike(c)) {
            flag = true;
            printf("Insertion Sort\n");
        }
    }
    flag = false;
    for (int step = 2; step / 2 <= N; step *= 2) {
        for (int i = 0; i < N; i += step) {
            sort(d + i, d + min(N, i + step));
        }
        if (flag == true) {
            PrintOut(d);
            break;
        }
        if (isLike(d)) {
            flag = true;
            printf("Merge Sort\n");
        }
    }
}
