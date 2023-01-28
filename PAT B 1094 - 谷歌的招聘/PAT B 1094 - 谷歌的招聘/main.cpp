//
//  main.cpp
//  PAT B 1094 - 谷歌的招聘
//
//  Created by 97 on 2019/8/16.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

bool pd(int out){
    if (out == 0 || out == 1) return false;
    for (int i = 2; i * i <= out; i++) {
        if (out % i == 0) {
            return false;
        }
    }
    return true;
}

int main(){
    int len;
    int k;
    string a;
    cin >> len >> k >> a;
    for (int i = 0; i + k <= len; i++) {
        string t = a.substr(i, k);
        int out = stoi(t);
        if (pd(out)) {
            cout << t;
            return 0;
        }
    }
    cout << "404";
    return 0;
}

//#include <stdio.h>
//#include <math.h>
//
//int a[1010];
//
//bool pd(int out){
//    for (int i = 2; i < sqrt(out); i++) {
//        if (out % i == 0) {
//            return false;
//        }
//    }
//    return true;
//}
//
//int main(){
//    //    printf("%d", pd(19));
//    int len;
//    int k;
//    scanf("%d %d", &len, &k);
//    getchar();
//    for (int i = 0; i < len; i++) {
//        char n;
//        n = getchar();
//        a[i] = n - '0';
//    }
//    //    for (int i = 0; i < len; i++) {
//    //        printf("%d", a[i]);
//    //    }
//    //    printf("\n");
//    for (int i = 0; i + k <= len; i++) {
//        int out = 0;
//        for (int j = i; j < i + k; j++) {
//            out = out * 10 + a[j];
//        }
//        if (pd(out)) {
//            printf("%05d", out);
//            return 0;
//        }
//    }
//    printf("404");
//    return 0;
//}
