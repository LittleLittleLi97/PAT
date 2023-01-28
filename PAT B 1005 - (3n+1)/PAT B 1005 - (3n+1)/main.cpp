//
//  main.cpp
//  PAT B 1005 - (3n+1)
//
//  Created by 97 on 2019/7/19.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

bool covered[300] = {false};
int num[300];

bool cmp(int a, int b){
    return a > b;
}

void cover(int a){
    while (a != 1) {
        if (a % 2 == 0) {
            a = a / 2;
        }else{
            a = (3 * a + 1) / 2;
        }
        if (a <= 100) {             //不加这个数组越界
            covered[a] = true;
        }
    }
}

int main(){
    covered[1] = true;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
        cover(num[i]);
    }
    int result[300];
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (covered[num[i]] == false) {
            result[k] = num[i];
            k++;
        }
    }
    sort(result, result + k, cmp);
    for (int i = 0; i < k; i++) {
        if (i == k - 1) {
            printf("%d", result[i]);
            break;
        }
        printf("%d ", result[i]);
    }
}
