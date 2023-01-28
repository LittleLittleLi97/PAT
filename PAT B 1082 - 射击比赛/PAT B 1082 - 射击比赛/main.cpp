//
//  main.cpp
//  PAT B 1082 - 射击比赛
//
//  Created by 97 on 2019/8/20.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int firstGrade = 100000;
    int first = 0;
    int lastGrade = 0;
    int last = 0;
    for (int i = 0; i < N; i++) {
        int t;
        int a, b;
        cin >> t >> a >> b;
        int g = a * a + b * b;
        if (g < firstGrade) {
            firstGrade = g;
            first = t;
        }
        if (g > lastGrade) {
            lastGrade = g;
            last = t;
        }
    }
    printf("%04d %04d", first, last);
}
