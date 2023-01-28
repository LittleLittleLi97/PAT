//
//  main.cpp
//  PAT A 1051 - Pop Sequence
//
//  Created by 97 on 2019/11/17.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;

vector<int> v;
stack<int> s;
int M, N, K;

bool pd(){
    int index = 0;
    for (int i = 1; i <= N; i++) {
        s.push(i);
        if (s.size() > M) return false;
        while (!s.empty() && s.top() == v[index]) {
            s.pop();
            index++;
        }
    }
    if (s.empty()) return true;
    else return false;
}

int main(){
    scanf("%d%d%d", &M, &N, &K);
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            int t; scanf("%d", &t);
            v.push_back(t);
        }
        if (pd()) printf("YES\n");
        else printf("NO\n");
        while (!s.empty()) {
            s.pop();
        }
        v.clear();
    }
}
