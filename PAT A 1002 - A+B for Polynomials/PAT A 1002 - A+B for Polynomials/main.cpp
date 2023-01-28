//
//  main.cpp
//  PAT A 1002 - A+B for Polynomials
//
//  Created by 97 on 2019/9/20.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int zhishu;
    double xishu;
};

map<int, double> m;
vector<Node> v;

bool cmp(Node a, Node b){
    return a.zhishu > b.zhishu;
}

int main(){
    for (int i = 0; i < 2; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int zhishu; double xishu; cin >> zhishu >> xishu;
            m[zhishu] += xishu;
        }
    }
    for (auto it:m) {
        if (it.second == 0) continue;
        Node t;
        t.zhishu = it.first;
        t.xishu = it.second;
        v.push_back(t);
    }
    sort(v.begin(), v.end(), cmp);
    printf("%ld", v.size());
    for (int i = 0; i < v.size(); i++) {
        printf(" %d %.1lf", v[i].zhishu, v[i].xishu);
    }
}
