//
//  main.cpp
//  PAT B 1009 - 说反话
//
//  Created by 97 on 2019/7/21.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(){
    char a[100][100];
    int i = 0;
    while (scanf("%s", a[i]) != EOF) {
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%s", a[j]);
        if (j != 0) {
            printf(" ");
        }
    }
//    char a[100][100];
//    int i = 0;
//    char n;
//    scanf("%s", a[i++]);
//    n = getchar();
//    while (n == ' ') {
//        scanf("%s", a[i++]);
//        n = getchar();
//    }
//    for (int j = i - 1; j >= 0; j--) {
//        printf("%s", a[j]);
//        if (j != 0) {
//            printf(" ");
//        }
//    }
}
