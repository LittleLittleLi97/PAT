//
//  main.cpp
//  PAT A 1113 - Integer Set Partition
//
//  Created by 97 on 2019/12/4.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;

int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int t; scanf("%d", &t);
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    int a = 0;
    int b = 0;
    for (int i = 0; i < N / 2; i++) {
        a += v[i];
    }
    for (int i = N / 2; i < v.size(); i++) {
        b += v[i];
    }
    printf("%d %d", (N - N / 2) - N / 2, b - a);
}
