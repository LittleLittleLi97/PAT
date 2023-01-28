//
//  main.cpp
//  PAT A 1032 - Sharing
//
//  Created by 97 on 2019/10/1.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

struct Node {
    int Address;
    char Data;
    int Next;
};
Node a[100010];
bool ever[100010];

int main(){
    int firstAddress;
    int secondAddress;
    int N;
    scanf("%d%d%d", &firstAddress, &secondAddress, &N);
    for (int i = 0; i < N; i++) {
        Node t; scanf("%d %c %d", &t.Address, &t.Data, &t.Next);
        a[t.Address] = t;
    }
    int ta = firstAddress;
    while (ta != -1) {
        ever[ta] = true;
        ta = a[ta].Next;
    }
    ta = secondAddress;
    while (ta != -1) {
        if (ever[ta] == true) break;
        ta = a[ta].Next;
    }
    if (ta != -1) printf("%05d", ta);
    else printf("-1");
}
