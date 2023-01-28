//
//  main.cpp
//  PAT A 1023 - Have Fun With Numbers
//
//  Created by 97 on 2019/11/11.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

int N = 0;
int a[22];
int b[22];
int CalCount[10];
int bCalCount[10];

bool duibi(){
    for (int i = 0; i < 10; i++) {
        if (CalCount[i] != bCalCount[i]) return false;
    }
    return true;
}

int main(){
    char t;
    t = getchar();
    while (t != '\n') {
        a[N] = t - '0';
        CalCount[t - '0']++;
        N++;
        t = getchar();
    }
//    for (int i = 0; i < N; i++) {
//        printf("%d", a[i]);
//    }
    int cy = 0;
    for (int i = N - 1; i >= 0; i--) {
        int t = 2 * a[i] + cy;
        cy = t / 10;
        t = t % 10;
        b[i] = t;
        bCalCount[t]++;
    }
    if (duibi() && cy == 0) {
        printf("Yes\n");
        for (int i = 0; i < N; i++) {
            printf("%d", b[i]);
        }
    }
    else {
        printf("No\n");
        if (cy != 0) printf("%d", cy);
        for (int i = 0; i < N; i++) {
            printf("%d", b[i]);
        }
        return 0;
    }
}
