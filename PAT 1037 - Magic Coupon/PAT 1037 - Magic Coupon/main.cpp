//
//  main.cpp
//  PAT 1037 - Magic Coupon
//
//  Created by 97 on 2019/11/4.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a, b;
int out = 0;

bool cmp(int x, int y){
    return x > y;
}

int main(){
    int N; scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int t; scanf("%d", &t);
        a.push_back(t);
    }
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int t; scanf("%d", &t);
        b.push_back(t);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0;
    while (a[i] < 0 && b[i] < 0) {
        out += a[i] * b[i];
        i++;
    }
    sort(a.begin(), a.end(), cmp);
    sort(b.begin(), b.end(), cmp);
    i = 0;
    while (a[i] > 0 && b[i] > 0) {
        out += a[i] * b[i];
        i++;
    }
    printf("%d", out);
}
