//
//  main.cpp
//  PAT A 1095 - Cars on Campus
//
//  Created by 97 on 2019/10/28.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

struct Node {
    char ID[10];
    int time;
    bool in0out1;
};
vector<Node> v;
vector<Node> w; //有效记录
map<string, int> m; //记录总时长
int N, K;
int maxTime = 0;

int ChangeTime(int a, int b, int c){
    return a * 3600 + b * 60 + c;
}

bool cmpInit(Node a, Node b){
    string x = a.ID; string y = b.ID;
    if (x != y) return x < y;
    else return a.time < b.time;
}

bool cmpValid(Node a, Node b){
    return a.time < b.time;
}

int main(){
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        Node t; int a, b, c; char state[5];
        scanf("%s %d:%d:%d %s", t.ID, &a, &b, &c, state);
        t.time = ChangeTime(a, b, c);
        if (state[0] == 'i') t.in0out1 = false;
        else t.in0out1 = true;
        v.push_back(t);
    }
    sort(v.begin(), v.end(), cmpInit);
//    for (int i = 0; i < v.size(); i++) {
//        Node t = v[i];
//        printf("%s %d %d\n", t.ID, t.time, t.in0out1);
//    }
    for (int i = 0, j = 1; j < v.size(); i++, j++) {
        if (strcmp(v[i].ID, v[j].ID) == 0 && v[i].in0out1 == false && v[j].in0out1 == true) {
            m[v[i].ID] += v[j].time - v[i].time;
            if (m[v[i].ID] > maxTime) maxTime = m[v[i].ID];
            w.push_back(v[i]);
            w.push_back(v[j]);
        }
    }
    sort(w.begin(), w.end(), cmpValid);
//    for (int i = 0; i < w.size(); i++) {
//        Node t = w[i];
//        printf("%s %d %d\n", t.ID, t.time, t.in0out1);
//    }
    int now = 0;
    int count = 0;
    for (int i = 0; i < K; i++) {
        int a, b, c; scanf("%d:%d:%d", &a, &b, &c);
        int time = ChangeTime(a, b, c);
//        printf("time = %d\n", time);
        while (time >= w[now].time && now < w.size()) {
            if (w[now].in0out1 == false) count++;
            else count--;
            now++;
        }
        printf("%d\n", count);
    }
    for (auto it : m) {
        if (it.second == maxTime) {
            printf("%s ", it.first.c_str());
        }
    }
    printf("%02d:%02d:%02d", maxTime / 3600, maxTime % 3600 / 60, maxTime % 60);
}
    


/*  超时 21分
struct Record {
    char ID[10];
    int Hour, Minute, Second;
    int Total;
    bool in0out1;
};
vector<Record> v;
int N, K;

struct Statistic {
    int Total;
    vector<int> enter;
    vector<int> out;
};
map<string, Statistic> m;

struct out {
    string ID;
    int Total;
};
vector<out> w;

int ChangeTime(int a, int b, int c){
    return a * 60 * 60 + b * 60 + c;
}

void outTime(int a, int &hour, int &minute, int &second){
    hour = a / (60 * 60);
    a = a % (60 * 60);
    minute = a / 60;
    a = a % 60;
    second = a;
}

bool cmpInit(Record a, Record b){
    string x = a.ID;
    string y = b.ID;
    if (x != y) return x < y;
    else return a.Total < b.Total;
}

bool cmpout(out a, out b) {
    if (a.Total != b.Total) return a.Total > b.Total;
    else return a.ID < b.ID;
}

int main(){
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        Record t;
        char what[5];
        scanf("%s %d:%d:%d %s", t.ID, &t.Hour, &t.Minute, &t.Second, what);
        if (what[0] == 'i') t.in0out1 = false;
        else t.in0out1 = true;
        t.Total = ChangeTime(t.Hour, t.Minute, t.Second);
        v.push_back(t);
    }
    sort(v.begin(), v.end(), cmpInit);
//    for (int i = 0; i < v.size(); i++) {
//        Record t = v[i];
//        printf("%s %d:%d:%d %d %d\n", t.ID, t.Hour, t.Minute, t.Second, t.Total, t.in0out1);
//    }
//    int count = 0;
    // count - 统计成对记录的数量
    for (int i = 0, j = 1; j < v.size(); i++, j++) {
        if (v[i].in0out1 == false && v[j].in0out1 == true) {
            if (strcmp(v[i].ID, v[j].ID) == 0) {
                string t = v[i].ID;
                m[t].enter.push_back(v[i].Total);
                m[t].out.push_back(v[j].Total);
                m[t].Total += v[j].Total - v[i].Total;
//                count++;
            }
        }
    }
//    printf("%d", count);
    for (int i = 0; i < K; i++) {
        int a, b, c; scanf("%d:%d:%d", &a, &b, &c);
        int now = ChangeTime(a, b, c);
        int num = 0;
        for (auto it : m) {
//            printf("%d\n", now);
//            printf("size = %d\n", it.second.enter.size());
            for (int j = 0; j < it.second.enter.size(); j++) {
                if (now >= it.second.enter[j] && now < it.second.out[j]) {
                    num++;
                    break;
                }
            }
        }
        printf("%d\n", num);
    }
    for (auto it : m) {
        w.push_back({it.first, it.second.Total});
    }
    sort(w.begin(), w.end(), cmpout);
    printf("%s", w[0].ID.c_str());
    for (int i = 1; i < w.size(); i++) {
        if (w[i].Total == w[0].Total) printf(" %s", w[i].ID.c_str());
        else break;
    }
    int hour, minute, second;
    outTime(w[0].Total, hour, minute, second);
    printf(" %02d:%02d:%02d", hour, minute, second);
}
*/
