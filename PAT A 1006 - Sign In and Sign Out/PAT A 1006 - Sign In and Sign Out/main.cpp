//
//  main.cpp
//  PAT A 1006 - Sign In and Sign Out
//
//  Created by 97 on 2019/10/13.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;

int N;

int change(int a, int b, int c){
    return a * 60 * 60 + b * 60 + c;
}

int main(){
    scanf("%d", &N);
    char first[20], second[20];
    int min_time = 24 * 60 * 60, max_time = 0;
    for (int i = 0; i < N; i++) {
        char id[20];
        int a, b, c;
        scanf("%s %d:%d:%d", id, &a, &b, &c);
        int out1 = change(a, b, c);
        if (out1 < min_time) {
            strcpy(first, id);
            min_time = out1;
        }
        scanf("%d:%d:%d", &a, &b, &c);
        int out2 = change(a, b, c);
        if (out2 > max_time) {
            strcpy(second, id);
            max_time = out2;
        }
    }
    printf("%s %s", first, second);
}
