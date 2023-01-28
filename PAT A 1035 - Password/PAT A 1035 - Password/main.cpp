//
//  main.cpp
//  PAT A 1035 - Password
//
//  Created by 97 on 2019/11/18.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;

struct Node {
    string a;
    string b;
};

vector<Node> v;
int N;

int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char a[20], b[20];
        scanf("%s %s", a, b);
        bool flag = false;
        for (int j = 0; j < strlen(b); j++) {
            if (b[j] == '1') {
                b[j] = '@';
                flag = true;
            }else if (b[j] == '0') {
                b[j] = '%';
                flag = true;
            }else if (b[j] == 'l') {
                b[j] = 'L';
                flag = true;
            }else if (b[j] == 'O') {
                b[j] = 'o';
                flag = true;
            }
        }
        if (flag == true) v.push_back({a, b});
    }
    if (v.size() == 0) {
        if (N == 1) printf("There is 1 account and no account is modified");
        else if (N > 1) printf("There are %d accounts and no account is modified", N);
    }else {
        printf("%ld\n", v.size());
        for (int i = 0; i < v.size(); i++) {
            printf("%s %s\n", v[i].a.c_str(), v[i].b.c_str());
        }
    }
}
