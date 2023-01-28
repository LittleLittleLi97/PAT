//
//  main.cpp
//  PAT A 1008 - Elevator
//
//  Created by 97 on 2019/10/14.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int now = 0;
    int out = 0;
    for (int i = 0; i < N; i++) {
        int t; cin >> t;
        if (t > now) {
            out += (t - now) * 6 + 5;
        }else if (t < now) {
            out += (now - t) * 4 + 5;
        }else out += 5;
        now = t;
    }
    printf("%d", out);
}

