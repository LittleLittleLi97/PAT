//
//  main.cpp
//  Second PAT A 1008 - Elevator
//
//  Created by 97 on 2021/9/23.
//  Copyright © 2021 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

vector<int> v;
int N;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int t;
        scanf("%d", &t);
        v.push_back(t);
    }
    int last = 0;
    int out = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] < last) out += (last - v[i]) * 4;
        else out += (v[i] - last) * 6;
        last = v[i];
    }
    out += N * 5;
    printf("%d", out);
}
