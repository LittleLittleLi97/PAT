//
//  main.cpp
//  PAT B 1040 - 有几个PAT
//
//  Created by 97 on 2019/8/8.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>
#include <string.h>

char s[100010];

int main(){
    scanf("%s", s);
    long long count = 0;
    long long a_count = 0;
    long long t_count = 0;  //没有用到
    long long p_count = 0;
    int a = 0;
    int p = 0;
    for (int t = 0; t < strlen(s); t++) {
        if (s[t] != 'T') continue;
        count += a_count;
        
        for (; a < t; a++) {
            if (s[a] != 'A') continue;
            count += p_count;
            a_count += p_count;
            
            for (; p < a; p++) {
                if (s[p] != 'P') continue;
                t_count++;      //
                a_count++;
                p_count++;
                
                count++;
                //                printf("%d %d %d \n", p+1, a+1, t+1);
            }
        }
    }
    printf("%lld", count % 1000000007);
}
