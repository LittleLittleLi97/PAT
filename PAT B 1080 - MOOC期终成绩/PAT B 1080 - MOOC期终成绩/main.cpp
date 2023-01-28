//
//  main.cpp
//  PAT B 1080 - MOOC期终成绩
//
//  Created by 97 on 2019/8/23.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

struct Node {
    int pingshi;
    int zhong;
    int mo;
    int grade;
};

struct range {
    string id;
    Node what;
};

unordered_map<string, Node> a;
vector<range> v;

bool cmp(range x, range y){
    if (x.what.grade != y.what.grade) return x.what.grade > y.what.grade;
    else return x.id < y.id;
}

int main(){
    int P, M, N;
    cin >> P >> M >> N;
    string id; int grade;
    for (int i = 0; i < P; i++) {
        cin >> id >> grade;
        a[id].pingshi = grade;
    }
    for (int i = 0; i < M; i++) {
        cin >> id >> grade;
        a[id].zhong = grade;
    }
    for (int i = 0; i < N; i++) {
        cin >> id >> grade;
        a[id].mo = grade;
    }
    for (auto it : a) {
        if (it.second.pingshi < 200) continue;
        if (it.second.zhong > it.second.mo) it.second.grade = round((double)it.second.zhong * 0.4 + (double)it.second.mo * 0.6);
        else it.second.grade = it.second.mo;
        if (it.second.grade < 60) continue;
        v.push_back({it.first, it.second});
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++) {
        printf("%s %d ", v[i].id.c_str(), v[i].what.pingshi);
        if (!v[i].what.zhong) printf("-1 ");
        else printf("%d ", v[i].what.zhong);
        if (!v[i].what.mo) printf("-1 ");
        else printf("%d ", v[i].what.mo);
        printf("%d\n", v[i].what.grade);
    }
}
