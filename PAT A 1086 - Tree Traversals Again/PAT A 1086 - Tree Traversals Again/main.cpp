//
//  main.cpp
//  PAT A 1086 - Tree Traversals Again
//
//  Created by 97 on 2019/11/23.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;

struct Node {
    int Data;
    Node *Left;
    Node *Right;
};
stack<int> s;
vector<int> in;
vector<int> pre;
int N;
bool flag = false;

Node* Create(int preLeft, int preRight, int inLeft, int inRight){
    if (preLeft > preRight) return NULL;
    Node *root = new Node;
    root->Data = pre[preLeft];
    int k = -1;
    for (int i = inLeft; i <= inRight; i++) {
        if (in[i] == pre[preLeft]) {
            k = i;
            break;
        }
    }
    int numLeft = k - inLeft;
    root->Left = Create(preLeft + 1, preLeft + numLeft, inLeft, k - 1);
    root->Right = Create(preLeft + numLeft + 1, preRight, k + 1, inRight);
    return root;
}

void PostTraversal(Node *Tree){
    if (Tree->Left) PostTraversal(Tree->Left);
    if (Tree->Right) PostTraversal(Tree->Right);
    if (flag == true) printf(" ");
    printf("%d", Tree->Data);
    flag = true;
}

int main(){
    scanf("%d", &N);
    for (int i = 0; i < N || !s.empty(); ) {
        char a[5]; scanf("%s", a);
        if (a[1] == 'u') {
            int t; scanf("%d", &t);
            pre.push_back(t);
            s.push(t);
            i++;
        }else if (a[1] == 'o') {
            in.push_back(s.top());
            s.pop();
        }
    }
//    for (int i = 0; i < in.size(); i++) {
//        printf("%d ", in[i]);
//    }
//    printf("\n");
//    for (int i = 0; i < pre.size(); i++) {
//        printf("%d ", pre[i]);
//    }
    Node *Tree = Create(0, N - 1, 0, N - 1);
    PostTraversal(Tree);
}
