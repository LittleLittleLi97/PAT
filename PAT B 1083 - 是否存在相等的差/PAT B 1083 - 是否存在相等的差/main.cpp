//
//  main.cpp
//  PAT B 1083 - 是否存在相等的差
//
//  Created by 97 on 2019/8/20.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int a[10000] = {0};

int main(){
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int t;
        cin >> t;
        t = abs(t - i);
        a[t]++;
    }
    for (int i = N + 1; i >= 0; i--) {
        if (a[i] > 1) {
            cout << i << " " << a[i] << endl;
        }
    }
}
