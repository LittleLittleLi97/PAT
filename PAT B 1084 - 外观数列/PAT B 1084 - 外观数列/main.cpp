//
//  main.cpp
//  PAT B 1084 - 外观数列
//
//  Created by 97 on 2019/8/21.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

string a;

int main(){
    int d;
    int N;
    cin >> d >> N;
    a = to_string(d);
    for (int i = 1; i < N; i++) {
        string t;
        int count = 1;
        for (int j = 0; j < a.length(); j++) {
            if (a[j] == a[j + 1]) {
                count++;
            }else {
                t += a[j];
                string s = to_string(count);
                t += s;
                count = 1;
            }
        }
        a = t;
//        cout << a << endl;
    }
    cout << a;
}

/*
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

vector<int> a;

int main(){
    int d;
    int N;
    scanf("%d %d", &d, &N);
    a.push_back(d);
    for (int i = 1; i < N; i++) {
        vector<int> t;
        int count = 1;
        for (int j = 0; j < a.size(); j++) {
            if (a[j] == a[j + 1] && a[j] != 0) {
                count++;
            }else {
                string s = to_string(count);
                t.push_back(a[j]);
                for (int k = 0; k < s.length(); k++) {
                    t.push_back(s[k] - '0');
                }
                count = 1;
            }
        }
        a = t;
//        for (int i = 0; i < a.size(); i++) {
//            printf("%d", a[i]);
//        }
//        printf("\n");
    }
    for (int i = 0; i < a.size(); i++) {
        printf("%d", a[i]);
    }
}
*/
