//
//  main.cpp
//  PAT 1067 - Sort With Swap
//
//  Created by 97 on 2019/11/4.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> v;
int N;
int num = 0;    //除0以外不在本位的个数

int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int t; scanf("%d", &t);
        v.push_back(t);
        if (i != 0 && t != i) num++;
    }
    int count = 0;
    int k = 1;
    while (num > 0) {
        if (v[0] == 0) {
            while (k < v.size()) {
                if (k != v[k]) {
                    swap(v[0], v[k]);
                    count++;
                    break;
                }
                k++;
            }
        }else {
            swap(v[0], v[v[0]]);
            count++;
            num--;
        }
    }
    printf("%d", count);
}
