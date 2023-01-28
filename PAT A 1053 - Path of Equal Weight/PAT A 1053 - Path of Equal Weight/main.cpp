//
//  main.cpp
//  PAT A 1053 - Path of Equal Weight
//
//  Created by 97 on 2019/10/5.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
    int Weight;
    vector<int> Sub;
};
Node v[110];
int N, M, S;
vector<vector<int>> Path;
vector<int> tPath;

bool cmp(vector<int> a, vector<int> b){
    return a > b;
}

void DFS(int which, int weight){
    weight += v[which].Weight;
    tPath.push_back(v[which].Weight);
    if (weight > S) { return;}
    if (weight == S && v[which].Sub.size() == 0) {
        Path.push_back(tPath);
        return;
    }
    if (weight < S && v[which].Sub.size() == 0) {
        return;
    }
    for (int i = 0; i < v[which].Sub.size(); i++) {
        DFS(v[which].Sub[i], weight);
        tPath.pop_back();
    }
}

int main(){
    scanf("%d %d %d", &N, &M, &S);
    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i].Weight);
    }
    for (int i = 0; i < M; i++) {
        int which, many; scanf("%d %d", &which, &many);
        for (int j = 0; j < many; j++) {
            int t; scanf("%d", &t);
            v[which].Sub.push_back(t);
        }
    }
    DFS(0, 0);
    sort(Path.begin(), Path.end(), cmp);
//    cout << Path.size() << endl;
    for (int i = 0; i < Path.size(); i++) {
        for (int j = 0; j < Path[i].size(); j++) {
            printf("%d", Path[i][j]);
            if (j != Path[i].size() - 1) printf(" ");
        }
        printf("\n");
    }
}
