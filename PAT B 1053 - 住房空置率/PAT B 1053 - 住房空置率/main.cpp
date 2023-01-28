//
//  main.cpp
//  PAT B 1053 - 住房空置率
//
//  Created by 97 on 2019/8/28.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int N;
    double e;
    int D;
    cin >> N >> e >> D;
    int K;
    int knkongzhi = 0;
    int kongzhi = 0;
    double t;
    for (int i = 0; i < N; i++) {
        cin >> K;
        int count = 0;
        for (int j = 0; j < K; j++) {
            cin >> t;
            if (t < e) count++;
        }
//        printf("%d\n", count);
        if (count * 2 > K) {
            if (K > D) {
                kongzhi++;
            }
            else knkongzhi++;
        }
    }
    printf("%.1f%% %.1f%%", (double)knkongzhi / N * 100, (double)kongzhi / N * 100);
}
