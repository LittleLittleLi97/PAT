//
//  main.cpp
//  Second PAT A 1007 - Maximum Subsequence Sum
//
//  Created by 97 on 2021/9/23.
//  Copyright © 2021 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int K;
struct Node {
    int i;
    int j;
};
vector<int> vIn;
vector<Node> vRecord;
int dp[10010];

int main() {
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        int t;
        scanf("%d", &t);
        vIn.push_back(t);
    }
    dp[0] = vIn[0];
    Node tNode;
    tNode.i = tNode.j = 0;
    vRecord.push_back(tNode);
    for (int i = 1; i < vIn.size(); i++) {
        if (dp[i - 1] + vIn[i] > vIn[i]) {
            dp[i] = dp[i - 1] + vIn[i];
            tNode.i = vRecord[i - 1].i;
            tNode.j = i;
            vRecord.push_back(tNode);
        }else {
            dp[i] = vIn[i];
            tNode.i = i;
            tNode.j = i;
            vRecord.push_back(tNode);
        }
    }
    int outIndex = 0;
    for (int i = 0; i < vIn.size(); i++) {
        if (dp[i] > dp[outIndex]) {
            outIndex = i;
        }
    }
    if (dp[outIndex] < 0) printf("0 %d %d", vIn[0], vIn[vIn.size() - 1]);
    else printf("%d %d %d", dp[outIndex], vIn[vRecord[outIndex].i], vIn[vRecord[outIndex].j]);
}
