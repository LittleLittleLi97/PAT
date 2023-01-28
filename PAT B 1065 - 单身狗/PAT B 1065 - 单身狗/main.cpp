//
//  main.cpp
//  PAT B 1065 - 单身狗
//
//  Created by 97 on 2019/9/1.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
using namespace std;

unordered_map<string, string> m;
vector<string> come;
vector<string> out;
bool ever[1000010] = {false};

int main(){
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        string a, b; cin >> a >> b;
        m[a] = b;
        m[b] = a;
    }
    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        string t; cin >> t;
        ever[stoi(t)] = true;
        come.push_back(t);
    }
    for (int i = 0; i < come.size(); i++) {
        if (m[come[i]] == "") out.push_back(come[i]);
        else if(ever[stoi(m[come[i]])] == false) out.push_back(come[i]);
    }
    sort(out.begin(), out.end());
    printf("%ld\n", out.size());
    for (int i = 0; i < out.size(); i++) {
        if (i != 0) printf(" ");
        printf("%s", out[i].c_str());
    }
}
