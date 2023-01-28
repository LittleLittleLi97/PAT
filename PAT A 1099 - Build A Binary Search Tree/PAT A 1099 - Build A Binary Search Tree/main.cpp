//
//  main.cpp
//  PAT A 1099 - Build A Binary Search Tree
//
//  Created by 97 on 2019/11/26.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
    int Data;
    int Left;
    int Right;
};
Node v[110];
int Data[110];
int N;
int nowCount = 0;

void InOrderTraversal(int index){
    if (v[index].Left != -1) InOrderTraversal(v[index].Left);
    v[index].Data = Data[nowCount++];
    if (v[index].Right != -1) InOrderTraversal(v[index].Right);
}

void LevelTraversal(int st){
    queue<int> q;
    q.push(st);
    bool flag = false;
    while (!q.empty()) {
        int which = q.front();
        q.pop();
        if (flag == true) printf(" ");
        printf("%d", v[which].Data);
        flag = true;
        if (v[which].Left != -1) q.push(v[which].Left);
        if (v[which].Right != -1) q.push(v[which].Right);
    }
}

int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &v[i].Left, &v[i].Right);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &Data[i]);
    }
    sort(Data, Data + N);
    InOrderTraversal(0);
    LevelTraversal(0);
}
