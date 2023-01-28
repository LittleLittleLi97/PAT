//
//  main.cpp
//  PAT B 1092 - 最好吃的月饼
//
//  Created by 97 on 2019/8/16.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>
using namespace std;

int a[1010] = {0};

int main(){
    int kind;
    int city;
    scanf("%d %d", &kind, &city);
    for (int i = 0; i < city; i++) {
        for (int j = 1; j <= kind; j++) {
            int t;
            scanf("%d", &t);
            a[j] += t;
        }
    }
    int k = 1;
    for (int i = 1; i <= kind; i++) {
        if (a[i] > a[k]) {
            k = i;
        }
    }
    printf("%d\n",a[k]);
    for (int i = 1; i <= kind; i++) {
        if (a[k] == a[i]) {
            if (k != i) {
                printf(" ");
            }
            printf("%d", i);
        }
    }
}
