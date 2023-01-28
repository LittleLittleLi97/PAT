//
//  main.cpp
//  PAT B 1046 - 划拳
//
//  Created by 97 on 2019/8/12.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    int Ahan, Ahua, Bhan, Bhua;
    int N;
    int Adrink = 0;
    int Bdrink = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> Ahan >> Ahua >> Bhan >> Bhua;
        if (Ahua == Bhua) continue;
        if (Ahua == Ahan + Bhan) Bdrink++;
        if (Bhua == Ahan + Bhan) Adrink++;
    }
    cout << Adrink << " " << Bdrink;
}
