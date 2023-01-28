//
//  main.cpp
//  PAT B 1064 - 朋友数
//
//  Created by 97 on 2019/9/1.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool ever[100] = {false};
bool ever_v[100] = {false};

vector<int> v;

int main(){
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int t; cin >> t;
        string a = to_string(t);
        int r = 0;
        for (int j = 0; j < a.length(); j++) {
            r += a[j] - '0';
        }
        if (ever[r] == false) {
            v.push_back(r);
            ever[r] = true;
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
        if (i != 0) cout << " ";
        cout << v[i];
    }
}
