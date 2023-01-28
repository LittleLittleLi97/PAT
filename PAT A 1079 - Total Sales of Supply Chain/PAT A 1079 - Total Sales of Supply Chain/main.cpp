//
//  main.cpp
//  PAT A 1079 - Total Sales of Supply Chain
//
//  Created by 97 on 2019/11/25.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

struct Node {
    double Price;
    vector<int> Sub;
    double Amount;
};
Node v[100010];
int N;
double P, R;
vector<int> Retails;
double out = 0;

int main(){
    scanf("%d %lf %lf", &N, &P, &R);
    v[0].Price = P;
    for (int i = 0; i < N; i++) {
        int many;
        scanf("%d", &many);
        if (many == 0) {
            scanf("%lf", &v[i].Amount);
            Retails.push_back(i);
        }else {
            for (int j = 0; j < many; j++) {
                int which; scanf("%d", &which);
                v[i].Sub.push_back(which);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < v[i].Sub.size(); j++) {
            v[v[i].Sub[j]].Price = v[i].Price + v[i].Price * R / 100;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < v[i].Sub.size(); j++) {
            v[v[i].Sub[j]].Price = v[i].Price + v[i].Price * R / 100;
        }
    }
//    cout << Retails.size() << endl;
//    for (int i = 0; i < N; i++) {
//        printf("%d - %lf\n", i, v[i].Price);
//    }
//    
    for (int i = 0; i < Retails.size(); i++) {
        out += v[Retails[i]].Amount * v[Retails[i]].Price;
    }
    printf("%.1lf", out);
}
