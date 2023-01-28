//
//  main.cpp
//  PAT B 1011 - A+B和C
//
//  Created by 97 on 2019/7/21.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>

struct Node {
    long int a;
    long int b;
    long int c;
}num[20];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%ld%ld%ld", &num[i].a, &num[i].b, &num[i].c);
    }
    for (int i = 0; i < n; i++) {
        if (num[i].a + num[i].b > num[i].c) {
            printf("Case #%d: true", i + 1);
        }else{
            printf("Case #%d: false", i + 1);
        }
        if (i != n) {
            printf("\n");
        }
    }
}
