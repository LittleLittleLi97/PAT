//
//  main.cpp
//  PAT B 1056 - 组合数的和
//
//  Created by 97 on 2019/8/29.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main(){
    int N;
    cin >> N;
    int t;
    for (int i = 0; i < N; i++) {
        cin >> t;
        v.push_back(t);
    }
    int out = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j) out += v[i] * 10 + v[j];
        }
    }
    cout << out;
}
