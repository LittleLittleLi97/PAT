//
//  main.cpp
//  PAT B 1070 - 结绳
//
//  Created by 97 on 2019/9/2.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<double> v;

int main(){
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        double t; cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    double out = v[0];
    for (int i = 1; i < v.size(); i++) {
        out = out / 2 + v[i] / 2;
    }
    printf("%d", (int)out);
}
