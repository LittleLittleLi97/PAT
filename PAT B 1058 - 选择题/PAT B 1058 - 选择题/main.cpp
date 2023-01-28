//
//  main.cpp
//  PAT B 1058 - 选择题
//
//  Created by 97 on 2019/8/29.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;

struct Node {
    int Grade;
    int TotalMany;
    int CorrectMany;
    char Option[10];
};

vector<Node> v;

int cuoti[110];
int maxcuoti = 0;

bool pd(char a, int ti){
    for (int i = 0; i < v[ti].CorrectMany; i++) {
        if (a == v[ti].Option[i]) return true;
    }
    return false;
}

int main(){
    int student;
    int problem;
    cin >> student >> problem;
    for (int i = 0; i < problem; i++) {
        Node t;
        cin >> t.Grade >> t.TotalMany >> t.CorrectMany;
        for (int j = 0; j < t.CorrectMany; j++) cin >> t.Option[j];
        v.push_back(t);
    }
    getchar();
    string a;
    for (int i = 0; i < student; i++) {
//        printf("学生%d\n", i);
        getline(cin, a);
        int ti = -1;
        int fenshu = 0;
        for (int j = 0; j < a.length(); j++) {
            if (a[j] >= '0' && a[j] <= '9') {
                ti++;
//                printf("第%d题\n", ti);
                int count = 0;
                bool flag = true;
                for (; a[j] != ')'; j++) {
                    if (a[j] >= 'a' && a[j] <= 'z') {
                        if(pd(a[j], ti)) count++;
                        else flag = false;
                    }
                }
//                printf("count %d\n", count);
                if (count == v[ti].CorrectMany && flag == true) fenshu += v[ti].Grade;
//                printf("fenshu %d\n", fenshu);
                else {
                    cuoti[ti]++;
                    if (cuoti[ti] > maxcuoti) maxcuoti = cuoti[ti];
                }
            }
        }
        printf("%d\n", fenshu);
    }
//    for (int i = 0; i < problem; i++) {
//        printf( " - %d -", cuoti[i]);
//    }
    if (!maxcuoti) printf("Too simple");
    else {
        printf("%d", maxcuoti);
        for (int i = 0; i < problem; i++) {
            if (cuoti[i] == maxcuoti) printf(" %d", i + 1);
        }
    }
}
