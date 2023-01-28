//
//  main.cpp
//  PAT B 1078 - 字符串压缩与解压
//
//  Created by 97 on 2019/8/22.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string out;

int main(){
    char a;
    a = getchar();
    getchar();
    string t;
    getline(cin, t);
    if (a == 'C') {
        int count = 1;
        for (int i = 0; i < t.length(); i++) {
            if (t[i] == t[i + 1]) count++;
            else if (count > 1) {
                out += to_string(count);
                out += t[i];
                count = 1;
            }else out += t[i];
        }
    }else if (a == 'D') {
        int count = 0;
        for (int i = 0; i < t.length(); i++) {
            if (t[i] >= '0' && t[i] <= '9') count = count * 10 + (t[i] - '0');
            else if (count > 0){
                for (int j = 0; j < count; j++) out += t[i];
                count = 0;
            }else {
                out += t[i];
                count = 0;
            }
        }
    }
    cout << out;
}
