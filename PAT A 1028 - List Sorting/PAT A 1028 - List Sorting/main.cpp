//
//  main.cpp
//  PAT A 1028 - List Sorting
//
//  Created by 97 on 2019/10/23.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
    int ID;
    string Name;
    int Grade;
};
vector<Node> v;
int N, C;

bool cmp1(Node a, Node b){
    return a.ID < b.ID;
}

bool cmp2(Node a, Node b){
    if (a.Name != b.Name) return a.Name < b.Name;
    else return a.ID < b.ID;
}

bool cmp3(Node a, Node b){
    if (a.Grade != b.Grade) return a.Grade < b.Grade;
    else return a.ID < b.ID;
}

int main(){
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        Node t; cin >> t.ID >> t.Name >> t.Grade;
        v.push_back(t);
    }
    if (C == 1) sort(v.begin(), v.end(), cmp1);
    if (C == 2) sort(v.begin(), v.end(), cmp2);
    if (C == 3) sort(v.begin(), v.end(), cmp3);
    for (int i = 0; i < v.size(); i++) {
        printf("%06d %s %d\n", v[i].ID, v[i].Name.c_str(), v[i].Grade);
    }
}
