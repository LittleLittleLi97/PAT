//
//  main.cpp
//  PAT B 1091 - N-自守数
//
//  Created by 97 on 2019/8/16.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(){
    int M;
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int t;
        scanf("%d", &t);
        int flag = 0;
        for (int n = 1; n < 10; n++) {
            char a[10];
            char tout[10];
            int out = n * t * t;
            sprintf(a, "%d", out);
            sprintf(tout, "%d", t);
            if (strcmp(tout, a + strlen(a) - strlen(tout)) == 0) {
                printf("%d %d\n", n, out);
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            printf("No\n");
        }
    }
}
