//
//  main.cpp
//  PAT A 1015 - Reversible Primes
//
//  Created by 97 on 2019/10/17.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N, D;

bool pd(int t){
    for (int i = 2; i <= sqrt(t); i++) {
        if (t % i == 0) return false;
    }
    return true;
}

int change(){
    int t = N;
    vector<int> v;
    while (t) {
        v.push_back(t % D);
        t = t / D;
    }
    int out = 0;
    for (int i = 0; i < v.size(); i++) {
        out += v[i] * pow(D, v.size() - i - 1);
    }
//    printf("%d\n", out);
    return out;
}

int main(){
    cin >> N;
    while (N > 0) {
        cin >> D;
        if (pd(N) == true && pd(change()) == true) printf("Yes\n");
        else printf("No\n");
        cin >> N;
    }
}
