//
//  main.cpp
//  PAT A 1027 - Colors in Mars
//
//  Created by 97 on 2019/11/18.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

char out[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};
int R, G, B;

void Change(int a){
    printf("%c", out[a / 13]);
    a %= 13;
    printf("%c", out[a]);
}

int main(){
    scanf("%d%d%d", &R, &G, &B);
    printf("#");
    Change(R);
    Change(G);
    Change(B);
}
