//
//  main.cpp
//  PAT B 1085 - PAT单位排行
//
//  Created by 97 on 2019/8/22.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Node {
    int A;
    int B;
    int T;
    int Grade;
    int Many;
};

struct Node2 {
    string Name;
    Node what;
};

unordered_map<string, Node> m;
vector<Node2> v;

bool cmp(Node2 a, Node2 b){
    if ((int)a.what.Grade != (int)b.what.Grade) return (int)a.what.Grade > (int)b.what.Grade;
    else if (a.what.Many != b.what.Many) return a.what.Many < b.what.Many;
    else return a.Name < b.Name;
}

string to_lower(string a){
    for (int i = 0; i < a.length(); i++) {
        if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 32;
    }
    return a;
}

int main(){
    int N;
    cin >> N;
    string hao; double grade; string school;
    for (int i = 0; i < N; i++) {
        cin >> hao >> grade >> school;
        school = to_lower(school);
        if (hao[0] == 'B') m[school].B += grade;
        else if (hao[0] == 'A') m[school].A += grade;
        else if (hao[0] == 'T') m[school].T += grade;
        m[school].Many++;
    }
    for (auto it : m) v.push_back({it.first, it.second});
    for (int i = 0; i < v.size(); i++) v[i].what.Grade = v[i].what.A + v[i].what.B / 1.5 + v[i].what.T * 1.5;
//    cout << v[0].Name << " " << v[0].what.Grade << " " << v[0].what.Many;
    sort(v.begin(), v.end(), cmp);
    int realrank = 1;
    int momentrank = 1;
    printf("%ld\n", v.size());
    printf("%d %s %d %d", momentrank, v[0].Name.c_str(), (int)v[0].what.Grade, v[0].what.Many);
    realrank++;
    for (int i = 1; i < v.size(); i++) {
        if ((int)v[i].what.Grade != (int)v[i - 1].what.Grade) momentrank = realrank;
        printf("\n");
        printf("%d %s %d %d", momentrank, v[i].Name.c_str(), (int)v[i].what.Grade, v[i].what.Many);
        realrank++;
    }
}
