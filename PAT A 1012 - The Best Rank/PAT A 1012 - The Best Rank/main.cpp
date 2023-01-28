//
//  main.cpp
//  PAT A 1012 - The Best Rank
//
//  Created by 97 on 2019/10/15.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct Node {
    int ID;
    int C, M, E, A;
};
vector<Node> v;
map<int, Node> m;

int N, many;

bool cmpA(Node a, Node b){
    return a.A > b.A;
}
bool cmpC(Node a, Node b){
    return a.C > b.C;
}
bool cmpM(Node a, Node b){
    return a.M > b.M;
}
bool cmpE(Node a, Node b){
    return a.E > b.E;
}

int main(){
    scanf("%d %d", &N, &many);
    for (int i = 0; i < N; i++) {
        Node t; scanf("%d %d %d %d", &t.ID, &t.C, &t.M, &t.E);
        t.A = (t.C + t.M + t.E) / 3;
        v.push_back(t);
    }
    sort(v.begin(), v.end(), cmpA); vector<Node> A = v;
    sort(v.begin(), v.end(), cmpC); vector<Node> C = v;
    sort(v.begin(), v.end(), cmpE); vector<Node> E = v;
    sort(v.begin(), v.end(), cmpM); vector<Node> M = v;
    int ra = 1, rc = 1, rm = 1, re = 1;
    m[A[0].ID].A = ra;
    m[C[0].ID].C = rc;
    m[M[0].ID].M = rm;
    m[E[0].ID].E = re;
    for (int i = 1; i < v.size(); i++) {
        if (A[i].A == A[i - 1].A) {
            m[A[i].ID].A = ra;
        }else {
            ra = i + 1;
            m[A[i].ID].A = ra;
        }
        
        if (C[i].C == C[i - 1].C) {
            m[C[i].ID].C = rc;
        }else {
            rc = i + 1;
            m[C[i].ID].C = rc;
        }
        
        if (E[i].E == E[i - 1].E) {
            m[E[i].ID].E = re;
        }else {
            re = i + 1;
            m[E[i].ID].E = re;
        }
        
        if (M[i].M == M[i - 1].M) {
            m[M[i].ID].M = rm;
        }else {
            rm = i + 1;
            m[M[i].ID].M = rm;
        }
    }
    for (int i = 0; i < many; i++) {
        int t; scanf("%d", &t);
        if (m.find(t) == m.end()) {
            printf("N/A");
        }else {
            int rank[4];
            rank[0] = m[t].A;
            rank[1] = m[t].C;
            rank[2] = m[t].M;
            rank[3] = m[t].E;
            int index = 0;
            for (int j = 0; j < 4; j++) {
                if (rank[j] < rank[index]) {
                    index = j;
                }
            }
            if (index == 0) printf("%d A", rank[index]);
            if (index == 1) printf("%d C", rank[index]);
            if (index == 2) printf("%d M", rank[index]);
            if (index == 3) printf("%d E", rank[index]);
        }
        printf("\n");
    }
}
