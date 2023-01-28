//
//  main.cpp
//  PAT B 1014 - 福尔摩斯的约会
//
//  Created by 97 on 2019/7/21.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>
#include <string.h>

char a[4][100];
char mon[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main(){
    scanf("%s%s%s%s", a[0], a[1], a[2], a[3]);
    int i;
    for (i = 0; i < strlen(a[0]) && i < strlen(a[1]); i++) {
        if (a[0][i] == a[1][i] && a[0][i] >= 'A' && a[0][i] <= 'G') {
            printf("%s ", mon[a[0][i] - 'A']);
            break;
        }
    }
    for (i++; i < strlen(a[0]) && i < strlen(a[1]); i++) {
        if (a[0][i] == a[1][i]) {
            char temp = a[0][i];
            if ((temp >= '0' && temp <= '9') || (temp >= 'A' && temp <= 'N')) {
                if (temp >= '0' && temp <= '9') {
                    printf("0%c", temp);
                }else{
                    printf("%d", temp - 'A' + 10);
                }
                break;
            }
        }
    }
    printf(":");
    for (i = 0; i < strlen(a[2]) && i < strlen(a[3]); i++) {
        if (a[2][i] == a[3][i]) {
            char temp = a[2][i];
            if ((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'N')) {
                if (i < 10) {
                    printf("0%d", i);
                }else{
                    printf("%d", i);
                }
                break;
            }
        }
    }
}
