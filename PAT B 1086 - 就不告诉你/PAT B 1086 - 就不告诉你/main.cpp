//
//  main.cpp
//  PAT B 1086 - 就不告诉你
//
//  Created by 97 on 2019/8/19.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    int a;
    int b;
    cin >> a >> b;
    int c = a * b;
    bool flag = false;
    while (c != 0) {
        if (flag == false && c % 10 == 0) {
            c /= 10;
            continue;
        }
        cout << c % 10;
        c /= 10;
        flag = true;
    }
}
