//
//  main.cpp
//  PAT B 1060 - 爱丁顿数
//
//  Created by 97 on 2019/9/1.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int a[100010];

bool cmp(int x, int y){
    return x > y;
}

int main(){
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + N + 1, cmp);
    int out = 1;
    while (out <= N && a[out] > out) {
        out++;
    }
    cout << out - 1;
}

/*
// 14 分
int a[100010];
int m = 0;
int out = 0;

int main(){
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int t; cin >> t;
        a[t]++;
        if (t > m) m = t;
    }
    for (int i = 0; i <= m; i++) {
        if (N - a[i] == i) {
            if (i > out) out = i;
        }
        N -= a[i];
    }
    cout << out;
}
*/
