//
//  main.cpp
//  PAT A 1019 - General Palindromic Number
//
//  Created by 97 on 2019/10/21.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

vector<int> v;

void change(int n, int radix){
    int mod = 0;
    while (n != 0) {
        mod = n % radix;
        n = n / radix;
        v.push_back(mod);   // 反着的
    }
}

bool pd(){
    int left = 0;
    int right = v.size() - 1;
    for (; left <= right; left++, right--) {
        if (v[left] != v[right]) return false;
    }
    return true;
}

int main(){
    int a, b;
    cin >> a >> b;
    change(a, b);
//    for (int i = 0; i < v.size(); i++) {
//        cout << v[i];
//    }
//    cout << endl;
    bool flag = pd();
    if (flag == true) printf("Yes\n");
    else printf("No\n");
    for (int i = v.size() - 1; i >= 0; i--) {
        printf("%d", v[i]);
        if (i != 0) printf(" ");
    }
}
