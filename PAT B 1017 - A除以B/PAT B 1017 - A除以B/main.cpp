//
//  main.cpp
//  PAT B 1017 - A除以B
//
//  Created by 97 on 2019/7/23.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>
#include <string.h>

char a[1010];
int b;
int out[1010];

int main(){
    scanf("%s %d", a, &b);
    int last = a[0] - '0';
    int count = 0;
    for (int i = 1; i < strlen(a); i++) {
        last = last * 10 + (a[i] - '0');
        out[count++] = (last - (last % b)) / b;
        last = last % b;
    }
    if (strlen(a) == 1) {
        out[count++] = (last - (last % b)) / b;
        last = last % b;
    }
    for (int i  = 0; i < count; i++) {
        printf("%d", out[i]);
    }
    printf(" %d", last);
}
