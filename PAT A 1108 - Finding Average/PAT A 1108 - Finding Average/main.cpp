//
//  main.cpp
//  PAT A 1108 - Finding Average
//
//  Created by 97 on 2019/12/3.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

double total = 0;
int num = 0;
int N;

bool isLegal(string a){
    int dotCount = 0;
    int afterDotCount = 0;
    bool dotFlag = false;
    for (int i = 0; i < a.length(); i++) {
        if (dotFlag == true) {
            afterDotCount++;
            if (afterDotCount > 2) {
                return false;
            }
        }
        if (a[i] >= '0' && a[i] <= '9') {
            continue;
        }
        else if (a[i] == '.') {
            dotCount++;
            dotFlag = true;
            if (dotCount > 1) {
                return false;
            }
        }
        else if (a[i] == '-') continue;
        else return false;
    }
    return true;
}

int main(){
    cin >> N;
    for (int i = 0; i < N; i++) {
        string t; cin >> t;
        if (isLegal(t) == false) {
            printf("ERROR: %s is not a legal number\n", t.c_str());
        }else {
            double zhi = stod(t);
            if (zhi > 1000 || zhi < -1000) {
                printf("ERROR: %s is not a legal number\n", t.c_str());
            }else {
                total += zhi;
                num++;
            }
        }
    }
    if (num == 0) {
        printf("The average of 0 numbers is Undefined\n");
    }else if (num == 1) printf("The average of 1 number is %.2lf\n", total);
    else printf("The average of %d numbers is %.2lf", num, total / num);
}
