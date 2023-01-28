//
//  main.cpp
//  PAT B 1018 - 锤子剪刀布
//
//  Created by 97 on 2019/7/23.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

struct Node {
    int win;
    int eval;
    int lose;
    int shoushi[3];
} a, b;

int pd(char q, char e){
    if (q == e) {
        return 0;
    }else if (q == 'C') {
        if (e == 'J') {
            return 1;
        }else return -1;
    }else if (q == 'J') {
        if (e == 'B') {
            return 1;
        }else return -1;
    }else {
        if (e == 'C') {
            return 1;
        }else return -1;
    }
}

void cal_shoushi(int zhi, char what) {
    if (what == 'C') {
        if (zhi == 1) {
            a.shoushi[0]++;
        }else if (zhi == -1) {
            b.shoushi[0]++;
        }
    }else if (what == 'B') {
        if (zhi == 1) {
            a.shoushi[2]++;
        }else if (zhi == -1) {
            b.shoushi[2]++;
        }
    }else {
        if (zhi == 1) {
            a.shoushi[1]++;
        }else if (zhi == -1) {
            b.shoushi[1]++;
        }
    }
}

int main(){
    a.win = 0; a.eval = 0; a.lose = 0;
    b.win = 0; b.eval = 0; b.lose = 0;
    for (int i = 0; i < 3; i++) {
        a.shoushi[i] = 0; b.shoushi[i] = 0;
    }
    int N;
    scanf("%d", &N);
    getchar();
    char jia, yi;
    for (int i = 0; i < N; i++) {
        scanf("%c %c", &jia, &yi);
        getchar();
        int out = pd(jia, yi);
        if (out == 1) {
            a.win++;
            b.lose++;
            cal_shoushi(1, jia);
        }else if (out == -1) {
            a.lose++;
            b.win++;
            cal_shoushi(-1, yi);
        }else{
            a.eval++;
            b.eval++;
        }
    }
    printf("%d %d %d\n", a.win, a.eval, a.lose);
    printf("%d %d %d\n", b.win, b.eval, b.lose);
    int amax = 0;
    int bmax = 0;
    int mp[3] = {1,2,0};
    for (int i = 1; i < 3; i++) {
        if (a.shoushi[i] > a.shoushi[amax]) {
            amax = i;
        }else if (a.shoushi[i] == a.shoushi[amax]) {
            if (mp[i] < mp[amax]) {
                amax = i;
            }
        }
        if (b.shoushi[i] > b.shoushi[bmax]) {
            bmax = i;
        }else if (b.shoushi[i] == b.shoushi[bmax]) {
            if (mp[i] < mp[bmax]) {
                bmax = i;
            }
        }
    }
    if (amax == 0) {
        printf("C ");
    }else if (amax == 1) {
        printf("J ");
    }else printf("B ");
    if (bmax == 0) {
        printf("C");
    }else if (bmax == 1) {
        printf("J");
    }else printf("B");
}
