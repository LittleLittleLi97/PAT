//
//  main.cpp
//  PAT A 1112 - Stucked Keyboard
//
//  Created by 97 on 2019/12/4.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

bool Flag[200];
int appear[200];
bool tianjia[200];
int K;
string Init;
string Stucked;
char last = '\n';

int main(){
    scanf("%d", &K);
    getchar();
    int count = 0;
    char n = getchar();
    while (n != '\n') {
        Init += n;
        if (n != last) {
            if (appear[last] % K != 0) {
                Flag[last] = true;
                appear[last] = 0;
            }
        }
        last = n;
        appear[n]++;
        n = getchar();
    }
    count = 0;
    for (int i = 0; i < Init.length(); i++) {
        if (Flag[Init[i]] == false && tianjia[Init[i]] == false) {
            Stucked += Init[i];
            tianjia[Init[i]] = true;
        }
    }
    printf("%s\n", Stucked.c_str());
    for (int i = 0; i < Init.length(); i++) {
        char t = Init[i];
        if (Flag[t] == false) {
            if (count == 0) printf("%c", t);
            count++;
            if (count == K) count = 0;
        }else {
            count = 0;
            printf("%c", t);
        }
    }
}
