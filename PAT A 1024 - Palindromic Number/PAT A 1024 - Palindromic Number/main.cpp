//
//  main.cpp
//  PAT A 1024 - Palindromic Number
//
//  Created by 97 on 2019/11/15.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

long long N;
int K;
int a[10000000]; //右边存高位 左边存低位
int t[10000000];
int length = 0;

void Add(){
    for (int i = length, j = 0; i >= 0; i--, j++) {
        t[i] = a[j];
    }
    int cy = 0;
    for (int i = 0; i <= length; i++) {
        int zhi = a[i] + t[i] + cy;
        a[i] = zhi % 10;
        cy = zhi / 10;
    }
    if (cy) {
        length++;
        a[length] = cy;
    }
//    for (int i = length; i >= 0; i--) {
//        printf("%d", a[i]);
//    } printf("\n");
}

bool IsPalindrominc(){
    int left = 0;
    int right = length;
    while (left <= right) {
        if (a[left] != a[right]) return false;
        left++;
        right--;
    }
    return true;
}

void Change(){
    int index = 0;
    while (N) {
        a[index++] = N % 10;
        N /= 10;
    }
    length = index - 1;
}

int main(){
    scanf("%lld %d", &N, &K);
    Change();
//    printf("%d\n", length);
//    for (int i = length; i >= 0; i--) {
//        printf("%d", a[i]);
//    } printf("\n");
    int count = 0;
    while (!IsPalindrominc() && count < K) {
//        printf("%d - ", count);
        Add();
        count++;
    }
//    printf("OK");
    for (int i = length; i >= 0; i--) {
        printf("%d", a[i]);
    }
    printf("\n%d", count);
}
