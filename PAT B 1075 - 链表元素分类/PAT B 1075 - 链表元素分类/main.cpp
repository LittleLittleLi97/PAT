//
//  main.cpp
//  PAT B 1075 - 链表元素分类
//
//  Created by 97 on 2019/9/3.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;

// int 和 string 都超时，把insert改成3个vector

struct Node {
    int Address;
    int Data;
    int Next;
};
Node a[100010];
vector<Node> v[3];

int main(){
    int FirstAddress;
    int Many; int K;
    cin >> FirstAddress >> Many >> K;
    for (int i = 0; i < Many; i++) {
        Node t; cin >> t.Address >> t.Data >> t.Next;
        a[t.Address] = t;
    }
    int ad = FirstAddress;
    while (ad != -1) {
        Node t = a[ad];
        if (t.Data < 0) v[0].push_back(t);
        else if (t.Data <= K) v[1].push_back(t);
        else v[2].push_back(t);
        ad = t.Next;
    }
    v[0].insert(v[0].end(), v[1].begin(), v[1].end());
    v[0].insert(v[0].end(), v[2].begin(), v[2].end());
    for (int i = 0; i < v[0].size(); i++) {
        if (i == v[0].size() - 1) printf("%05d %d -1\n", v[0][i].Address, v[0][i].Data);
        else printf("%05d %d %05d\n", v[0][i].Address, v[0][i].Data, v[0][i + 1].Address);
    }
//    for (int i = 0; i < v[0].size(); i++) {
//        if (i == v[0].size() - 1) printf("%05d %d %05d\n", v[0][i].Address, v[0][i].Data, v[1][0].Address);
//        else printf("%05d %d %05d\n", v[0][i].Address, v[0][i].Data, v[0][i + 1].Address);
//    }
//    for (int i = 0; i < v[1].size(); i++) {
//        if (i == v[1].size() - 1) printf("%05d %d %05d\n", v[1][i].Address, v[1][i].Data, v[2][0].Address);
//        else printf("%05d %d %05d\n", v[1][i].Address, v[1][i].Data, v[1][i + 1].Address);
//    }
//    for (int i = 0; i < v[2].size(); i++) {
//        if (i == v[2].size() - 1) printf("%05d %d -1\n", v[2][i].Address, v[2][i].Data);
//        else printf("%05d %d %05d\n", v[2][i].Address, v[2][i].Data, v[2][i + 1].Address);
//    }
}

/*  //超时
struct Node {
    string Address;
    int Data;
    string Next;
};
Node a[100010];
vector<Node> v;

int main(){
    string FirstAddress;
    int Many; int K;
    cin >> FirstAddress >> Many >> K;
    for (int i = 0; i < Many; i++) {
        Node t; cin >> t.Address >> t.Data >> t.Next;
        a[stoi(t.Address)] = t;
    }
    int ad = stoi(FirstAddress);
    int fu_th = 0;
    int k_th = 0;
    while (ad != -1) {
        Node t = a[ad];
        if (t.Data < 0) {
            v.insert(v.begin() + fu_th, t);
            fu_th++;
            k_th++;
        }else if (t.Data <= K) {
            v.insert(v.begin() + k_th, t);
            k_th++;
        }else v.push_back(t);
        ad = stoi(t.Next);
    }
    for (int i = 0; i < v.size(); i++) {
        if (i == v.size() - 1) printf("%s %d -1\n", v[i].Address.c_str(), v[i].Data);
        else printf("%s %d %s\n", v[i].Address.c_str(), v[i].Data, v[i + 1].Address.c_str());
    }
}
*/
