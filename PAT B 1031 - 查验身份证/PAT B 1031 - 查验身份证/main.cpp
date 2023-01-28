//
//  main.cpp
//  PAT B 1031 - 查验身份证
//
//  Created by 97 on 2019/7/30.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char what[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

char a[100][20];

int main(){
    int many;
    scanf("%d", &many);
    char t[20];
    int rest = 0;
    for (int i = 0; i < many; i++) {
        scanf("%s", t);
        int sum = 0;
        for (int j = 0; j < 17; j++) {
            sum += (t[j] - '0') * weight[j];
        }
        int mod = sum % 11;
        if (t[17] != what[mod]) {
            strcpy(a[rest], t);
            rest++;
        }
    }
    if (rest) {
        for (int i = 0; i < rest; i++) {
            printf("%s", a[i]);
            if (i != rest - 1) {
                printf("\n");
            }
        }
    }else printf("All passed");
}
