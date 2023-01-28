//
//  main.cpp
//  PAT A 1005 - Spell It Right
//
//  Created by 97 on 2019/10/8.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

string m[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main(){
    char n;
    n = getchar();
    long int out = 0;
    while (n != '\n') {
        out += n - '0';
        n = getchar();
    }
    string a = to_string(out);
    for (int i = 0; i < a.length(); i++) {
        printf("%s", m[a[i] - '0'].c_str());
        if (i != a.length() - 1) printf(" ");
    }
}
