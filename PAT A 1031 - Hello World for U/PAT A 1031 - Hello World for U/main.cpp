//
//  main.cpp
//  PAT A 1031 - Hello World for U
//
//  Created by 97 on 2019/10/21.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(){
    string a; cin >> a;
    int n1 = 1;
    int n2 = a.length();
    string left, right;
    int st = 0;
    int ed = a.length() - 1;
    while (n1 + 1 <= n2 - 2) {
        n1 += 1;
        n2 -= 2;
        left += a[st++];
        right += a[ed--];
    }
    int space = a.length() - n1 * 2;
    for (int i = 0; i < left.length(); i++) {
        cout << left[i];
        for (int j = 0; j < space; j++) {
            cout << " ";
        }
        cout << right[i];
        cout << endl;
    }
    for (int i = st; i <= ed; i++) {
        cout << a[i];
    }
}
