//
//  main.cpp
//  PAT A 1016 - Phone Bills
//
//  Created by 97 on 2019/10/21.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;

struct Node {
    char Name[22];
    int Month;
    int Day;
    int Hour;
    int Minute;
    bool State;
};
vector<Node> v;
int spend[24];
int N;
map<string, bool> m;
map<string, int> total;

bool cmp(Node a, Node b){
    int name = strcmp(a.Name, b.Name);
    if (name != 0) return name < 0;
    else if (a.Month != b.Month) return a.Month < b.Month;
    else if (a.Day != b.Day) return a.Day < b.Day;
    else if (a.Hour != b.Hour) return a.Hour < b.Hour;
    else return a.Minute < b.Minute;
}

void Cal(int a, int b, int &outlay, int &time){
    Node ta = v[a]; Node tb = v[b];
    while (ta.Day < tb.Day || ta.Hour < tb.Hour || ta.Minute < tb.Minute) {
        outlay += spend[ta.Hour];
        time++;
        ta.Minute++;
        if (ta.Minute == 60) {
            ta.Minute = 0;
            ta.Hour++;
        }
        if (ta.Hour == 24) {
            ta.Hour = 0;
            ta.Day++;
        }
    }
}

int main(){
    for (int i = 0; i < 24; i++) scanf("%d", &spend[i]);
    cin >> N;
    for (int i = 0; i < N; i++) {
        Node t;
        char state[10];
        scanf("%s %d:%d:%d:%d %s", t.Name, &t.Month, &t.Day, &t.Hour, &t.Minute, state);
        if (state[1] == 'n') t.State = true;
        else if (state[1] == 'f') t.State = false;
        v.push_back(t);
    }
    sort(v.begin(), v.end(), cmp);
//    cout << v.size() << endl;
//    for (int i = 0; i < v.size(); i++) {
//        Node t = v[i];
//        cout << t.Name << " " << t.Day << " " << t.Hour << " " << t.Minute << " " << t.State <<endl;
//    }
    for (int i = 0, j = 1; j <= v.size(); i++, j++) {
        if (strcmp(v[i].Name, v[j].Name) != 0) {
            if (m[v[i].Name] == true) {
                printf("Total amount: $%.2lf\n", (double)total[v[i].Name] / 100);
            }
            continue;
        }
        if (v[i].State == true && v[j].State == false) {
            if (m[v[i].Name] == false) {
                printf("%s %02d\n", v[i].Name, v[i].Month);
                m[v[i].Name] = true;
            }
            int outlay = 0, time = 0;
            Cal(i, j, outlay, time);
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n", v[i].Day, v[i].Hour, v[i].Minute, v[j].Day, v[j].Hour, v[j].Minute, time, (double)outlay / 100);
            total[v[i].Name] += outlay;
        }
    }
}
