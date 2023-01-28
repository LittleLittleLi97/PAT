//
//  main.cpp
//  PAT A 1050 - String Subtraction
//
//  Created by 97 on 2019/11/20.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
using namespace std;

map<char, bool> m;

int main(){
    string a, b;
    getline(cin, a);
    getline(cin, b);
    for (int i = 0; i < b.length(); i++) {
        m[b[i]] = true;
    }
    string out = "";
    for (int i = 0; i < a.length(); i++) {
        if (m[a[i]] == false) {
            out += a[i];
        }
    }
    cout << out;
}
