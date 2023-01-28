//
//  main.cpp
//  PAT B 1068 - 万绿丛中一点红
//
//  Created by 97 on 2019/9/2.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
using namespace std;

struct Node {
    int i;
    int j;
    int Data;
};
vector<Node> v;

int main(){
    int M, N, TOL; scanf("%d %d %d", &M, &N, &TOL);
    int a[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < M - 1; j++) {
            //(abs(a[i][j] - a[i - 1][j - 1]) > TOL && abs(a[i][j] - a[i - 1][j]) > TOL && abs(a[i][j] - a[i - 1][j + 1]) > TOL && abs(a[i][j] - a[i][j - 1]) > TOL && abs(a[i][j] - a[i][j + 1]) > TOL && abs(a[i][j] - a[i + 1][j - 1]) > TOL && abs(a[i][j] - a[i + 1][j]) > TOL && abs(a[i][j] - a[i + 1][j + 1]) > TOL)
            if (a[i][j] - a[i - 1][j - 1] > TOL && a[i][j] - a[i - 1][j] > TOL && a[i][j] - a[i - 1][j + 1] > TOL && a[i][j] - a[i][j - 1] > TOL && a[i][j] - a[i][j + 1] > TOL && a[i][j] - a[i + 1][j - 1] > TOL && a[i][j] - a[i + 1][j] > TOL && a[i][j] - a[i + 1][j + 1] > TOL) {
                Node t; t.i = i + 1; t.j = j + 1; t.Data = a[i][j];
                v.push_back(t);
//                printf("%d - %d - %d\n", i, j, a[i][j]);
            }
        }
    }
    if (v.size() == 0) {
        printf("Not Exist");
    }else if (v.size() == 1) {
        printf("(%d, %d): %d", v[0].j, v[0].i, v[0].Data);
    }else {
        printf("Not Unique");
    }
}
