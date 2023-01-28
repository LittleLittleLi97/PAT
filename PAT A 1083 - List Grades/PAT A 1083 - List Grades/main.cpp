//
//  main.cpp
//  PAT A 1083 - List Grades
//
//  Created by 97 on 2019/10/25.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    string Name;
    string ID;
    int Grade;
};
vector<Node> v;
int N;
int x, y;

bool cmp(Node a, Node b){
    return a.Grade > b.Grade;
}

int main(){
    cin >> N;
    for (int i = 0; i < N; i++) {
        Node t;
        cin >> t.Name >> t.ID >> t.Grade;
        v.push_back(t);
    }
    cin >> x >> y;
    sort(v.begin(), v.end(), cmp);
    bool flag = false;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].Grade >= x && v[i].Grade <= y) {
            flag = true;
            printf("%s %s\n", v[i].Name.c_str(), v[i].ID.c_str());
        }
    }
    if (flag == false) printf("NONE");
}
