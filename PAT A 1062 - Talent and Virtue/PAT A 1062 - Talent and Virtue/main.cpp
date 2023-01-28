//
//  main.cpp
//  PAT A 1062 - Talent and Virtue
//
//  Created by 97 on 2019/10/21.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int ID;
    int Virtue;
    int Talent;
    int Total;
};
vector<Node> v;
vector<Node> sage, noble, fool, rest;
int N, L, H;

bool cmp(Node a, Node b){
    if (a.Total != b.Total) return a.Total > b.Total;
    else if (a.Virtue != b.Virtue) return a.Virtue > b.Virtue;
    else return a.ID < b.ID;
}

int main(){
    scanf("%d %d %d", &N, &L, &H);
    for (int i = 0; i < N; i++) {
        Node t; scanf("%d %d %d", &t.ID, &t.Virtue, & t.Talent);
        t.Total = t.Virtue + t.Talent;
        if (t.Virtue < L || t.Talent < L) continue;
        if (t.Virtue >= H && t.Talent >= H) sage.push_back(t);
        else if (t.Virtue >= H) noble.push_back(t);
        else if (t.Virtue >= t.Talent) fool.push_back(t);
        else rest.push_back(t);
    }
    sort(sage.begin(), sage.end(), cmp);
    sort(noble.begin(), noble.end(), cmp);
    sort(fool.begin(), fool.end(), cmp);
    sort(rest.begin(), rest.end(), cmp);
    printf("%d\n", sage.size() + noble.size() + fool.size() + rest.size());
    for (int i = 0; i < sage.size(); i++) {
        Node t = sage[i];
        printf("%d %d %d\n", t.ID, t.Virtue, t.Talent);
    }
    for (int i = 0; i < noble.size(); i++) {
        Node t = noble[i];
        printf("%d %d %d\n", t.ID, t.Virtue, t.Talent);
    }
    for (int i = 0; i < fool.size(); i++) {
        Node t = fool[i];
        printf("%d %d %d\n", t.ID, t.Virtue, t.Talent);
    }
    for (int i = 0; i < rest.size(); i++) {
        Node t = rest[i];
        printf("%d %d %d\n", t.ID, t.Virtue, t.Talent);
    }
}
