
//
//  main.cpp
//  PAT B 1054 - 求平均值
//
//  Created by 97 on 2019/8/28.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
using namespace std;

int main(){
    int N;
    cin >> N;
    int count = 0;
    string a;
    getchar();
    getline(cin, a);
    string t;
    a += " ";
    double total = 0;
    bool flag = true;
    int dot = 0;
    for (int i = 0; i < a.length(); i++) {
        if(a[i] != ' ') {
            t += a[i];
            if (!(a[i] >= '0' && a[i] <= '9') && a[i] != '.' && a[i] != '-') flag = false;
            if (a[i] == '.') {
                if (dot != 0) flag = false;
                else dot = t.length();
            }
        }else {
            if (flag == true) {
                double m = stod(t);
                if (m >= -1000 && m <= 1000){
                    if (dot && t.length() - dot > 2) printf("ERROR: %s is not a legal number\n", t.c_str());
                    else {
                        total += m; count++;
                    }
                }
                else printf("ERROR: %s is not a legal number\n", t.c_str());
            }
            else printf("ERROR: %s is not a legal number\n", t.c_str());
            t = "";
            flag = true;
            dot = 0;
        }
    }
    if (count > 0) printf("The average of %d numbers is %.2f", count, total / count);
    else printf("The average of 0 numbers is Undefined");
}
