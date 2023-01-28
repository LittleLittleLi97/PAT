//
//  main.cpp
//  PAT A 1047 - Student List for Course
//
//  Created by 97 on 2019/11/15.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

vector<string> v[2510];
int N, K;

bool cmp(string a, string b){
    return a < b;
}

int main(){
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) {
        char name[5]; scanf("%s", name);
        int many; scanf("%d", &many);
        for (int j = 0; j < many; j++) {
            int course; scanf("%d", &course);
            v[course].push_back(name);
        }
    }
    for (int i = 1; i <= K; i++) {
        printf("%d %ld\n", i, v[i].size());
        sort(v[i].begin(), v[i].end(), cmp);
        for (int j = 0; j < v[i].size(); j++) {
            printf("%s\n", v[i][j].c_str());
        }
    }
}
