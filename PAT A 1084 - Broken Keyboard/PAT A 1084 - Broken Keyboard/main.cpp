//
//  main.cpp
//  PAT A 1084 - Broken Keyboard
//
//  Created by 97 on 2019/10/29.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

bool a[200];

int main(){
    string first, second;
    cin >> first >> second;
    for (int i = 0; i < second.length(); i++) {
        if (second[i] >= 'A' && second[i] <= 'Z') a[second[i] - 'A' + 'a'] = true;
        else if (second[i] >= 'a' && second[i] <= 'z') a[second[i] - 'a' + 'A'] = true;
        a[second[i]] = true;
    }
    
    for (int i = 0; i < first.length(); i++) {
        if (a[first[i]] == false) {
            char t = first[i];
            a[t] = true;
            if (t >= 'A' && t <= 'Z') a[t - 'A' + 'a'] = true;
            else if (t >= 'a' && t <= 'z') {
                t = t - 'a' + 'A';
                a[t] = true;
            }
            printf("%c", t);
        }
    }
}
