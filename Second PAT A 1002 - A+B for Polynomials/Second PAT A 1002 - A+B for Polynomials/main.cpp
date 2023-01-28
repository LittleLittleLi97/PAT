//
//  main.cpp
//  Second PAT A 1002 - A+B for Polynomials
//
//  Created by 97 on 2021/9/20.
//  Copyright © 2021 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

bool expA[1010];
double coeA[1010];
bool expB[1010];
double coeB[1010];

struct Node {
    int exp;
    double coe;
};
vector<Node> v;

void Receipt(int n, bool flag[], double coe[]) {
    for (int i = 0; i < n; i++) {
        int exp;
        scanf("%d", &exp);
        flag[exp] = true;
        scanf("%lf", &coe[exp]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    Receipt(n, expA, coeA);
    scanf("%d", &n);
    Receipt(n, expB, coeB);
    for (int i = 1000; i >= 0; i--) {
        if (expA[i] == true || expB[i] == true) {
            if (coeA[i] + coeB[i] != 0) {
                Node t;
                t.exp = i;
                t.coe = coeA[i] + coeB[i];
                v.push_back(t);
            }
        }
    }
    printf("%ld", v.size());
    for (int i = 0; i < v.size(); i++) {
        printf(" %d %.1lf", v[i].exp, v[i].coe);
    }
}
