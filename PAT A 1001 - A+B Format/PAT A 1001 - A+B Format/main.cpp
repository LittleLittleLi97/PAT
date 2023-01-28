//
//  main.cpp
//  PAT A 1001 - A+B Format
//
//  Created by 97 on 2019/9/16.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main(){
    long a, b;
    cin >> a >> b;
    string t = to_string(a + b);
    if (t[0] == '-') {
        printf("-");
        int length = t.length() - 1;
        for (int i = 1; i < t.length(); i++) {
            printf("%c", t[i]);
            if ((length - i) % 3 == 0 && length - i >= 3) {
                printf(",");
            }
        }
    }else {
        int length = t.length();
        for (int i = 0; i < t.length(); i++) {
            printf("%c", t[i]);
            if ((length - i - 1) % 3 == 0 && length - i - 1 >= 3) {
                printf(",");
            }
        }
    }
}
