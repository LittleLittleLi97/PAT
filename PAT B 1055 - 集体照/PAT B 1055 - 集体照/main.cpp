//
//  main.cpp
//  PAT B 1055 - 集体照
//
//  Created by 97 on 2019/8/28.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;

struct Node {
    string Name;
    int Data;
};
vector<Node> v;

bool cmp(Node a, Node b){
    if (a.Data != b.Data) return a.Data > b.Data;
    else return a.Name < b.Name;
}

void out(int a, int b){
//    printf("%d - %d\n", a, b);
    vector<Node> t;
    t.push_back(v[a]);
    int count = 0;
    for (int i = a + 1; i <= b; i++, count++) {
        if (count % 2 == 0) t.insert(t.begin(), v[i]);
        else t.insert(t.end(), v[i]);
//        for (int i = 0; i < t.size(); i++) {
//            printf(" -%s-", t[i].Name.c_str());
//        }
//        printf("\n");
    }
    for (int i = 0; i < t.size(); i++) {
        if (i == 0) printf("%s", t[i].Name.c_str());
        else printf(" %s", t[i].Name.c_str());
    }
    printf("\n");
}

int main(){
    int N, K;
    cin >> N >> K;
    Node t;
    int h = N / K;
    for (int i = 0; i < N; i++) {
        cin >> t.Name >> t.Data;
        v.push_back(t);
    }
    sort(v.begin(), v.end(), cmp);
    int moment = N - (K - 1) * h - 1;
    for (int i = 0; i < K; i++) {
        if (i == 0) {out(0, moment); moment += 1;}
        else {out(moment, moment + h - 1); moment += h;}
    }
}
