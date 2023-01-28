//
//  main.cpp
//  PAT A 1043 - Is It a Binary Search Tree
//
//  Created by 97 on 2019/10/7.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

struct Node {
    int Data;
    Node *Left;
    Node *Right;
};
int N;
vector<int> v;
vector<int> first, second;
bool flag1 = false;
bool flag2 = false;

void Insert(Node * & T, int Data){
    if (T == NULL) {
        Node *root = new Node;
        root->Left = root->Right = NULL;
        root->Data = Data;
        T = root;
        return;
    }
    if (Data < T->Data) Insert(T->Left, Data);
    else Insert(T->Right, Data);
}

Node* Create(){
    Node *root = new Node;
    root->Left = root->Right = NULL;
    int t; scanf("%d", &t);
    root->Data = t;
    v.push_back(t);
    for (int i = 1; i < N; i++) {
        scanf("%d", &t);
        v.push_back(t);
        Insert(root, t);
    }
    return root;
}

void firstPre(Node *T){
    first.push_back(T->Data);
    if (T->Left) firstPre(T->Left);
    if (T->Right) firstPre(T->Right);
}

void secondPre(Node *T){
    second.push_back(T->Data);
    if (T->Right) secondPre(T->Right);
    if (T->Left) secondPre(T->Left);
}

void firstPost(Node *T){
    if (T->Left) firstPost(T->Left);
    if (T->Right) firstPost(T->Right);
    if (flag1 == true) printf(" ");
    printf("%d", T->Data);
    flag1 = true;
}

void secondPost(Node *T){
    if (T->Right) secondPost(T->Right);
    if (T->Left) secondPost(T->Left);
    if (flag2 == true) printf(" ");
    printf("%d", T->Data);
    flag2 = true;
}

int main(){
    scanf("%d", &N);
    Node *T = Create();
    firstPre(T);
    secondPre(T);
    if (first == v) {
        printf("YES\n");
        firstPost(T);
        return 0;
    }
    if (second == v) {
        printf("YES\n");
        secondPost(T);
    }else printf("NO");
    
}
