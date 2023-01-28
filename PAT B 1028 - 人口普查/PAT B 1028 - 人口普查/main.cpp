//
//  main.cpp
//  PAT B 1028 - 人口普查
//
//  Created by 97 on 2019/7/29.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    char name[10];
    int year;
    int month;
    int day;
};

vector<Node> v;

bool cmp(Node a, Node b){
    if (a.year != b.year) {
        return a.year > b.year;
    }else if (a.month != b.month) {
        return a.month > b.month;
    }else return a.day > b.day;
}

int main(){
    int N;
    scanf("%d", &N);
    Node t;
    for (int i = 0; i < N; i++) {
        scanf("%s %d/%d/%d", t.name, &t.year, &t.month, &t.day);
        if (t.year == 1814 && t.month == 9 && t.day < 6) continue;
        else if (t.year == 1814 && t.month < 9) continue;
        if (t.year < 1814) continue;
        if (t.year == 2014 && t.month == 9 && t.day > 6) continue;
        else if (t.year == 2014 && t.month > 9) continue;
        if (t.year > 2014) continue;
        v.push_back(t);
    }
//    printf("\n");
//    for (int i = 0; i < v.size(); i++) {
//        printf("%s - %d/%d/%d\n", v[i].name, v[i].year, v[i].month, v[i].day);
//    }
    
    sort(v.begin(), v.end(), cmp);
    
//    printf("\n");
//    for (int i = 0; i < v.size(); i++) {
//        printf("%s - %d/%d/%d\n", v[i].name, v[i].year, v[i].month, v[i].day);
//    }
    
    if (v.size() == 0) printf("0");
    else printf("%ld %s %s", v.size(), v[v.size() - 1].name, v[0].name);
}
