//
//  main.cpp
//  PAT B 1071 - 小赌怡情
//
//  Created by 97 on 2019/8/24.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int T; int K;
    cin >> T >> K;
    int n1, n2, b, t;
    for (int i = 0; i < K; i++) {
        cin >> n1 >> b >>  t >> n2;
        if (t > T) {
            printf("Not enough tokens.  Total = %d.\n", T);
            continue;
        }
        if (b == 0) {
            if (n1 > n2) {
            T += t;
            printf("Win %d!  Total = %d.\n", t, T);
            }else {
            T -= t;
            printf("Lose %d.  Total = %d.\n", t, T);
                if (T == 0) {
                    printf("Game Over.");
                    return 0;
                }
            }
        }else if (b == 1) {
            if (n1 < n2) {
                T += t;
                printf("Win %d!  Total = %d.\n", t, T);
            }else {
                T -= t;
                printf("Lose %d.  Total = %d.\n", t, T);
                if (T == 0) {
                    printf("Game Over.");
                    return 0;
                }
            }
        }
    }
}
