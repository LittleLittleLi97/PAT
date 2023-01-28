//
//  main.cpp
//  PAT A 1118 - Birds in Forest
//
//  Created by 97 on 2019/12/6.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

vector<int> v[10010];
map<int, vector<int>> mNumtoIndex;
bool ever[10010];
map<int, int> mTree;
int vSize = 1;
int N, Q;

void DFS(int st, int whichTree){
    mTree[st] = whichTree;
    ever[st] = true;
    for (int i = 0; i < mNumtoIndex[st].size(); i++) {
        int will = mNumtoIndex[st][i];
        for (int j = 0; j < v[will].size(); j++) {
            if (ever[v[will][j]] == false) {
                DFS(v[will][j], whichTree);
            }
        }
    }
}

int DFSTraversal(){
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if(ever[v[i][j]] == false) {
                DFS(v[i][j], i);
                count++;
            }
        }
    }
    return count;
}

int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int many; scanf("%d", &many);
        for (int j = 0; j < many; j++) {
            int b; scanf("%d", &b);
            v[i].push_back(b);
            mNumtoIndex[b].push_back(i);
        }
    }
    int count = DFSTraversal();
    printf("%d %ld\n", count, mTree.size());
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        int a, b; scanf("%d%d", &a, &b);
        if (mTree[a] == mTree[b]) printf("Yes\n");
        else printf("No\n");
    }
}
