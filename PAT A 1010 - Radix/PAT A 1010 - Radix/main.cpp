//
//  main.cpp
//  PAT A 1010 - Radix
//
//  Created by 97 on 2019/10/15.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <stack>
using namespace std;

string a, b;
int tag, radix;

string change_radix(int toRadix, int n){
    string out;
    stack<int> s;
    while (n) {
        int mod = n % toRadix;
        s.push(mod);
        n = n / toRadix;
    }
    while (!s.empty()) {
        if (s.top() < 10) {
            out += s.top() + '0';
        }else {
            out += s.top() - 10 + 'a';
        }
        s.pop();
    }
    return out;
}

int main(){
//    cout << change_radix(16, 15);
    cin >> a >> b >> tag >> radix;
    for (int i = 2; i <= 35; i++) {
        string out
    }
}
