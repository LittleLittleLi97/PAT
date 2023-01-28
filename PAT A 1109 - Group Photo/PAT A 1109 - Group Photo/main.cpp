//
//  main.cpp
//  PAT A 1109 - Group Photo
//
//  Created by 97 on 2019/12/3.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Node {
    string Name;
    int Height;
};
vector<Node> v;
int N, K;

bool cmp(Node a, Node b){
    if (a.Height != b.Height) return a.Height > b.Height;
    else return a.Name < b.Name;
}

int main(){
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) {
        char a[10]; int b; scanf("%s %d", a, &b);
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), cmp);
    int i = 0;
    int j = 0;
    int mod = N % K;
    int len = N / K;
    for ( ; i < v.size(); ) {
        if (i == 0) {
            j = mod + len;
        }else j = i + len;
        vector<int> t;
        bool flag = false;
        for (int z = i; z < j; z++) {
            if (flag == false) {
                t.push_back(z);
                flag = true;
            }else if (flag == true) {
                t.insert(t.begin(), z);
                flag = false;
            }
        }
        for (int z = 0; z < t.size(); z++) {
            printf("%s", v[t[z]].Name.c_str());
            if (z != t.size() - 1) printf(" ");
        }
        printf("\n");
        i = j;
    }
}
