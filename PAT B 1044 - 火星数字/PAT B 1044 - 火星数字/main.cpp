//
//  main.cpp
//  PAT B 1044 - 火星数字
//
//  Created by 97 on 2019/8/10.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

string low[13] = {"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string high[13] = {"","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};

int main(){
    int N;
    cin >> N;
    getchar();
    string t;
    for (int i = 0; i < N; i++) {
        getline(cin, t);
        if (t[0] >= '0' && t[0] <= '9') {
            int earth = 0;
            for (int i = 0; i < t.length(); i++) earth = earth * 10 + (t[i] - '0');
//            cout << earth << endl;
            if (earth < 13) cout << low[earth];
            else if (earth % 13 == 0) cout << high[earth / 13];
            else cout << high[earth / 13] << " " << low[earth % 13];
        }else if (t.length() <= 4){
            for (int j = 0; j < 13; j++) {
                if (t == low[j]) cout << j;
                if (t == high[j]) cout << j * 13;
            }
        }else {
            string a = t.substr(0, 3);
            string b = t.substr(4, 3);
            int out = 0;
            for (int j = 0; j < 13; j++) {
                if (a == high[j]) {
                    out += j * 13;
                }
                if (b == low[j]) {
                    out += j;
                }
            }
            cout << out;
        }
        cout << endl;
    }
}

/*
#include <stdio.h>
#include <math.h>
#include <string.h>

char low[13][5] = {"tret","jan","feb","mar","apr","may","jun","jly","aug","sep,","oct","nov","dec"};
char high[13][5] = {"","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};

int main(){
    int N;
    scanf("%d", &N);
    getchar();
    for (int i = 0; i < N; i++) {
        char a[10];
        char t;
        t = getchar();
        int count = 0;
        while (t != '\n') {
            a[count++] = t;
            t = getchar();
        }
        a[count] = '\0';
        if (a[0] >= '0' && a[0] <= '9') {
            int earth = 0;
            for (int j = 0; j < count; j++) {
                earth += (a[j] - '0') * pow(10, count - j - 1);
            }
            int h = earth / 13;
            printf("%s", high[h]);
            if (h && earth % 13 > 0) {
                printf(" %s", low[earth % 13]);
            }else if (earth % 13 > 0) printf("%s", low[earth % 13]);
            else printf("%s", low[earth % 13]);
        }else if (count <= 4) {
            for (int j = 0; j < 13; j++) {
                if (strcmp(a, low[j]) == 0) {
                    printf("%d", j);
                    break;
                }else if(strcmp(a, high[j]) == 0) {
                    printf("%d", j * 13);
                    break;
                }
            }
        }else {
            a[3] = '\0';
            int out = 0;
            for (int j = 0; j < 13; j++) {
                if (strcmp(a + 4, low[j]) == 0) {
                    out += j;
                }
                if(strcmp(a, high[j]) == 0) {
                    out += j * 13;
                }
            }
            printf("%d", out);
        }
        printf("\n");
    }
}
*/
