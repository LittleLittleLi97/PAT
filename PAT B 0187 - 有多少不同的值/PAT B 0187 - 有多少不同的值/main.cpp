//
//  main.cpp
//  PAT B 0187 - 有多少不同的值
//
//  Created by 97 on 2019/8/20.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
using namespace std;

bool flag[10000] = {false};

int main(){
    int n;
    cin >> n;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        int t = i / 2 + i / 3 + i / 5;
        if (flag[t] == false) {
            count++;
            flag[t] = true;
        }
    }
    cout << count;
}
