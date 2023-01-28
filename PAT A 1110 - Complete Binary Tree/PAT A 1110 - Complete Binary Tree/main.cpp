//
//  main.cpp
//  PAT A 1110 - Complete Binary Tree
//
//  Created by 97 on 2019/12/3.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct Node {
    int Left;
    int Right;
};
vector<Node> T;
bool notRoot[22];
int N;
int last = -1;

int Change(string a){
    if (a[0] == '-') {
        return -1;
    }else {
        int out = stoi(a);
        notRoot[out] = true;
        return out;
    }
}

bool LevelTraversal(int st){
    last = st;
    queue<Node> q;
    q.push(T[st]);
    bool flag = false;
    while (!q.empty()) {
        Node t = q.front();
        q.pop();
        if (t.Left != -1) {
            q.push(T[t.Left]);
            last = t.Left;
            if (flag == true) return false;
        }else {
            flag = true;
        }
        if (t.Right != -1) {
            q.push(T[t.Right]);
            last = t.Right;
            if (flag == true) return false;
        }else {
            flag = true;
        }
    }
    return true;
}

int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char a[5], b[5];
        scanf("%s %s", a, b);
        Node will;
        will.Left = Change(a);
        will.Right = Change(b);
        T.push_back(will);
    }
    int root = -1;
    for (int i = 0; i < N; i++) {
        if (notRoot[i] == false) {
            root = i;
            break;
        }
    }
    if (LevelTraversal(root) == false) {
        printf("NO %d", root);
    }else printf("YES %d", last);
}
