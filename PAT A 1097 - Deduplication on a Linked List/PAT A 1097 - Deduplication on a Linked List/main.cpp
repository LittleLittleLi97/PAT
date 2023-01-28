//
//  main.cpp
//  PAT A 1097 - Deduplication on a Linked List
//
//  Created by 97 on 2019/11/21.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Node {
    int Address;
    int Data;
    int Next;
};
Node Link[100010];
vector<Node> v;
int First, N;
bool ever[100010];

int main(){
    scanf("%d %d", &First, &N);
    for (int i = 0; i < N; i++) {
        Node t; scanf("%d %d %d", &t.Address, &t.Data, &t.Next);
        Link[t.Address] = t;
    }
    int nowAddress = First;
    printf("%05d %d ", Link[nowAddress].Address, Link[nowAddress].Data);
    ever[abs(Link[nowAddress].Data)] = true;
    nowAddress = Link[nowAddress].Next;
    while (nowAddress != -1) {
        if (ever[abs(Link[nowAddress].Data)] == true) {
            v.push_back(Link[nowAddress]);
        }else {
            printf("%05d\n%05d %d ", Link[nowAddress].Address, Link[nowAddress].Address, Link[nowAddress].Data);
            ever[abs(Link[nowAddress].Data)] = true;
        }
        nowAddress = Link[nowAddress].Next;
    }
    printf("-1\n");
    for (int i = 0; i < v.size(); i++) {
        if (i == v.size() - 1) printf("%05d %d -1\n", v[i].Address, v[i].Data);
        else printf("%05d %d %05d\n", v[i].Address, v[i].Data, v[i + 1].Address);
    }
}
