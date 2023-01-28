//
//  main.cpp
//  PAT A 1114 - Family Property
//
//  Created by 97 on 2019/12/5.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
#define MaxSize 10010
using namespace std;

struct Node {
    int ID;
    vector<int> Sub;
    int Mstate;
    int Area;
};
struct OutNode {
    int ID;
    int Num;
    double totalMstate; //  total是平均
    double totalArea;   //  没有改掉
};
map<int, Node> m;
map<int, int> mIDtoInt;
vector<Node> v;
vector<OutNode> w;
bool ever[MaxSize];
int N;

bool cmp(OutNode a, OutNode b){
    if (a.totalArea != b.totalArea) return a.totalArea > b.totalArea;
    else return a.ID < b.ID;
}

void DFS(int st, int &totalMstate, int &totalArea, int &num, int &minID){
    num++;
    totalMstate += v[st].Mstate;
    totalArea += v[st].Area;
    if (v[st].ID < minID) minID = v[st].ID;
    ever[st] = true;
    for (int i = 0; i < v[st].Sub.size(); i++) {
        int willID = v[st].Sub[i];
        int willIndex = mIDtoInt[willID];
        if (ever[willIndex] == false) {
            DFS(willIndex, totalMstate, totalArea, num, minID);
        }
    }
}

int DFSTraversal(){
    int count = 0;
    for (int i = 0; i < v.size(); i++) {
        if (ever[i] == false) {
            int totalMstate = 0;
            int totalArea = 0;
            int num = 0;
            int minID = v[i].ID;
            ever[i] = true;
            DFS(i, totalMstate, totalArea, num, minID);
            count++;
            OutNode t;
            t.ID = minID;
            t.Num = num;
            t.totalMstate = (double)totalMstate / num;
            t.totalArea = (double)totalArea / num;
            w.push_back(t);
        }
    }
    return count;
}

int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int id, a, b; scanf("%d%d%d", &id, &a, &b);
        m[id].ID = id;
        if (a != -1) {
            m[a].ID = a;
            m[a].Sub.push_back(id);
            m[id].Sub.push_back(a);
        }
        if (b != -1) {
            m[b].ID = b;
            m[b].Sub.push_back(id);
            m[id].Sub.push_back(b);
        }
        int many; scanf("%d", &many);
        for (int j = 0; j < many; j++) {
            int what; scanf("%d", &what);
            m[id].Sub.push_back(what);
            m[what].ID = what;
            m[what].Sub.push_back(id);
        }
        int x, y; scanf("%d%d", &x, &y);
        m[id].Mstate = x;
        m[id].Area = y;
    }
    for (map<int, Node> :: iterator it = m.begin(); it != m.end(); it++) {
        it->second.ID = it->first;
        mIDtoInt[it->first] = v.size();
        v.push_back(it->second);
    }
    int count = DFSTraversal();
    sort(w.begin(), w.end(), cmp);
    printf("%d\n", count);
    for (int i = 0; i < w.size(); i++) {
        printf("%04d %d %.3lf %.3lf\n", w[i].ID, w[i].Num, w[i].totalMstate, w[i].totalArea);
    }
}
