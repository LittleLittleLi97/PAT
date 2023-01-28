//
//  main.cpp
//  PAT B 1069 - 微博转发抽奖
//
//  Created by 97 on 2019/9/2.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> v;
unordered_map<string, int> m;

int main(){
    int total, gap, first;
    cin >> total >> gap >> first;
    int count = 0;
    for (int i = 1; i <= total; i++) {
        string t; cin >> t;
        if (i == first + count * gap) {
            if (m[t] == 0) {
                m[t] = 1;
                v.push_back(t);
                count++;
            }else {
                first = i + 1;
                count = 0;
            }
        }
    }
    if (v.size() == 0) printf("Keep going...");
    else {
        for (int i = 0; i < v.size(); i++) {
            printf("%s\n", v[i].c_str());
        }
    }
}
