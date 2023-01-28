//
//  main.cpp
//  PAT B 1057 - 数零壹
//
//  Created by 97 on 2019/8/29.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int N = 0;
int x = 0; //0
int y = 0; //1

int main(){
    string a;
    getline(cin, a);
    for (int i = 0; i < a.length(); i++) {
        if (a[i] >= 'a' && a[i] <= 'z') N += a[i] - 'a' + 1;
        if (a[i] >= 'A' && a[i] <= 'Z') N += a[i] - 'A' + 1;
    }
    while (N) {
        int mod = N % 2;
        if (mod == 0) x++;
        else y++;
        N /= 2;
    }
    cout << x << " " << y;
}
