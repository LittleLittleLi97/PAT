//
//  main.cpp
//  PAT B 1090 - 危险品装箱
//
//  Created by 97 on 2019/8/20.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

vector<int> v[100000];

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        int a; int b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 0; i < M; i++) {
        int many; scanf("%d", &many);
        bool flag[100000] = {false};
        bool NY = false;
        for (int j = 0; j < many; j++) {
            int t; scanf("%d", &t);
            if (flag[t] == true) {
                printf("No\n");
                NY = true;
                break;
            }
            for (int k = 0; k < v[t].size(); k++) {
                flag[v[t][k]] = true;
            }
        }
        if (NY == false) printf("Yes\n");
    }
}
