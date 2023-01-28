//
//  main.cpp
//  PAT A 1038 - Recover the Smallest Number
//
//  Created by 97 on 2019/11/4.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v;
int N;

bool cmp(string a, string b){
    return a + b < b + a;
}

int main(){
    cin >> N;
    for (int i = 0; i < N; i++) {
        string t; cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end(), cmp);
    bool flag = false;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].length(); j++) {
            if (flag == false && v[i][j] == '0') {
                continue;
            }else {
                flag = true;
                printf("%c", v[i][j]);
            }
        }
    }
    if (flag == false) printf("0");
}
