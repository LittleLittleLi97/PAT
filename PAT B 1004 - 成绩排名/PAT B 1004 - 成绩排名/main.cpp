//
//  main.cpp
//  PAT B 1004 - 成绩排名
//
//  Created by 97 on 2019/7/19.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

struct Information {
    char name[11];
    char hao[11];
    int grade;
}Student[10010];

bool cmp(Information a, Information b){
    return a.grade > b.grade;
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", Student[i].name);
        scanf("%s", Student[i].hao);
        scanf("%d", &Student[i].grade);
    }
    sort(Student, Student + n, cmp);
    printf("%s %s\n", Student[0].name, Student[0].hao);
    printf("%s %s", Student[n-1].name, Student[n-1].hao);
}
