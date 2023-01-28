//
//  main.cpp
//  PAT A 1033 - To Fill or Not to Fill
//
//  Created by 97 on 2019/11/2.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;

struct Station {
    double Price;
    double Distance;
};
vector<Station> v;
double Capacity, TotalDistance, KmPerGas;
int N;
double Outlay, nowGas;

bool cmp(Station a, Station b){
    return a.Distance < b.Distance;
}

int main(){
    scanf("%lf%lf%lf%d", &Capacity, &TotalDistance, &KmPerGas, &N);
    for (int i = 0; i < N; i++) {
        Station t; scanf("%lf%lf", &t.Price, &t.Distance);
        v.push_back(t);
    }
    v.push_back({0, TotalDistance});
    sort(v.begin(), v.end(), cmp);
    if (v[0].Distance != 0) {
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    int now = 0;
    while (now < v.size()) {
        int u = -1;
        double minPrice = INF;
        for (int i = now + 1; i < v.size() && v[i].Distance - v[now].Distance <= Capacity * KmPerGas; i++) {
            if (v[i].Price < minPrice) {
                u = i;
                minPrice = v[i].Price;
                if (minPrice < v[now].Price) {
                    break;
                }
            }
        }
//        cout << "now " << now << endl;
        if (u == -1) break;
        double needGas = (v[u].Distance - v[now].Distance) / KmPerGas - nowGas;
        if (v[u].Price < v[now].Price) {
            Outlay += needGas * v[now].Price;
            nowGas = 0;
        }else {
            Outlay += (Capacity - nowGas) * v[now].Price;
            nowGas = Capacity - (v[u].Distance - v[now].Distance) / KmPerGas;
        }
        now = u;
    }
    if (v[now].Distance == TotalDistance) {
        printf("%.2lf", Outlay);
    }else printf("The maximum travel distance = %.2lf", v[now].Distance + Capacity * KmPerGas);
}
