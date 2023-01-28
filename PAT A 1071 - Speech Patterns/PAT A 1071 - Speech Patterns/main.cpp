//
//  main.cpp
//  PAT A 1071 - Speech Patterns
//
//  Created by 97 on 2019/11/16.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> m;
string a;

int main(){
    getline(cin, a);
    string word;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] >= '0' && a[i] <= '9') {
            word += a[i];
        }else if (a[i] >= 'a' && a[i] <= 'z') {
            word += a[i];
        }else if (a[i] >= 'A' && a[i] <= 'Z') {
            a[i] = a[i] - 'A' + 'a';
            word += a[i];
        }else {
            if (word != "") m[word]++;
            word = "";
        }
    }
    if (word != "") m[word]++;
    string out;
    int count = 0;
    for (auto it : m) {
        if (it.second > count) {
            out = it.first;
            count = it.second;
        }
    }
//    cout << m.size() << endl;
//    cout << m["can"] << endl;
    cout << out << " " << count;
}
