//
//  main.cpp
//  PAT A 1044 - Shopping in Mars
//
//  Created by 97 on 2019/11/6.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;

int worth[100010];
int total[100010];
int N, M;
int minTotal = INF;

int Find(int left, int right, int zhi){
    int frontTotal = total[left];
    while (left <= right) {
        int mid = (left + right) / 2;
        int nowTotal = total[mid] - frontTotal;
        if (nowTotal == zhi) return mid;
        else if (nowTotal < zhi) left = mid + 1;
        else right = mid - 1;
    }
    return left;
}

int main(){
    scanf("%d %d", &N, &M);
    worth[0] = total[0] = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &worth[i]);
        total[i] = worth[i - 1] + total[i - 1];
    }
    total[N + 1] = worth[N] + total[N];
//    for (int i = 1; i <= N + 1; i++) {
//        printf("%d ", total[i]);
//    }printf("\n");
    for (int i = 1; i <= N; i++) {
        int j = Find(i, N + 1, M);    // j在total中比worth中大1，total[1]从0开始
        if (total[j] - total[i] == M) {
            minTotal = M;
            break;
        }else if(j <= N + 1 && total[j] - total[i] < minTotal) {
            minTotal = total[j] - total[i];
//            printf(" - %d %d\n", i , j);
        }
    }
//    printf("%d\n", minTotal);
    for (int i = 1; i <= N; i++) {
        int j = Find(i, N + 1, M);
        if (total[j] - total[i] == minTotal) {
            printf("%d-%d\n", i, j - 1);
        }
    }
}
