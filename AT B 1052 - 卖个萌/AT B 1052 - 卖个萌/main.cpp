//
//  main.cpp
//  AT B 1052 - 卖个萌
//
//  Created by 97 on 2019/8/27.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

vector<string> vhand;
vector<string> veye;
vector<string> vmouse;

int main(){
    string n;
    getline(cin, n);
    for (int i = 0; i < n.length(); i++) {
        if (n[i] == '['){
            string t;
            for (int j = i + 1; n[j] != ']'; j++) {
                t += n[j];
            }
            vhand.push_back(t);
        }
    }
//    for (int i = 0; i < vhand.size(); i++) {
//        cout << vhand[i] << " ";
//    }
    getline(cin, n);
    for (int i = 0; i < n.length(); i++) {
        if (n[i] == '['){
            string t;
            for (int j = i + 1; n[j] != ']'; j++) {
                t += n[j];
            }
            veye.push_back(t);
        }
    }
    getline(cin, n);
    for (int i = 0; i < n.length(); i++) {
        if (n[i] == '['){
            string t;
            for (int j = i + 1; n[j] != ']'; j++) {
                t += n[j];
            }
            vmouse.push_back(t);
        }
    }
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string t;
        int which;
        bool flag = false;
        for (int j = 0; j < 5; j++) {
            cin >> which;
            if (j == 0 || j == 4) {
                if (j == 4) t += ')';
                if (which - 1< vhand.size()) t += vhand[which - 1];
                else flag = true;
            }
            if (j == 1 || j == 3) {
                if (j == 1) t += '(';
                if (which - 1< veye.size()) t+= veye[which - 1];
                else flag = true;
            }
            if (j == 2) {
                if (which - 1 < vmouse.size()) t+= vmouse[which - 1];
                else flag = true;
            }
        }
        if (flag == true) printf("Are you kidding me? @\\/@\n");
        else printf("%s\n", t.c_str());
    }
}
