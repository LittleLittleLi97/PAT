//
//  main.cpp
//  PAT A 1022 - Digital Library
//
//  Created by 97 on 2019/11/17.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
    int ID;
    string Title;
    string Author;
    vector<string> Key;
    string Publisher;
    string Year;
};
vector<Node> v;
map<string, vector<int> > mTitle;
map<string, vector<int> > mAuthor;
map<string, vector<int> > mKey;
map<string, vector<int> > mPublisher;
map<string, vector<int> > mYear;

int N, M;

int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        Node t; scanf("%d", &t.ID);
        getchar();
        getline(cin, t.Title);
        mTitle[t.Title].push_back(i);
        getline(cin, t.Author);
        mAuthor[t.Author].push_back(i);
        string a; getline(cin, a); a += " ";
        string key;
        for (int j = 0; j < a.length(); j++) {
            if (a[j] == ' ') {
                t.Key.push_back(key);
                mKey[key].push_back(i);
                key = "";
            }else {
                key += a[j];
            }
        }
        getline(cin, t.Publisher);
        mPublisher[t.Publisher].push_back(i);
        getline(cin, t.Year);
        mYear[t.Year].push_back(i);
        v.push_back(t);
    }
//    for (int i = 0; i < v.size(); i++) {
//        cout << v[i].ID << " " << v[i].Year << endl;
//    }
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int what; scanf("%d", &what);
        getchar(); getchar();
        string a; getline(cin, a);
        vector<int> tv;
        vector<int> out;
        printf("%d: %s\n", what, a.c_str());
        if (what == 1) tv = mTitle[a];
        else if (what == 2) tv = mAuthor[a];
        else if (what == 3) tv = mKey[a];
        else if (what == 4) tv = mPublisher[a];
        else if (what == 5) tv = mYear[a];
        for (int j = 0; j < tv.size(); j++) {
            out.push_back(v[tv[j]].ID);
        }
        sort(out.begin(), out.end());
        for (int j = 0; j < out.size(); j++) {
            printf("%d\n", out[j]);
        }
        if (out.size() == 0) printf("Not Found\n");
    }
}
