//
//  main.cpp
//  PAT B1020 - 月饼
//
//  Created by 97 on 2019/7/18.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

struct MoonCake {
    double storage;
    double total_price;
    double price;
}Cake[1010];

bool cmp(MoonCake a, MoonCake b){
    return a.price > b.price;
}

int main(){
    int kinds;
    double needs;
    scanf("%d%lf", &kinds, &needs);
    for (int i = 0; i < kinds; i++) {
        scanf("%lf", &Cake[i].storage);
    }
    for (int i = 0; i < kinds; i++) {
        scanf("%lf", &Cake[i].total_price);
        Cake[i].price = Cake[i].total_price / Cake[i].storage;
    }
    sort(Cake, Cake + kinds, cmp);
    double result = 0;
    for (int i = 0; i < kinds; i++) {
        if (needs >= Cake[i].storage) {
            result += Cake[i].total_price;
            needs -= Cake[i].storage;
        }else{
            result += Cake[i].price * needs;
            break;
        }
    }
    printf("%.2lf", result);
    return 0;
}
