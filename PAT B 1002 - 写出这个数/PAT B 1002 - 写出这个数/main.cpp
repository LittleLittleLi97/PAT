//
//  main.cpp
//  PAT B 1002 - 写出这个数
//
//  Created by 97 on 2019/7/19.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;

char zm[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main(){
    char n;
    int total = 0;
    n = getchar();
    while (n != '\n') {
        total += n - '0';
        n = getchar();
    }
    char a[1000];
    sprintf(a, "%d", total);
    for (int i = 0; i < strlen(a); i++) {
        if (i != strlen(a) - 1) {
            printf("%s ", zm[a[i] - '0']);
        }else{
            printf("%s", zm[a[i] - '0']);
        }
    }
}
