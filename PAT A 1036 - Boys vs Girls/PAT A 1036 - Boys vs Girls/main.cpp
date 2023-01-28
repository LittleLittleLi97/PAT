//
//  main.cpp
//  PAT A 1036 - Boys vs Girls
//
//  Created by 97 on 2019/10/18.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Node {
    string Name;
    string ID;
    int Grade;
};
vector<Node> M, F;
int N;

bool cmpF(Node a, Node b){
    return a.Grade > b.Grade;
}

bool cmpM(Node a, Node b){
    return a.Grade < b.Grade;
}

int main(){
    cin >> N;
    for (int i = 0; i < N; i++) {
        Node t; char gender;
        cin >> t.Name >> gender >> t.ID >> t.Grade;
        if (gender == 'M') M.push_back(t);
        else if (gender == 'F') F.push_back(t);
    }
    sort(F.begin(), F.end(), cmpF);
    sort(M.begin(), M.end(), cmpM);
    bool flag = false;
    if (F.size() == 0) {
        printf("Absent\n");
        flag = true;
    }else printf("%s %s\n", F[0].Name.c_str(), F[0].ID.c_str());
    if (M.size() == 0) {
        printf("Absent\n");
        flag = true;
    }else printf("%s %s\n", M[0].Name.c_str(), M[0].ID.c_str());
    if (flag == true) {
        printf("NA");
    }else printf("%d", F[0].Grade - M[0].Grade);
}
