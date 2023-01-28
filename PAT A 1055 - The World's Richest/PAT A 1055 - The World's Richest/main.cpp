//
//  main.cpp
//  PAT A 1055 - The World's Richest
//
//  Created by 97 on 2019/10/23.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct Node {
    string Name;
    int Age;
    int Worth;
};
vector<Node> v;
int N, K;

bool cmp(Node a, Node b){
    if (a.Worth != b.Worth) return a.Worth > b.Worth;
    else if (a.Age != b.Age) return a.Age < b.Age;
    else return a.Name < b.Name;
}

int main(){
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        Node t; cin >> t.Name >> t.Age >> t.Worth;
        v.push_back(t);
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 1; i <= K; i++) {
        int count, a, b;
        cin >> count >> a >> b;
        int nowCount = 0;
        printf("Case #%d:\n", i);
        for (int j = 0; j < v.size() && nowCount < count; j++) {
            if (v[j].Age >= a && v[j].Age <= b) {
                nowCount++;
                printf("%s %d %d\n", v[j].Name.c_str(), v[j].Age, v[j].Worth);
            }
        }
        if (nowCount == 0) printf("None\n");
    }
}
