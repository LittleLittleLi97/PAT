//
//  main.cpp
//  PAT B 1024 科学计数法
//
//  Created by 97 on 2019/7/24.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>
#include <queue>
using namespace std;

queue<char> q;

int main(){     //这是重构后的，比第一次写的速度更快，逻辑更为清晰，而且输入'.'的位置不再限于题目所输入的数字第一位后
    char first;
    first = getchar();
    char tmp;
    tmp = getchar();
    int dot = 0;
    int i = 0;
    while (tmp != 'E') {
        if (tmp == '.') {
            dot = i;
            tmp = getchar();
            continue;
        }
        q.push(tmp);
        i++;
        tmp = getchar();
    }
    char second;
    second = getchar();
    int jie;
    scanf("%d", &jie);
    if (second == '-') dot -= jie;
    else dot += jie;
    long int total = q.size();
//    printf("first:%c - second:%c - dot:%d - jie:%d\n", first, second, dot, jie);
    if (first == '-') printf("-");
    if (dot > 0) {
        if (dot >= total) {
            while (!q.empty()) {
                printf("%c",q.front());
                q.pop();
            }
            for (i = 0; i < dot - total; i++) {
                printf("0");
            }
        }
        else {
            int count = 1;
            while (!q.empty()) {
                printf("%c",q.front());
                q.pop();
                if (dot == count) printf(".");
                count++;
            }
        }
    }
    else {
        printf("0.");
        int count = 0;
        for (; count < 0 - dot; count++) {
            printf("0");
        }
        while (!q.empty()) {
            printf("%c",q.front());
            q.pop();
        }
    }
}

/*  这是第一次写的，一直有几个点过不去，重构时终于找到了，原来是正负号的问题
 #include <stdio.h>
 #include <queue>
 using namespace std;
 
 queue<char> q;
 
 int main(){
 char zf;
 char a;
 zf = getchar();
 a = getchar();
 while (a != 'E') {
 if (a == '.') {
 a = getchar();
 continue;
 }
 q.push(a);
 a = getchar();
 }
 char Ezf;
 Ezf = getchar();
 int zhishu;
 scanf("%d", &zhishu);
 if (zf == '-') printf("%c", zf);       //就是在这里，只有‘-’的时候才输出符号，‘+’时不输出
 if (Ezf == '+') {
 int i = 0;
 while (1) {
 if (!q.empty()) {
 printf("%c", q.front());
 q.pop();
 if (!q.empty() && i == zhishu) {
 printf(".");
 }
 }else {
 if (i >= zhishu) {
 break;
 }else {
 while (i <= zhishu) {
 printf("0");
 i++;
 }
 break;
 }
 }
 i++;
 }
 }
 if (Ezf == '-') {
 int i = 0;
 while (!q.empty()) {
 if (zhishu > 0 && i == 0) {
 printf("0.");
 while (i < zhishu - 1) {
 printf("0");
 i++;
 }
 }else {
 printf("%c", q.front());
 if (i == 0) {
 printf(".");
 }
 q.pop();
 i++;
 }
 }
 }
 }
*/
