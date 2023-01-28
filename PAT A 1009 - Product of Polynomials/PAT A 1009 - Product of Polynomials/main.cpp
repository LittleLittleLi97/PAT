//
//  main.cpp
//  PAT A 1009 - Product of Polynomials
//
//  Created by 97 on 2019/10/14.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Node {
    int zhishu;
    double xishu;
};
vector<Node> a, b, out, out2;
map<int, int> m;
int num = 0;

bool cmp(Node x, Node y){
    return x.zhishu > y.zhishu;
}

int main(){
    for (int i = 0; i < 2; i++) {
        int K; scanf("%d", &K);
        for (int j = 0; j < K; j++) {
            Node t; scanf("%d %lf", &t.zhishu, &t.xishu);
            if (i == 0) a.push_back(t);
            else if (i == 1) b.push_back(t);
        }
    }
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            Node t;
            t.zhishu = a[i].zhishu + b[j].zhishu;
            t.xishu = a[i].xishu * b[j].xishu;
            if (t.xishu == 0) continue;
            if (m.find(t.zhishu) == m.end()) {
                m[t.zhishu] = num++;
                out.push_back(t);
            }else {
                out[m[t.zhishu]].xishu += t.xishu;
            }
        }
    }
    sort(out.begin(), out.end(), cmp);
    for (int i = 0; i < out.size(); i++) {
        if (out[i].xishu != 0) {
            out2.push_back(out[i]);
        }
    }
    printf("%ld", out2.size());
    for (int i = 0; i < out2.size(); i++) {
        printf(" %d %.1lf", out2[i].zhishu, out2[i].xishu);
    }
}
