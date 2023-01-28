//
//  main.cpp
//  PAT B 1089 - 狼人杀
//
//  Created by 97 on 2019/8/20.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    int say[N + 1];
    for (int i = 1; i <= N; i++) cin >> say[i];
//    for (int i = 1; i <= N; i++) {
//        cout << say[i] << " ";
//    }
//    return 0;
    for (int i = 1; i <= N - 1; i++) {
        for (int j = i + 1; j <= N; j++) {
            int lieWolf = 0;
            int lieHuman = 0;
            for (int k = 1; k <= N; k++) {
                if ((say[k] > 0 && (say[k] == i || say[k] == j)) || (say[k] < 0 && (say[k] != -i && say[k] != -j))) {
                    if (k == i || k == j) lieWolf++;
                    lieHuman++;
//                    cout << " i - j " << i << " - " << j << endl;
//                    cout << " - " << k << endl;
                }
            }
//            cout << lieHuman << " - " << lieWolf << endl;
            if (lieWolf == 1 && lieHuman == 2) {
                cout << i << " " << j;
                return 0;
            }
        }
    }
    cout << "No Solution";
}
