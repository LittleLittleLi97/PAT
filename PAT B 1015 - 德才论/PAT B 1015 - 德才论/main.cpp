//
//  main.cpp
//  PAT B 1015 - 德才论
//
//  Created by 97 on 2019/7/22.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
    int num;    //这里把char num[10]改成了int就对了，莫名其妙
    int de;
    int cai;
    int grade;
};

vector<Node> v[4];

int N;

bool cmp(Node a, Node b){
    if (a.grade != b.grade) {
        return a.grade > b.grade;
    }else if (a.de != b.de) {
        return a.de > b.de;
    }else return a.num < b.num;
}

int main(){
    int L, H;
    scanf("%d%d%d", &N, &L, &H);
    Node temp;
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &temp.num, &temp.de, &temp.cai);
        temp.grade = temp.de + temp.cai;
        if (temp.de < L || temp.cai < L) {
            continue;
        }else if (temp.de >= H && temp.cai >= H) {
            v[0].push_back(temp);
        }else if (temp.de >= H && temp.cai < H) {
            v[1].push_back(temp);
        }else if (temp.de < H && temp.cai < H && temp.de >= temp.cai) {
            v[2].push_back(temp);
        }else {
            v[3].push_back(temp);
        }
    }
    int total_person = 0;
    for (int i = 0; i < 4; i++) {
        total_person += v[i].size();
    }
    printf("%d\n", total_person);
    for (int i = 0; i < 4; i++) {
        sort(v[i].begin(), v[i].end(), cmp);
        for (int j = 0; j < v[i].size(); j++) {
            printf("%d %d %d", v[i][j].num, v[i][j].de, v[i][j].cai);
            if (i != 3 || j != v[3].size() - 1) {
                printf("\n");
            }
        }
    }
}
