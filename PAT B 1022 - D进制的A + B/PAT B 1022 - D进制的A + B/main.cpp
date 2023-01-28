//
//  main.cpp
//  PAT B 1022 - D进制的A + B
//
//  Created by 97 on 2019/7/24.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>
#include <stack>
using namespace std;

stack<int> s;

void conversion(long int a, int jz){
    int mod = 0;
    if (a == 0) {
        s.push(0);
        return;
    }
    while (a) {
        mod = a % jz;
        s.push(mod);
        a = a / jz;
    }
}

int main(){
    long int a, b;
    int c;
    scanf("%ld %ld %d", &a, &b, &c);
    a += b;
    conversion(a, c);
    while (!s.empty()) {
        printf("%d", s.top());
        s.pop();
    }
}
