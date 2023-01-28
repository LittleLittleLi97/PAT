//
//  main.cpp
//  PAT B 1095 - 解码PAT准考证
//
//  Created by 97 on 2019/8/17.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <stdio.h>
using namespace std;

struct Node {
//    char Class;
//    string Room;
//    string Date;
//    string Num;
    string All;
    int Grade;
}a[10010];

struct t3Node {
    string Room;
    int Count;
};

int N;
int M;

bool cmpGrade(Node m, Node n){
    if (m.Grade != n.Grade) return m.Grade > n.Grade;
    else return m.All < n.All;
}

bool th3_Count(t3Node m, t3Node n){
    if (m.Count != n.Count) return m.Count > n.Count;
    else return m.Room < n.Room;
}

void Traversal_Grade(char c){
    bool flag = false;
    for (int i = 0; i < N; i++) {
        if (a[i].All[0] == c) {
//            cout << a[i].All << " " << a[i].Grade << endl;
            printf("%s %d\n", a[i].All.c_str(), a[i].Grade);
            flag = true;
        }
    }
    if (!flag) printf("NA\n");
}

int main(){
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> a[i].All >> a[i].Grade;
//        string hao;
//        cin >> hao >> t.Grade;
//        t.Class = hao[0];
//        t.Room = hao.substr(1, 3);
//        t.Date = hao.substr(4, 6);
//        t.Num = hao.substr(10, 3);
//        t.All = hao;
//        a[i] = t;
    }
//    cout << a[0].Class <<" "<< a[0].Room <<" "<< a[0].Date << a[0].Num << " " << a[0].Grade;
    for (int i = 0; i < M; i++) {
        int th;
        string what;
        cin >> th >> what;
        cout << "Case " << i + 1 << ": " << th << " " << what << endl;
        if (th == 1) {
            sort(a, a + N, cmpGrade);
            if (what[0] == 'B') Traversal_Grade('B');
            if (what[0] == 'A') Traversal_Grade('A');
            if (what[0] == 'T') Traversal_Grade('T');
        }else if (th == 2) {
            bool flag = false;
            int count = 0;
            int out = 0;
            for (int j = 0; j < N; j++) {
                if (what == a[j].All.substr(1, 3)) {
                    count++;
                    out += a[j].Grade;
                    flag = true;
                }
            }
            if (flag) //cout << count << " " << out << endl;
                printf("%d %d\n", count, out);
            else printf("NA\n");
        }else if (th == 3) {
            bool flag = false;
            unordered_map<string, int> m;
            vector<t3Node> v;
            for (int j = 0; j < N; j++) {
                if (what == a[j].All.substr(4, 6)) {
                    m[a[j].All.substr(1, 3)]++;
                }
            }
            for (auto it:m) v.push_back({it.first, it.second});
            sort(v.begin(), v.end(), th3_Count);
            for (int j = 0; j < v.size(); j++) {
                flag = true;
//                cout << v[j].Room << " " << v[j].Count << endl;
                printf("%s %d\n", v[j].Room.c_str(), v[j].Count);
            }
            if (flag == false) printf("NA\n");
        }
    }
}
