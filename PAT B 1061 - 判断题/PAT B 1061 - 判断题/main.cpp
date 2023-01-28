//
//  main.cpp
//  PAT B 1061 - 判断题
//
//  Created by 97 on 2019/9/1.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

struct Node {
    int Grade;
    int Response;
};
vector<Node> v;

int main(){
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        Node t;
        cin >> t.Grade;
        v.push_back(t);
    }
    for (int i = 0; i < M; i++) {
        cin >> v[i].Response;
    }
    for (int i = 0; i < N; i++) {
        int out = 0;
        for (int j = 0; j < M; j++) {
            int t;
            cin >> t;
            if (t == v[j].Response) out += v[j].Grade;
        }
        cout << out << endl;
    }
}
