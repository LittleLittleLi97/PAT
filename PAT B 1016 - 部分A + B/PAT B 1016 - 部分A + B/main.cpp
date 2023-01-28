//
//  main.cpp
//  PAT B 1016 - 部分A + B
//
//  Created by 97 on 2019/7/23.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(){
    char A[20];
    char DA;
    char B[20];
    char DB;
    scanf("%s %c %s %c", A, &DA, B, &DB);
    int intda = DA - '0';
    int intdb = DB - '0';
    int counta = 0;
    int countb = 0;
    for (int i = 0; i < strlen(A); i++) {
        if (A[i] == DA) {
            counta = counta * 10 + intda;
        }
    }
//    printf("%d\n", intda);
    for (int i = 0; i < strlen(B); i++) {
        if (B[i] == DB) {
            countb = countb * 10 + intdb;
        }
    }
//    printf("%d\n", countb);
    printf("%d", counta + countb);
}
