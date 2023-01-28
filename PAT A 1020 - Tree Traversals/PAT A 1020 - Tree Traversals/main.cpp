//
//  main.cpp
//  PAT A 1020 - Tree Traversals
//
//  Created by 97 on 2019/10/5.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

struct Node {
    int Data;
    Node *Left;
    Node *Right;
};

int post[33];
int in[33];
int N;

Node* Create(int postLeft, int postRight, int inLeft, int inRight){
    if (postLeft > postRight) return NULL;
    Node* root = new Node;
    root->Data = post[postRight];
    int k = -1;
    for (int i = inLeft; i <= inRight; i++) {
        if (post[postRight] == in[i]) k = i;
    }
    int numLeft = k - inLeft;
    root->Left = Create(postLeft, postLeft + numLeft - 1, inLeft, k - 1);
    root->Right = Create(postLeft + numLeft, postRight - 1, k + 1, inRight);
    return root;
}

void LevelTravesal(Node *Tree){
    queue<Node*> q;
    q.push(Tree);
    bool flag = false;
    while (!q.empty()) {
        Node *T = q.front();
        q.pop();
        if (flag == true) printf(" ");
        printf("%d", T->Data);
        flag = true;
        if (T->Left) q.push(T->Left);
        if (T->Right) q.push(T->Right);
    }
}

int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &post[i]);
    for (int i = 0; i < N; i++) scanf("%d", &in[i]);
    Node *Tree = Create(0, N - 1, 0, N - 1);
    LevelTravesal(Tree);
}
