//
//  main.cpp
//  习题
//
//  Created by 97 on 2020/11/26.
//  Copyright © 2020 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
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

int preNum2[6] = {1, 2, 3, 5, 6, 4};
int inNum2[6] = {3, 2, 6, 5, 1, 4};

typedef struct BiTNode {
    int data;
    struct BiTNode *lchid, *rchild;
    int depth;
}BiTNode, *BiTree;

BiTree CreateBiTreeWithPreAndIn(int Pre[], int In[], int preLeft, int preRight, int inLeft, int inRight){
    BiTree root = (BiTree)malloc(sizeof(BiTNode));
    root->data = Pre[preLeft];
    root->lchid = root->rchild = NULL;
    root->depth = 0;
    int u = inLeft;
    while (In[u] != root->data) u++;
    int leftNum = u - inLeft;
    int rightNum = inRight - u;
    if (leftNum) root->lchid = CreateBiTreeWithPreAndIn(Pre, In, preLeft + 1, preLeft + leftNum, inLeft, u - 1);
    if (rightNum) root->rchild = CreateBiTreeWithPreAndIn(Pre, In, preLeft + leftNum + 1, preRight, u + 1, inRight);
    return root;
}

void PreOrderTraversal(BiTree T){
    if (T) {
        printf("Data: %d Depth: %d\n", T->data, T->depth);
        PreOrderTraversal(T->lchid);
        PreOrderTraversal(T->rchild);
    }
}

int BiTreeDepth(BiTree T){
    if (T == NULL) return 0;
    int depth = BiTreeDepth(T->lchid) > BiTreeDepth(T->rchild) ? BiTreeDepth(T->lchid) + 1 : BiTreeDepth(T->rchild) + 1;
    T->depth = depth;
    return depth;
}

int BiTreeBalanced(BiTree T){
    int leftTag = 1;
    if (T->lchid) leftTag = BiTreeBalanced(T->lchid);
    int rightTag = 1;
    if (T->rchild) rightTag = BiTreeBalanced(T->rchild);
    int leftDepth = T->lchid ? T->lchid->depth : 0;
    int rightDepth = T->rchild ? T->rchild->depth : 0;
    int factor = leftDepth - rightDepth;
    if (abs(factor) <= 1 && leftTag && rightTag) return 1;
    else return 0;
}

int BiTreeBalanced_PreOrder(BiTree T){
    if (T) {
        int leftDepth = T->lchid ? T->lchid->depth : 0;
        int rightDepth = T->rchild ? T->rchild->depth : 0;
        int factor = leftDepth - rightDepth;
        if (abs(factor) > 1) return 0;
        else return BiTreeBalanced_PreOrder(T->lchid) && BiTreeBalanced_PreOrder(T->rchild);
    }
    return true;
}

int main(){
    BiTree root = CreateBiTreeWithPreAndIn(preNum, inNum, 0, 9, 0, 9);
    BiTreeDepth(root);
    PreOrderTraversal(root);
    cout << BiTreeBalanced_PreOrder(root);
}
