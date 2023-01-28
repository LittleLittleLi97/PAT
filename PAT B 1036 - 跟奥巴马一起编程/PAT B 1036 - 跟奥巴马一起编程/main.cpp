//
//  main.cpp
//  PAT B 1036 - 跟奥巴马一起编程
//
//  Created by 97 on 2019/8/5.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>

int main(){
    int N;
    char a;
    scanf("%d %c", &N, &a);
    for (int i = 0; i < N; i++) {
        printf("%c",a);
    }
    printf("\n");
    int hang;
    if (N % 2 == 0) {
        hang = N / 2 - 2;
    }else hang = N / 2 - 2 + 1;
    for (int i = 0; i < hang; i++) {
        printf("%c", a);
        for (int j = 0; j < N - 2; j++) {
            printf(" ");
        }
        printf("%c\n", a);
    }
    for (int i = 0; i < N; i++) {
        printf("%c", a);
    }
}
