//
//  main.cpp
//  Second PAT A 1010 - Radix
//
//  Created by 97 on 2021/9/30.
//  Copyright © 2021 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

long int N1;
long int N2;
int tag;
int radix;

string changeRadix(long int num, int edRadix) {
    string out = "";
    while (num != 0) {
        out += (num % edRadix) + '0';
        num /= edRadix;
    }
    return out;
}

int main() {
    scanf("%ld%ld%d%d", &N1, &N2, &tag, &radix);
    if (tag == 2) swap(N1, N2);
    string N1Str = changeRadix(N1, radix);
    for (int i = 2; i <=35; i++) {
        <#statements#>
    }
    
}
