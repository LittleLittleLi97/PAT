//
//  main.cpp
//  20201121 Bitree
//
//  Created by 97 on 2020/11/21.
//  Copyright © 2020 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

int preNum[10] = {10, 5, 3, 7, 6, 15, 14, 19, 18, 20};
int inNum[10] = {3, 5, 6, 7, 10, 14, 15, 18, 19, 20};
//            10
//          /    \
//         5      15
//       /  \    /  \
//      3    7  14  19
//          /      /  \
//         6      18   20


typedef struct BiTNode {
    int Data;
    struct BiTNode *Left, *Right;
} BiTNode, *BiTree;

BiTree CreateTreeWithPreAndIn(int pre[], int in[], int preLeft, int preRight, int inLeft, int inRight){
    BiTree root = (BiTree)malloc(sizeof(BiTNode));
    root->Data = pre[preLeft];
    root->Left = root->Right = NULL;
    int u = inLeft;
    while (in[u] != root->Data) u++;
    int numLeft = u - inLeft;
    int numRight = inRight - u;
    if (numLeft) root->Left = CreateTreeWithPreAndIn(pre, in, preLeft + 1, preLeft + numLeft, inLeft, u - 1);
    if (numRight) root->Right = CreateTreeWithPreAndIn(pre, in, preLeft + numLeft + 1, preRight, u + 1, inRight);
    return root;
}

void PreOrderTraversal(BiTree T){
    if (T) {
        printf("%d\t", T->Data);
        PreOrderTraversal(T->Left);
        PreOrderTraversal(T->Right);
    }
}

void InOrderTraversal(BiTree T){
    if (T) {
        InOrderTraversal(T->Left);
        printf("%d\t", T->Data);
        InOrderTraversal(T->Right);
    }
}

int GetHeight(BiTree T){
    if (T == NULL) return 0;
    else return GetHeight(T->Left) > GetHeight(T->Right) ? GetHeight(T->Left) + 1 : GetHeight(T->Right) + 1;
}

void Insert(BiTree &root, int x){
    if (root == NULL) {
        root = (BiTree)malloc(sizeof(BiTNode));
        root->Data = x;
        root->Left = root->Right = NULL;
        return;
    }
    if (x < root->Data) Insert(root->Left, x);
    else Insert(root->Right, x);
}

BiTree CreateBST(int A[], int n){
    BiTree root = NULL;
    for (int i = 0; i < n; i++) {
        Insert(root, A[i]);
    }
    return root;
}

void LRotation(BiTree &root){
    BiTree temp = root->Right;
    root->Right = temp->Left;
    temp->Left = root;
    root = temp;
}

void RRotation(BiTree &root){
    BiTree temp = root->Left;
    root->Left = temp->Right;
    temp->Right = root;
    root = temp;
}

void LRRotation(BiTree &root){
    LRotation(root->Left);
    RRotation(root);
}

void RLRotation(BiTree &root){
    RRotation(root->Right);
    LRotation(root);
}

int GetBalanceFactor(BiTree root){
    return GetHeight(root->Left) - GetHeight(root->Right);
}

void InsertAVL(BiTree &root, int x){
    if (root == NULL) {
        root = (BiTree)malloc(sizeof(BiTNode));
        root->Data = x;
        root->Left = root->Right = NULL;
        return;
    }
    if (x < root->Data) {
        InsertAVL(root->Left, x);
        if (GetBalanceFactor(root) == 2) {
            if (GetBalanceFactor(root->Left) == 1) RRotation(root);
            else LRRotation(root);
        }
    } else {
        InsertAVL(root->Right, x);
        if (GetBalanceFactor(root) == -2) {
            if (GetBalanceFactor(root->Right) == -1) LRotation(root);
            else RLRotation(root);
        }
    }
}

BiTree CreateAVL(int A[], int n){
    BiTree root = NULL;
    for (int i = 0; i < n; i++) {
        InsertAVL(root, A[i]);
    }
    return root;
}

void MaxDepth(BiTree T, int nowDepth, int &Depth){  // MaxDepth(root, 0, depth);
    if (T) {
        nowDepth++;
        if (nowDepth > Depth) Depth = nowDepth;
        MaxDepth(T->Left, nowDepth, Depth);
        MaxDepth(T->Right, nowDepth, Depth);
    }
}

void CountLeavesRecursive(BiTree T, int &num){
    if (T) {
        if (T->Left == NULL && T->Right == NULL) num++;
        CountLeavesRecursive(T->Left, num);
        CountLeavesRecursive(T->Right, num);
    }
}

int main(){
    BiTree root = CreateTreeWithPreAndIn(preNum, inNum, 0, 9, 0, 9);
    int num = 0;
    CountLeavesRecursive(root, num);
    cout << num << endl;
}
