//
//  main.cpp
//  PAT B 1041 - 考试座位号
//
//  Created by 97 on 2019/8/9.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

struct Node {
    char id[20];
    int shi;
    int real;
}Stu[1010];

int Find[1010];

bool cmp(Node a, Node b){
    return a.shi < b.shi;
}

int main(){
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s %d %d", Stu[i].id, &Stu[i].shi, &Stu[i].real);
    }
    sort(Stu, Stu + N, cmp);
    int M;
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &Find[i]);
    }
    for (int i = 0; i < M; i++) {
        if (i != 0) {
            printf("\n");
        }
        printf("%s %d", Stu[Find[i] - 1].id, Stu[Find[i] - 1].real);
    }
}
