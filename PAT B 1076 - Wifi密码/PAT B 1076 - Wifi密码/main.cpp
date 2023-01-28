//
//  main.cpp
//  PAT B 1076 - Wifi密码
//
//  Created by 97 on 2019/8/22.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> v;

void push(char a){
    if (a == 'A') v.push_back(1);
    else if (a == 'B') v.push_back(2);
    else if (a == 'C') v.push_back(3);
    else if (a == 'D') v.push_back(4);
}

int main(){
    int N;
    cin >> N;
    getchar();
    for (int i = 0; i < N; i++) {
        string t;
        getline(cin, t);
//        cout << t << endl;
        if (t[2] == 'T') push(t[0]);
        else if (t[6] == 'T') push(t[4]);
        else if (t[10] == 'T') push(t[8]);
        else if (t[14] == 'T') push(t[12]);
    }
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
    }
}
