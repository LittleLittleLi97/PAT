//
//  main.cpp
//  PAT A 1066 - Root of AVL Tree
//
//  Created by 97 on 2019/11/26.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;

struct Node {
    int Data;
    Node *Left;
    Node *Right;
    int Height;
};
Node *root;
int N;
int a[22];

void updateHeight(Node *root);
int getHeight(Node *root);

void L(Node *&root){
    Node *t = root->Right;
    root->Right = t->Left;
    t->Left = root;
    updateHeight(root);
    updateHeight(t);
    root = t;
}

void R(Node *&root){
    Node *t = root->Left;
    root->Left = t->Right;
    t->Right = root;
    updateHeight(root);
    updateHeight(t);
    root = t;
}

int getHeight(Node *root){
    if (root == NULL) return 0;
    else return root->Height;
}

void updateHeight(Node *root){
    root->Height = max(getHeight(root->Left), getHeight(root->Right)) + 1;
}

int getFactor(Node *root){
    return getHeight(root->Left) - getHeight(root->Right);
}

Node* newNode(int Data){
    Node *root = new Node;
    root->Data = Data;
    root->Left = root->Right = NULL;
    root->Height = 1;
    return root;
}

void Insert(Node *&root, int Data){
    if (root == NULL) {
        root = newNode(Data);
        return;
    }
    if (Data < root->Data) {
        Insert(root->Left, Data);
        updateHeight(root);
        if (getFactor(root) == 2) {
            if (getFactor(root->Left) == 1) {
                R(root);
            }else if (getFactor(root->Left) == -1){
                L(root->Left);
                R(root);
            }
        }
    }else {
        Insert(root->Right, Data);
        updateHeight(root);
        if (getFactor(root) == -2) {
            if (getFactor(root->Right) == -1) {
                L(root);
            }else if (getFactor(root->Right) == 1){
                R(root->Right);
                L(root);
            }
        }
    }
}

Node* Create(int Data[], int n){
    Node *root = NULL;
    for (int i = 0; i < n; i++) {
        Insert(root, Data[i]);
    }
    return root;
}

int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    root = Create(a, N);
    printf("%d", root->Data);
}
