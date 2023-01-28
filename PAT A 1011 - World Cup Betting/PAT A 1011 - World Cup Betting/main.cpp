//
//  main.cpp
//  PAT A 1011 - World Cup Betting
//
//  Created by 97 on 2019/10/15.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

double a[3][3];
int out[3];
double yuan = 1;

int main(){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
            if (a[i][j] > a[i][out[i]]) out[i] = j;
        }
        yuan *= a[i][out[i]];
    }
    for (int i = 0; i < 3; i++) {
        if (out[i] == 0) printf("W");
        if (out[i] == 1) printf("T");
        if (out[i] == 2) printf("L");
        printf(" ");
    }
    printf("%.2lf", (yuan * 0.65 - 1) * 2);
}
