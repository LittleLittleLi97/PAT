//
//  main.cpp
//  PAT A 1096 - Consecutive Factors
//
//  Created by 97 on 2019/11/14.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
int st = 0;
int Consecutive = 0;

int main(){
    scanf("%d", &N);
    for (int i = 2; i <= N; i++) {
        int tn = N;
        int j = i;
        int length = 0;
        int tst = i;
        while (j <= N && tn % j == 0) {
            tn /= j;
            length++;
            j++;
        }
        if (length > Consecutive) {
            Consecutive = length;
            st = tst;
        }
    }
    printf("%d\n", Consecutive);
    for (int i = 0; i < Consecutive; i++) {
        printf("%d", i + st);
        if (i != Consecutive - 1) printf("*");
    }
}
