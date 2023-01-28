//
//  main.cpp
//  Second PAT A 1001 - A+B Format
//
//  Created by 97 on 2021/9/18.
//  Copyright © 2021 97. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    int a, b;
    cin >> a >> b;
    int c = a + b;
    string s = to_string(abs(c));
    if (c < 0) {
        cout << '-';
    }
    for (int i = 0; i < s.length(); i++) {
        cout << s[i];
        if (i != s.length() - 1 && (s.length() - i - 1) % 3 == 0) {
            cout << ',';
        }
    }
}
