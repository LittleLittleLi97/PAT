//
//  main.cpp
//  PAT A 1004 - Counting Leaves
//
//  Created by 97 on 2019/10/9.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int Level;
    vector<int> Leaves;
};
Node Tree[110];
int N, M;
int num[110];
int maxLevel = 0;

void LevelTraversal(){
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int which = q.front();
        q.pop();
        if (Tree[which].Leaves.size() == 0) num[Tree[which].Level]++;
        if (Tree[which].Level > maxLevel) maxLevel = Tree[which].Level;
        for (int i = 0; i < Tree[which].Leaves.size(); i++) {
            Tree[Tree[which].Leaves[i]].Level = Tree[which].Level + 1;
            q.push(Tree[which].Leaves[i]);
        }
    }
}

int main(){
    scanf("%d %d", &N, &M);
    if (N == 0) return 0;
    for (int i = 0; i < M; i++) {
        int which, K; scanf("%d %d", &which, &K);
        for (int j = 0; j < K; j++) {
            int sub; scanf("%d", &sub);
            Tree[which].Leaves.push_back(sub);
        }
    }
    Tree[1].Level = 0;
    LevelTraversal();
    for (int i = 0; i <= maxLevel; i++) {
        printf("%d", num[i]);
        if (i != maxLevel) printf(" ");
    }
}
