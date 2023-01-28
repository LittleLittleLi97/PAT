//
//  main.cpp
//  PAT B 1081 - 检查密码
//
//  Created by 97 on 2019/8/20.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

void pd(string a){
    if (a.length() < 6) {
        cout << "Your password is tai duan le.\n";
        return;
    }
    bool notonlyzm = false; bool notonlysz = false;
    for (int i = 0; i < a.length(); i++) {
        if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= '0' && a[i] <= '9') || a[i] == '.') {
            if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z')) {
                notonlysz = true;
            }else if (a[i] >= '0' && a[i] <= '9') notonlyzm = true;
            continue;
        }else {cout << "Your password is tai luan le.\n"; return;}
    }
    if (notonlysz == false) {
        cout << "Your password needs zi mu.\n";
        return;
    }
    if (notonlyzm == false) {
        cout << "Your password needs shu zi.\n";
        return;
    }
    cout << "Your password is wan mei.\n";
}

int main(){
    int N;
    cin >> N;
    getchar();
    for (int i = 0; i < N; i++) {
        string t;
        getline(cin, t);
        pd(t);
    }
}
