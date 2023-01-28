//
//  main.cpp
//  PAT A 1034 - Head of a Gang
//
//  Created by 97 on 2019/10/8.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#define MaxSize 2010
using namespace std;

map<string, int> mStrToInt;
map<int, string> mIntToStr;
map<string, int> mOut;
int mCount = 1;
int Graph[MaxSize][MaxSize];
int Weight[MaxSize];
bool ever[MaxSize];
int N, K;

void Enter(string a){
    if (mStrToInt[a] == 0) {
        mStrToInt[a] = mCount;
        mIntToStr[mCount] = a;
        mCount++;
    }
}

void DFSTraversal(int st, int &totalTime, int &Head, int &num){
    ever[st] = true;
    num++;
    if (Weight[st] > Weight[Head]) Head = st;
    for (int i = 1; i < mCount; i++) {
        if (Graph[st][i] > 0) {
            totalTime += Graph[st][i];
            Graph[st][i] = Graph[i][st] = 0;
            if (ever[i] == false) {
                DFSTraversal(i, totalTime, Head, num);
            }
        }
    }
}

void DFS(){
    for (int i = 1; i < mCount; i++) {
        if (ever[i] == false) {
            int totalTime = 0, Head = i, num = 0;
            DFSTraversal(i, totalTime, Head, num);
            if (totalTime > K && num > 2) {
                mOut[mIntToStr[Head]] = num;
//                printf(" - %d\n", totalTime);
            }
        }
    }
}

int main(){
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        char a[5], b[5]; scanf("%s", a); scanf("%s", b);
        Enter(a); Enter(b);
        int x = mStrToInt[a]; int y = mStrToInt[b];
        int time; scanf("%d", &time);
        Graph[x][y] += time; Graph[y][x] += time;
        Weight[x] += time; Weight[y] += time;
    }
    DFS();
    printf("%ld\n", mOut.size());
    for (map<string, int> :: iterator it = mOut.begin(); it != mOut.end(); it++) {
        printf("%s %d\n", it->first.c_str(), it->second);
    }
}
