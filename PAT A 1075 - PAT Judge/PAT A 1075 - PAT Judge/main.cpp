//
//  main.cpp
//  PAT A 1075 - PAT Judge
//
//  Created by 97 on 2019/10/24.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct Node {
    int ID;
    int Grade[10];
    int Total;
    int Perfect;
    bool Sub[10];
    bool ever;
};
map<int, Node> m;
vector<Node> v;
int grade[10];
int N, K, M;

bool cmp(Node a, Node b){
    if (a.Total != b.Total) return a.Total > b.Total;
    else if (a.Perfect != b.Perfect) return a.Perfect > b.Perfect;
    else return a.ID < b.ID;
}

int main(){
    scanf("%d %d %d", &N, &K, &M);
    for (int i = 1; i <= K; i++) {
        scanf("%d", &grade[i]);
    }
    for (int i = 0; i < M; i++) {
        int id, which, many;
        scanf("%d %d %d", &id, &which, &many);
        m[id].Sub[which] = true;
//        printf("%d\n", id);
        if (many != -1) m[id].ever = true;
        if (many > m[id].Grade[which]) {
            m[id].Grade[which] = many;
        }
    }
    for (auto it : m) {
//        printf("%d\n", it.first);
        if (it.second.ever == false) continue;
        for (int i = 1; i <= K; i++) {
            it.second.Total += it.second.Grade[i];
            if (it.second.Grade[i] == grade[i]) it.second.Perfect++;
        }
        it.second.ID = it.first;
        v.push_back(it.second);
    }
    sort(v.begin(), v.end(), cmp);
    int rank = 1;
    printf("%d %05d %d", rank, v[0].ID, v[0].Total);
    for (int i = 1; i <= K; i++) {
        if (v[0].Sub[i] == false) printf(" -");
        else printf(" %d", v[0].Grade[i]);
    }
    printf("\n");
    for (int i = 1; i < v.size(); i++) {
        if (v[i].Total != v[i - 1].Total) rank = i + 1;
        printf("%d %05d %d", rank, v[i].ID, v[i].Total);
        for (int j = 1; j <= K; j++) {
            if (v[i].Sub[j] == false) printf(" -");
            else printf(" %d", v[i].Grade[j]);
        }
        printf("\n");
    }
}
