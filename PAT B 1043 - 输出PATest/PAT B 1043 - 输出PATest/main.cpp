//
//  main.cpp
//  PAT B 1043 - 输出PATest
//
//  Created by 97 on 2019/8/10.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>

int a[6] = {0};

int main(){
    char n;
    n = getchar();
    while (n != '\n') {
        switch (n) {
            case 'P': a[0] += 1; break;
            case 'A': a[1] += 1; break;
            case 'T': a[2] += 1; break;
            case 'e': a[3] += 1; break;
            case 's': a[4] += 1; break;
            case 't': a[5] += 1; break;
        }
        n = getchar();
    }
//    int traversal = a[0] + a[1] + a[2] + a[3] + a[4] + a[5];
    int moment = 0;
    for (int i = 0; a[0] || a[1] || a[2] || a[3] || a[4] || a[5]; i++) {
        if (a[moment]) {
            switch (moment) {
                case 0: printf("P"); break;
                    case 1: printf("A"); break;
                    case 2: printf("T"); break;
                    case 3: printf("e"); break;
                    case 4: printf("s"); break;
                    case 5: printf("t"); break;
            }
            a[moment] -= 1;
        }
        moment = (moment + 1) % 6;
    }
}
