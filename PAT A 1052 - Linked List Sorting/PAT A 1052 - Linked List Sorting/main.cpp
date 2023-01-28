//
//  main.cpp
//  PAT A 1052 - Linked List Sorting
//
//  Created by 97 on 2019/11/21.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int Address;
    int Data;
    int Next;
};
Node Link[100010];
vector<Node> v;
int N, First;

bool cmp(Node a, Node b){
    return a.Data < b.Data;
}

int main(){
    scanf("%d %d", &N, &First);
    for (int i = 0; i < N; i++) {
        Node t; scanf("%d %d %d", &t.Address, &t.Data, &t.Next);
        Link[t.Address] = t;
    }
    int nowAddress = First;
    while (nowAddress != -1) {
        v.push_back(Link[nowAddress]);
        nowAddress = Link[nowAddress].Next;
    }
    sort(v.begin(), v.end(), cmp);
    if (v.size()) printf("%ld %05d\n", v.size(), v[0].Address);
    else printf("0 -1\n");
    for (int i = 0; i < v.size(); i++) {
        if (i == v.size() - 1) printf("%05d %d -1\n", v[i].Address, v[i].Data);
        else printf("%05d %d %05d\n", v[i].Address, v[i].Data, v[i + 1].Address);
    }
}
