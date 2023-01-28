//
//  main.cpp
//  PAT A 1115 - Counting Nodes in a BST
//
//  Created by 97 on 2019/12/5.
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
    int Level;
};
int num[1010];
int N;

void LevelTraversal(Node *root){
    root->Level = 1;
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        Node *t = q.front();
        q.pop();
        num[t->Level]++;
        if (t->Left != NULL) {
            t->Left->Level = t->Level + 1;
            q.push(t->Left);
        }
        if (t->Right != NULL) {
            t->Right->Level = t->Level + 1;
            q.push(t->Right);
        }
    }
}

void Insert(int Data, Node * &root){
    if (root == NULL) {
        Node *t = new Node;
        t->Left = t->Right = NULL;
        t->Data = Data;
        root = t;
        return;
    }else if (Data <= root->Data) Insert(Data, root->Left);
    else if (Data > root->Data) Insert(Data, root->Right);
}

int main(){
    scanf("%d", &N);
    Node *root = NULL;
    for (int i = 0; i < N; i++) {
        int t; scanf("%d", &t);
        Insert(t, root);
    }
    LevelTraversal(root);
    int last = 0;
    for (int i = 0; i <= N; i++) {
        if (num[i] != 0) {
            last = i;
        }
    }
    printf("%d + %d = %d", num[last], num[last - 1], num[last - 1] + num[last]);
}
