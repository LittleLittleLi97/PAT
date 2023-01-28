//
//  main.cpp
//  PAT A 1063 - Set Similarity
//
//  Created by 97 on 2019/11/16.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;

set<int> v[60];
int N, K;

int main(){
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        int many; scanf("%d", &many);
        for (int j = 0; j < many; j++) {
            int t; scanf("%d", &t);
            v[i].insert(t);
        }
    }
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        int a, b; scanf("%d%d", &a, &b);
        int count = 0;
        int totalcount = v[b].size();
//        set<int> t;
        for (set<int> :: iterator it = v[a].begin(); it != v[a].end(); it++) {
            if (v[b].find(*it) != v[b].end()) count++;
            else totalcount++;
//            t.insert(*it);
        }
//        for (set<int> :: iterator it = v[b].begin(); it != v[b].end(); it++) {
//            t.insert(*it);
//        }
        printf("%.1lf%%\n", 100 * ((double)count / totalcount));
    }
}
