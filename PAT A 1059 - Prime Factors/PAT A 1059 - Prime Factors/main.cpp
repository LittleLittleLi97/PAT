//
//  main.cpp
//  PAT A 1059 - Prime Factors
//
//  Created by 97 on 2019/11/14.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int Prime[100010];
int CountPrime = 0;
long long N;

struct Node {
    int Prime;
    int Count;
};
vector<Node> v;

bool IsPrime(int a){
    if (a <= 1) return false;
    for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) return false;
    }
    return true;
}

void GetPrime(){
    for (int i = 2; i < 100010; i++) {
        if (IsPrime(i)) {
            Prime[CountPrime] = i;
            CountPrime++;
        }
    }
}

int main(){
    GetPrime();
    scanf("%lld", &N);
    printf("%lld=", N);
    if (N == 1) {
        printf("1");
        return 0;
    }
    int nowPrimeth = 0;
    while (N != 1) {
        Node t;
        if (N % Prime[nowPrimeth] == 0) {
            t.Prime = Prime[nowPrimeth];
            t.Count = 0;
            while (N % Prime[nowPrimeth] == 0) {
                t.Count++;
                N /= Prime[nowPrimeth];
            }
            v.push_back(t);
        }
        nowPrimeth++;
    }
    for (int i = 0; i < v.size(); i++) {
        printf("%d", v[i].Prime);
        if (v[i].Count > 1) {
            printf("^%d", v[i].Count);
        }
        if (i != v.size() - 1) printf("*");
    }
}
