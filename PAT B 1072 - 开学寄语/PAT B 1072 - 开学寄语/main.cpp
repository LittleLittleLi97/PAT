//
//  main.cpp
//  PAT B 1072 - 开学寄语
//
//  Created by 97 on 2019/8/24.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

bool a[10000] = {false};

int main(){
    int N, M;
    cin >> N >> M;
    int stu = 0;
    int total = 0;
    for (int i = 0; i < M; i++) {
        int t; cin >> t;
        a[t] = true;
    }
    for (int i = 0; i < N; i++) {
        string name;
        int kind;
        int t;
        vector<int> v;
        cin >> name >> kind;
        for (int j = 0; j < kind; j++) {
            cin >> t;
            if (a[t] == true) {
                v.push_back(t);
                total++;
            }
        }
        if (!v.empty()) {
            printf("%s:", name.c_str());
            stu++;
        }else continue;
        for (int j = 0; j < v.size(); j++) {
            printf(" %04d", v[j]);
        }
        printf("\n");
    }
    printf("%d %d", stu, total);
}
