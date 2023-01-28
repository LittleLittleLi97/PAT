//
//  main.cpp
//  Second PAT A 1006 - Sign In and Sign Out
//
//  Created by 97 on 2021/9/23.
//  Copyright © 2021 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int M;

int main() {
    string InName = "";
    string OutName = "";
    int InTime = 24*60*60;
    int OutTime = 0;
    cin >> M;
    for (int i = 0; i < M; i++) {
        string tName;
        int HH, MM, SS;
        cin >> tName;
        scanf("%d:%d:%d", &HH, &MM, &SS);
        int tInTime = HH * 60 * 60 + MM * 60 + SS;
        if (tInTime < InTime) {
            InTime = tInTime;
            InName = tName;
        }
        scanf("%d:%d:%d", &HH, &MM, &SS);
        int tOutTime = HH * 60 * 60 + MM * 60 + SS;
        if (tOutTime > OutTime) {
            OutTime = tOutTime;
            OutName = tName;
        }
    }
    cout << InName << " " << OutName;
}
