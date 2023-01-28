//
//  main.cpp
//  PAT A 1085 - Perfect Sequence
//
//  Created by 97 on 2019/11/6.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int N;
long int p;
long int v[100010];

int main(){
    scanf("%d %ld", &N, &p);
    for (int i = 0; i < N; i++) {
        scanf("%ld", &v[i]);
    }
    sort(v, v + N);
    int count = 1;
    for (int i = 0; i < N; i++) {
        for (int j = i + count; j < N; j++) {
            if (v[j] <= v[i] * p) {
                if (count < j - i + 1) {
                    count = j - i + 1;
                }
            }else break;
        }
    }
    printf("%d", count);
}
