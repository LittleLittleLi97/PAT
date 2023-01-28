//
//  main.cpp
//  PAT B 1059 - C语言竞赛
//
//  Created by 97 on 2019/8/29.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
#include <cmath>
using namespace std;

map<string, int> m;
bool ever[10010] = {false};

bool sushu(int a){
    for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) return false;
    }
    return true;
}

int main(){
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        string t;
        cin >> t;
        m[t] = i;
    }
    int K; cin >> K;
    for (int i = 0; i < K; i++) {
        string ts; int tint;
        cin >> ts;
        tint = stoi(ts);
        printf("%s: ", ts.c_str());
        if (!m[ts]) {
            printf("Are you kidding?\n"); continue;
        }
        if (ever[tint] == true) {
            printf("Checked\n"); continue;
        }
        if (m[ts] == 1) {
            printf("Mystery Award\n");
        }else if (sushu(m[ts])) {
            printf("Minion\n");
        }else {
            printf("Chocolate\n");
        }
        ever[tint] = true;
    }
}
