//
//  main.cpp
//  PAT A 1080 - Graduate Adminssion
//
//  Created by 97 on 2019/10/25.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    int ID;
    int GE;
    int GI;
    int Total;
    int App[10];
};
vector<Student> v;

struct School {
    int quota;
    int nowMany;
    int lastGE;
    int lastTotal;
    vector<int> ID;
};
vector<School> w;

int N, M, K;

bool cmp(Student a, Student b){
    if (a.Total != b.Total) return a.Total > b.Total;
    else if (a.GE != b.GE) return a.GE > b.GE;
    else return a.ID < b.ID;
}

int main(){
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < M; i++) {
        School t; scanf("%d", &t.quota);
        w.push_back(t);
    }
    for (int i = 0; i < N; i++) {
        Student t;
        t.ID = i;
        scanf("%d %d", &t.GE, &t.GI);
        t.Total = t.GE + t.GI;
        for (int j = 0; j < K; j++) {
            scanf("%d", &t.App[j]);
        }
        v.push_back(t);
    }
    sort(v.begin(), v.end(), cmp);
//    for (int i = 0; i < v.size(); i++) {
//        printf("%d %d %d\n", v[i].Total, v[i].GE, v[i].GI);
//    }
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < K; j++) {
            int which = v[i].App[j];
            if (w[which].nowMany < w[which].quota || (v[i].Total == w[which].lastTotal && v[i].GE == w[which].lastGE)) {
                w[which].nowMany++;
                w[which].ID.push_back(v[i].ID);
                w[which].lastTotal = v[i].Total;
                w[which].lastGE = v[i].GE;
                break;
            }
        }
    }
    for (int i = 0; i < w.size(); i++) {
        sort(w[i].ID.begin(), w[i].ID.end());
        for (int j = 0; j < w[i].ID.size(); j++) {
            printf("%d", w[i].ID[j]);
            if (j != w[i].ID.size() - 1) printf(" ");
        }
        printf("\n");
    }
}
