//
//  main.cpp
//  PAT A 1021 - Deepest Root
//
//  Created by 97 on 2019/11/5.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#define MaxSize 10010
using namespace std;

struct Node {
    int root;
    int Depth;
};
vector<Node> v;
bool Graph[MaxSize][MaxSize];
bool ever[MaxSize];
int N;

bool cmp(Node a, Node b){
    if (a.Depth != b.Depth) return a.Depth > b.Depth;
    else return a.root < b.root;
}

void DFSTraversal(int st, int nowDepth, int &maxDepth){
    nowDepth++;
    if (nowDepth > maxDepth) maxDepth = nowDepth;
    ever[st] = true;
    for (int i = 1; i <= N; i++) {
        if (ever[i] == false && Graph[st][i] == true) {
            DFSTraversal(i, nowDepth, maxDepth);
        }
    }
}

int DFS(){
    for (int i = 1; i <= N; i++) {
        fill(ever, ever + MaxSize, false);
        int count = 0;
        for (int j = i; j <= N; j++) {
            if (ever[j] == false) {
                int maxDepth = 0;
                DFSTraversal(j, 0, maxDepth);
                count++;
                v.push_back({j, maxDepth});
            }
        }
        if (count > 1) return count;
    }
    return 0;
}

int main(){
    scanf("%d", &N);
    for (int i = 0; i < N - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        Graph[a][b] = Graph[b][a] = true;
    }
    int count = DFS();
//    cout << count << endl;
    if (count > 0) {
        printf("Error: %d components", count);
    }else {
        sort(v.begin(), v.end(), cmp);
        int depth = v[0].Depth;
        for (int i = 0; i < v.size(); i++) {
            if (v[i].Depth == depth) {
                printf("%d\n", v[i].root);
            }else break;
        }
    }
}
