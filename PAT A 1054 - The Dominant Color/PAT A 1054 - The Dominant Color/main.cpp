//
//  main.cpp
//  PAT A 1054 - The Dominant Color
//
//  Created by 97 on 2019/11/16.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

map<int, int> m;
int M, N;

int main(){
    scanf("%d%d", &M, &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int t; scanf("%d", &t);
            m[t]++;
        }
    }
    int out = -1;
    int count = -1;
    for (auto it : m) {
        if (it.second > count) {
            out = it.first;
            count = it.second;
        }
    }
    printf("%d", out);
}
