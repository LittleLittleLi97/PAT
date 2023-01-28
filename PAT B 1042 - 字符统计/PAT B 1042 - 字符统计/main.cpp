//
//  main.cpp
//  PAT B 1042 - 字符统计
//
//  Created by 97 on 2019/8/9.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int a[30] = {0};

int main(){
    char n;
    n = getchar();
    while (n != '\n') {
        if (n >= 'a' && n <= 'z') {
            a[n - 'a'] += 1;
        }else if (n >= 'A' && n <= 'Z'){
            a[n - 'A'] += 1;
        }
        n = getchar();
    }
    int k = 0;
    for(int i = 0; i < 26; i++) {
        if (a[i] > a[k]) {
            k = i;
        }
    }
    printf("%c %d", k + 'a', a[k]);
}
