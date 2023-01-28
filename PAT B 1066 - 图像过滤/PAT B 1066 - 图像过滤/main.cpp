//
//  main.cpp
//  PAT B 1066 - 图像过滤
//
//  Created by 97 on 2019/9/1.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int M, N, A, B, what;
    cin >> M >> N >> A >> B >> what;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int t; scanf("%d", &t);
            if (j != 0) printf(" ");
            if (t >= A && t <= B) printf("%03d", what);
            else printf("%03d", t);
        }
        printf("\n");
    }
}
