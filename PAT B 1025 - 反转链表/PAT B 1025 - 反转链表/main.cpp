//
//  main.cpp
//  PAT B 1025 - 反转链表
//
//  Created by 97 on 2019/7/28.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int Address;
    int Data;
    int Next;
}a[100010];

vector<Node> v;

int main(){     //有对象真好，写着方便多了
    int firstAdd;
    int N;
    int K;
    scanf("%d%d%d", &firstAdd,&N, &K);
    Node t;
    for (int i = 0; i < N; i++) {
        scanf("%d%d%d", &t.Address, &t.Data, &t.Next);
        a[t.Address] = t;
    }
    int next = firstAdd;
    while (next != -1) {        //给的地址有可能不在Next中，不push到v中，扔掉
        v.push_back(a[next]);
        next = a[next].Next;
    }
    /*
    for (int i = 0; i < N; i++) {
        scanf("%d%d%d", &t.Address,&t.Data, &t.Next);
        if (t.Address == firstAdd) {
            v.insert(v.begin(), t);
            continue;
        }
        v.push_back(t);
    }
    for (int i = 0; i < N; i++) {
        int next = v[i].Next;
        for (int j = i + 1; j < N; j++) {
            if (next == v[j].Address) {
                v.insert(v.begin() + i + 1, v[j]);
                v.erase(v.begin() + j + 1);
            }
        }
    }
    */
    if (K != 0) {
        for (int i = 0; i + K <= v.size(); i += K) {
            reverse(v.begin() + i, v.begin() + i + K);
        }
    }
    /*
    if (K > N) {
        reverse(v.begin(), v.end());
    }else {
        int re = N / K;
        for (int i = 0; i < re; i++) {
            reverse(v.begin() + i * K, v.begin() + i * K + K);
        }
    }
    */
    for (int j = 0; j < v.size() - 1; j++) {
        v[j].Next = v[j + 1].Address;
    }
    v[N - 1].Next = -1;
    for (int i = 0; i < v.size(); i++) {
        if (i != 0) {
            printf("\n");
        }
        if (v[i].Next == -1) {
            printf("%05d %d %d", v[i].Address, v[i].Data, v[i].Next);
            continue;
        }
        printf("%05d %d %05d", v[i].Address, v[i].Data, v[i].Next);
    }
}
