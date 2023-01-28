//
//  main.cpp
//  PAT B 1067 - 试密码
//
//  Created by 97 on 2019/9/2.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    string s; int N;
    cin >> s >> N;
    getchar();
    for (int i = 1; i <= N; i++) {
        string t;
        getline(cin, t);
        if (t.length() == 1 && t[0] == '#') {
            return 0;
        }
        if (s == t) {
            printf("Welcome in\n");
            return 0;
        }else if (i < N){
            printf("Wrong password: %s\n", t.c_str());
        }else {
            printf("Wrong password: %s\n", t.c_str());
            printf("Account locked\n");
            return 0;
        }
    }
}
