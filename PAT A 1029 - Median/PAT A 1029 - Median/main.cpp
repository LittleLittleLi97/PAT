//
//  main.cpp
//  PAT A 1029 - Median
//
//  Created by 97 on 2019/11/7.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#define INF 2000000000
using namespace std;

int N, M;
int a[100010];
int b[100010];
//int c[100010];

int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &b[i]);
    }
    a[N] = b[M] = INF;
    int position = (N + M - 1) / 2;
    int pa = 0, pb = 0;
    int count = 0;
    while (count < position) {
        if (a[pa] <= b[pb]) pa++;
        else pb++;
        count++;
    }
    if (a[pa] < b[pb]) printf("%d", a[pa]);
    else printf("%d", b[pb]);
    /*
     // 未知错误 18分
     int PtrA = 0, PtrB = 0, PtrC = 0;
     while (PtrA < N && PtrB < M) {
     if (a[PtrA] <= b[PtrB]) {
     c[PtrC] = a[PtrA];
     PtrC++;
     PtrA++;
     }else {
     c[PtrC] = b[PtrB];
     PtrC++;
     PtrB++;
     }
     }
     while (PtrA < N) {
     c[PtrC] = a[PtrA];
     PtrC++;
     PtrA++;
     }
     while (PtrB < M) {
     c[PtrC] = b[PtrB];
     PtrC++;
     PtrB++;
     }
     //    for (int i = 0; i < N + M; i++) {
     //        printf("%ld ", c[i]);
     //    }printf("\n");
     printf("%ld", c[(N + M - 1) / 2]);
     */
}
