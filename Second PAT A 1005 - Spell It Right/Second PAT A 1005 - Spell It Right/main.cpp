//
//  main.cpp
//  Second PAT A 1005 - Spell It Right
//
//  Created by 97 on 2021/9/20.
//  Copyright © 2021 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

string str[11] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main() {
    int sum = 0;
    char a;
    scanf("%c", &a);
    while (a != '\n') {
        sum += a - '0';
        scanf("%c", &a);
    }
    if (sum == 0) {
        printf("%s", str[0].c_str());
        return 0;
    }
    vector<int> v;
    int mod = 10;
    while (sum != 0) {
        v.push_back(sum % mod);
        sum /= 10;
    }
    bool flag = false;
    for (long int i = v.size() - 1; i >= 0; i--) {
        if (flag == true) printf(" ");
        flag = true;
        printf("%s", str[v[i]].c_str());
    }
}
