//
//  main.cpp
//  PAT B 1073 - 多选题常见记分法
//
//  Created by 97 on 2019/8/26.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

double grade[1010];

struct ask {
    int grade;
    int many;
    int rightmany;
    char right[10];
};
vector<ask> vask;

bool pd(int moment, char a){
    for (int i = 0; i < vask[moment].rightmany; i++) {
        if (vask[moment].right[i] == a) return true;
    }
    return false;
}

int main(){
    int N, M;
    cin >> N >> M;
    ask t;
    int error[110][10] = {0}; //[题目编号][选项号]
    for (int i = 0; i < M; i++) {
        cin >> t.grade >> t.many >> t.rightmany;
        for (int j = 0; j < t.rightmany; j++) cin >> t.right[j];
        vask.push_back(t);
    }
    getchar();
    string h;
    int maxcount = 0;
    for (int i = 0; i < N; i++) {
        getline(cin, h);
        int moment = -1;
        for (int j = 0; j < h.length(); j++) {
            if (h[j] >= '0' && h[j] <= '9') {
                moment++;
//                cout << " ti - - _____________________________ " << moment << endl;
                int tint = h[j] - '0';
//                cout << " tint " << tint<< endl;
                int count = 0;
                for (int k = 0; k < tint; j++) {
                    if (h[j] >= 'a' && h[j] <= 'z') {
//                        cout << h[j] << endl;
                        if (pd(moment, h[j])) {
                            count++;
                        }
                        else {
                            count = -10000;
                            error[moment][h[j] - 'a']++;
                            printf("%c\n", h[j]);
                            if (error[moment][h[j] - 'a'] > maxcount) {
                                maxcount = error[moment][h[j] - 'a'];
                                printf("maxcount = %d\n", maxcount);
                            }
                        }
                        k++;
                    }
                }
//                cout << " right - - count - - " << count << endl;
                if (count > 0) {
                    if (count == vask[moment].rightmany) grade[i] += vask[moment].grade;
                    else grade[i] += (double)vask[moment].grade / 2;
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        printf("%.1lf\n", grade[i]);
    }
//    printf("%d\n", maxcount);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < 10; j++) {
//            if (error[i][j] == maxcount) {
                printf("%d %d-%c\n", error[i][j], i + 1, j + 'a');
//            }
        }
    }
}
