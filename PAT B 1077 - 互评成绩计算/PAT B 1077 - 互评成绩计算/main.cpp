//
//  main.cpp
//  PAT B 1077 - 互评成绩计算
//
//  Created by 97 on 2019/8/22.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        double teacher;
        vector<int> v;
        int t;
        cin >> teacher;
        for (int j = 0; j < N - 1; j++) {
            cin >> t;
            if (t >= 0 && t <= M) v.push_back(t);
        }
        sort(v.begin(), v.end());
        double sum = 0;
        for (int j = 1; j < v.size() - 1; j++) sum += v[j];
//        cout << sum << endl;
        int out = round((sum / (v.size() - 2) + teacher) / 2);
        cout << out << endl;
    }
}
