//
//  main.cpp
//  PAT A 1107 - Social Clusters
//
//  Created by 97 on 2019/11/27.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Person[1010];
vector<int> Hobby[1010];
bool PersonFlag[1010];
bool HobbyFlag[1010];
int N;
vector<int> out;

bool cmp(int a, int b){
    return a > b;
}

void DFSTraversal(int which, int &count){
    PersonFlag[which] = true;
    count++;
    for (int i = 0; i < Person[which].size(); i++) {
        int hobbyIndex = Person[which][i];
        if (HobbyFlag[hobbyIndex] == false) {
            HobbyFlag[hobbyIndex] = true;
            for (int j = 0; j < Hobby[hobbyIndex].size(); j++) {
                int personIndex = Hobby[hobbyIndex][j];
                if (PersonFlag[personIndex] == false) {
                    PersonFlag[personIndex] = true;
                    DFSTraversal(personIndex, count);
                }
            }
        }
    }
}

void DFS(){
    for (int i = 1; i <= N; i++) {
        if (PersonFlag[i] == false) {
            PersonFlag[i] = true;
            int count = 0;
            DFSTraversal(i, count);
            out.push_back(count);
        }
    }
}

int main(){
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        int many; scanf("%d", &many);
        getchar(); getchar();
        for (int j = 0; j < many; j++) {
            int t; scanf("%d", &t);
            Person[i].push_back(t);
            Hobby[t].push_back(i);
        }
    }
    DFS();
    sort(out.begin(), out.end(), cmp);
    printf("%ld\n", out.size());
    for (int i = 0; i < out.size(); i++) {
        printf("%d", out[i]);
        if (i != out.size() - 1) printf(" ");
    }
}
