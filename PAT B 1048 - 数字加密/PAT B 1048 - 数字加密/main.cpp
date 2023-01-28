//
//  main.cpp
//  PAT B 1048 - 数字加密
//
//  Created by 97 on 2019/8/13.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

string a;
string b;

stack<char> s;

void push(int out){
    if (out < 10) {char t = out + '0'; s.push(t);}
    else if (out == 10) s.push('J');
    else if (out == 11) s.push('Q');
    else if (out == 12) s.push('K');
}

int main(){
    cin >> a >> b;
    int min = a.length() >= b.length() ? a.length() : b.length();
    int count = 1;
    int amoment;
    int bmoment;
    for (int i = min - 1; i >= 0; i--, count++) {
        if (count > a.length()) amoment = 0;
        else amoment = a[a.length() - count] - '0';
        if (count > b.length()) bmoment = 0;
        else bmoment = b[b.length() - count] - '0';
        if (count % 2 == 1) {
            int out = (amoment + bmoment) % 13;
            push(out);
        }else {
            int out = bmoment - amoment;
            if (out < 0) out += 10;
            push(out);
        }
    }
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
}
