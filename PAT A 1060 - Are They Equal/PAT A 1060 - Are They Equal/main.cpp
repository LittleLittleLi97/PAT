//
//  main.cpp
//  PAT A 1060 - Are They Equal
//
//  Created by 97 on 2019/11/16.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int N;

string Deal(string a, int &e){
    while (a.length() > 0 && a[0] == '0') {
        a.erase(a.begin());
    }
    if (a[0] == '.') {
        a.erase(a.begin());
        while (a.length() > 0 && a[0] == '0') {
            a.erase(a.begin());
            e--;
        }
    }else {
        while (e < a.length() && a[e] != '.') {
            e++;
        }
        if (e < a.length()) a.erase(a.begin() + e);
    }
    if (a.length() == 0) e = 0;
    string t;
    int i = 0;
    while (i < N) {
        if (i < a.length()) t += a[i];
        else t += "0";
        i++;
    }
    return t;
}

int main(){
    string a, b;
    cin >> N >> a >> b;
    int ea = 0;
    int eb = 0;
    string DealA = Deal(a, ea);
    string DealB = Deal(b, eb);
    if (ea == eb && DealA == DealB) {
        cout << "YES 0." << DealA << "*10^" << ea;
    }else {
        cout << "NO 0." << DealA << "*10^" << ea;
        cout << " 0." << DealB << "*10^" << eb;
    }
}
