//
//  main.cpp
//  PAT B 1030 - 完美数列
//
//  Created by 97 on 2019/7/29.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

long int a[100010];

int main(){
    int N;
    long int p;
    scanf("%d%ld", &N, &p);
    for (int i = 0; i < N; i++) {
        scanf("%ld", &a[i]);
    }
    sort(a, a + N);
    int count = 1;
    for (int i = 0; i < N; i++) {
        for (int j = i + count; j < N; j++) {
            if (a[j] <= a[i] * p) {
                if (count <= j - i + 1) count = j - i + 1;
            }else break;        //这个break是重点，不明原理
        }
    }
    printf("%d", count);
}
