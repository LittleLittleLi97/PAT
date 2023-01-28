//
//  main.cpp
//  PAT B 1079 - 延迟的回文数
//
//  Created by 97 on 2019/8/23.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

string re(string a){
    string t;
    for (long long i = a.length() - 1; i >= 0; i--) {
        t += a[i];
    }
    return t;
}

int main(){
    long long a;
    cin >> a;
    if (a == 0) {
        printf("0 is a palindromic number.");
        return 0;
    }
    string t = to_string(a);
    string r = re(t);
    long long rint = stoi(r);
    if (t == r) {
        printf("%lld is a palindromic number.", a);
        return 0;
    }
    for (int i = 0; i < 10; i++) {
        a = a + rint;
        printf("%s + %s = %lld\n", t.c_str(), r.c_str(), a);
        t = to_string(a);
        r = re(t);
        rint = stoi(r);
        if (t == r) {
            printf("%lld is a palindromic number.", a);
            return 0;
        }
    }
    printf("Not found in 10 iterations.");
}
