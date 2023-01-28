//
//  main.cpp
//  PAT A 1064 - Complete Binary Search Tree
//
//  Created by 97 on 2019/11/26.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int N;
int original[1010];
int Tree[1010];
int nowCount = 0;

void InorderTraversal(int index){
    if (index > N) return;
    InorderTraversal(index * 2);
    Tree[index] = original[nowCount++];
    InorderTraversal(index * 2 + 1);
}

int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &original[i]);
    }
    sort(original, original + N);
    InorderTraversal(1);
    for (int i = 1; i <= N; i++) {
        printf("%d", Tree[i]);
        if (i != N) printf(" ");
    }
}
