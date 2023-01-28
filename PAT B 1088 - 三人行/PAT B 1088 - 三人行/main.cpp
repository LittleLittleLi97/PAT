//
//  main.cpp
//  PAT B 1088 - 三人行
//
//  Created by 97 on 2019/8/20.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

void cmp(int a, int b){
    if (a == b) cout << "Ping";
    else if (a > b) cout << "Gai";
    else cout << "Cong";
}

int main(){
    int m, x, y;
    cin >> m >> x >> y;
    int jia = 10;
    int yi = 1;
    bool flag = false;
    for (int a = 1; a <= 9; a++) {
        for (int b = 0; b <= 9; b++) {
            int tjia = 10 * a + b;
            int tyi = a + 10 * b;
            if (fabs((double)tjia - (double)tyi) / x == (double)tyi / y) {
                flag = true;
                if (tjia > jia) {
                    jia = tjia;
                    yi = tyi;
                }
            }
        }
    }
    int bing = yi / y;
//    cout << jia << " " << yi << " " << bing << endl;
    if (flag == false) {
        cout << "No Solution";
        return 0;
    }
    cout << jia << " ";
    cmp(m, jia); cout << " ";
    cmp(m, yi); cout << " ";
    cmp(m, bing);
}
