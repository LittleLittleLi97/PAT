//
//  main.cpp
//  Second PAT A 1009 - Product of Polynomials
//
//  Created by 97 on 2021/9/23.
//  Copyright © 2021 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int exp;
    double coef;
};
vector<Node> vA;
vector<Node> vB;
double coef[1000010];

void In(vector<Node> &v) {
    int K;
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        Node t;
        scanf("%d%lf", &t.exp, &t.coef);
        v.push_back(t);
    }
}

int main() {
    In(vA);
    In(vB);
    for (int i = 0; i < vA.size(); i++) {
        for (int j = 0; j < vB.size(); j++) {
            Node t;
            t.exp = vA[i].exp + vB[j].exp;
            t.coef = vA[i].coef * vB[j].coef;
            coef[t.exp] += t.coef;
//            printf("%d+%d=%d : %.1lf*%.1lf=%.1f\n", vA[i].exp, vB[i].exp, t.exp,vA[i].coef, vB[i].coef, t.coef);
        }
    }
    int outCount = 0;
    for (int i = 1000010 - 1; i >= 0; i--) {
        if (coef[i] != 0) {
            outCount++;
        }
    }
    printf("%d", outCount);
    for (int i = 1000010 - 1; i >= 0; i--) {
        if (coef[i] != 0) {
            printf(" %d %.1lf", i, coef[i]);
        }
    }
}
