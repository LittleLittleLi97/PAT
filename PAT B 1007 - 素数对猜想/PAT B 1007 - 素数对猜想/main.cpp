//
//  main.cpp
//  PAT B 1007 - 素数对猜想
//
//  Created by 97 on 2019/7/20.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int pd(int a){
    int q = sqrt(a);
    for (int i = 2; i <= q; i++)
        if (a % i == 0) return false;
    return true;
}

int main(){
//    1 2 3 5 7 11 13 17 19
    int n;
    scanf("%d", &n);
    int last = 2;
    int result = 0;
    for (int i = 2; i <= n; i++) {
        if (pd(i)) {
            if (i - last == 2) {
                result++;
            }
            last = i;
        }
    }
    printf("%d", result);
}
