//
//  main.cpp
//  PAT A 1041 - Be Unique
//
//  Created by 97 on 2019/11/20.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int ever[100010];
int N;
vector<int> v;

int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int t; scanf("%d", &t);
        ever[t]++;
        v.push_back(t);
    }
    for (int i = 0; i < v.size(); i++) {
        if (ever[v[i]] == 1) {
            printf("%d", v[i]);
            return 0;
        }
    }
    printf("None");
}
