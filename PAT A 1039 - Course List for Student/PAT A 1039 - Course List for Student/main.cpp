//
//  main.cpp
//  PAT A 1039 - Course List for Student
//
//  Created by 97 on 2019/11/15.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>
using namespace std;

map<string, vector<int>> m;
int N, K;

int main(){
    scanf("%d%d", &N, &K);
    for (int i = 0; i < K; i++) {
        int course, many; scanf("%d%d", &course, &many);
        for (int j = 0; j < many; j++) {
            char name[5]; scanf("%s", name);
            m[name].push_back(course);
        }
    }
    
    for (int i = 0; i < N; i++) {
        char name[5]; scanf("%s", name);
        sort(m[name].begin(), m[name].end());
        printf("%s %ld", name, m[name].size());
        for (int j = 0; j < m[name].size(); j++) {
            printf(" %d", m[name][j]);
        }
        printf("\n");
    }
}
