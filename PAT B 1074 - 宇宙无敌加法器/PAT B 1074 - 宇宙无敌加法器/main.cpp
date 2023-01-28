//
//  main.cpp
//  PAT B 1074 - 宇宙无敌加法器
//
//  Created by 97 on 2019/9/3.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main(){
    string N, a, b;
    cin >> N >> a >> b;
    reverse(N.begin(), N.end());
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if (a.length() < b.length()) swap(a, b);
    while (a.length() != b.length()) b += '0';
    int up = 0;
    for (int i = 0; i < a.length(); i++) {
        int t = a[i] + b[i] - '0' - '0' + up;
        if (N[i] == '0') {
            up = t / 10;
            t = t % 10;
        }else {
            up = t / (N[i] - '0');
            t = t % (N[i] - '0');
        }
        v.push_back(t);
    }
    v.push_back(up);
    bool flag = false;
    for (int i = v.size() - 1; i >= 0; i--) {
        if (flag == true || v[i] != 0) {
            cout << v[i];
            flag = true;
        }
    }
    if (flag == false) cout << 0;
}
