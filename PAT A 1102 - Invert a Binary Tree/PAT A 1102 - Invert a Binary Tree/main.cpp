//
//  main.cpp
//  PAT A 1102 - Invert a Binary Tree
//
//  Created by 97 on 2019/11/25.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct IN {
    int Left;
    int Right;
};
vector<IN> v;
struct Node {
    int Data;
    Node *Left;
    Node *Right;
};
bool ever[10];
int N;
bool inorderFlag = false;

int Change(char a){
    if (a >= '0' && a <= '9') {
        ever[a - '0'] = true;
        return a - '0';
    } else return -1;
}

int FindRoot(){
    for (int i = 0; i < N; i++) {
        if (ever[i] == false) return i;
    }
    return -1;
}

Node* Create(int Data){
    Node *root = new Node;
    root->Data = Data;
    if (v[Data].Left != -1) root->Left = Create(v[Data].Left);
    else root->Left = NULL;
    if (v[Data].Right != -1) root->Right = Create(v[Data].Right);
    else root->Right = NULL;
    return root;
}

void InvertLevelTraversal(Node *Tree){
    queue<Node *> q;
    q.push(Tree);
    bool flag = false;
    while (!q.empty()) {
        Node *t = q.front();
        q.pop();
        if (flag == true) printf(" ");
        printf("%d", t->Data);
        flag = true;
        if (t->Right) q.push(t->Right);
        if (t->Left) q.push(t->Left);
    }
}

void InvertInOrderTraversal(Node *Tree){
    if (Tree->Right) InvertInOrderTraversal(Tree->Right);
    if (inorderFlag == true) printf(" ");
    printf("%d", Tree->Data);
    inorderFlag = true;
    if (Tree->Left) InvertInOrderTraversal(Tree->Left);
}

//void pre(Node *T){
//    printf("%d ", T->Data);
//    if (T->Left) pre(T->Left);
//    if (T->Right) pre(T->Right);
//}

int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char a[2], b[2];
        scanf("%s%s", a, b);
        IN t;
        t.Left = Change(a[0]);
        t.Right = Change(b[0]);
        v.push_back(t);
    }
//    for (int i = 0; i < v.size(); i++) {
//        printf("%d %d\n", v[i].Left, v[i].Right);
//    }
    int rootIndex = FindRoot();
//    cout << rootIndex;
    Node *Tree = Create(rootIndex);
    InvertLevelTraversal(Tree);
    printf("\n");
    InvertInOrderTraversal(Tree);
}
