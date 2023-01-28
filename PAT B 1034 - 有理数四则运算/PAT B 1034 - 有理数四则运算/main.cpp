//
//  main.cpp
//  PAT B 1034 - 有理数四则运算
//
//  Created by 97 on 2019/7/31.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>
#include <algorithm>

long long findgongyinshu(long long a, long long b){
    return b == 0 ? a : findgongyinshu(b, a % b);
}

void show(long long up, long long down){
    if (down < 0) {
        up = -up;
        down = -down;
    }
    long long t = findgongyinshu(labs(up), labs(down));
    up /= t; down /= t;
    if (up < 0) printf("(");
    if (up == 0) printf("0");
    else if (down == 1) printf("%lld", up);
    else if (labs(up) > labs(down)) printf("%lld %lld/%lld", up / down, labs(up) % down, down);
    else printf("%lld/%lld", up, down);
    if (up < 0) printf(")");
}
    

int main(){
    long long up1, down1, up2, down2;
    scanf("%lld/%lld %lld/%lld", &up1, &down1, &up2, &down2);
    long long up, down;
    
    up = up1 * down2 + up2 * down1; down = down1 * down2;
    show(up1, down1); printf(" + "); show(up2, down2); printf(" = "); show(up, down); printf("\n");
    
    up = up1 * down2 - down1 * up2; down = down1 * down2;
    show(up1, down1); printf(" - "); show(up2, down2); printf(" = "); show(up, down); printf("\n");
    
    up = up1 * up2; down = down1 * down2;
    show(up1, down1); printf(" * "); show(up2, down2); printf(" = "); show(up, down); printf("\n");
    
    if (up2 == 0) {
        show(up1, down1); printf(" / "); show(up2, down2); printf(" = Inf");
    }else {
        up = up1 * down2; down = down1 * up2;
        show(up1, down1); printf(" / "); show(up2, down2); printf(" = "); show(up, down);
    }
}

/*
#include <stdio.h>
#include <algorithm>

char out[10][100];

long long findgongyinshu(long long a, long long b){
    return b == 0 ? a : findgongyinshu(b, a % b);
//    int k = 1;
//    for (int i = 1; i <= a && i <= b; i++) {
//        if (a % i == 0 && b % i == 0) {
//            k = i;
//        }
//    }
//    return k;
}

int conversion(long long a, long long b, int which){
    int i = 0;
    bool flag = false;
    if (a < 0) {
        a = 0 - a;
        out[which][i++] = '(';
        out[which][i++] = '-';
        flag = true;
    }
    if (a < b && a != 0) {
        long long k = findgongyinshu(a, b);
        a /= k;
        b /= k;
        out[which][i++] = a + '0';
        out[which][i++] = '/';
        out[which][i++] = b + '0';
    }else if (a % b == 0) {
        out[which][i++] = a / b + '0';
    }else {
        long long k = findgongyinshu(a, b);
        a /= k;
        b /= k;
        out[which][i++] = a / b + '0';
        out[which][i++] = ' ';
        out[which][i++] = a % b + '0';
        out[which][i++] = '/';
        out[which][i++] = b + '0';
    }
    if (flag == true) {
        out[which][i++] = ')';
    }
    return i;
}

void preprint(int which, int many){
    for (int i = 0 ; i < many; i++) {
        printf("%c", out[which][i]);
    }
}

int main(){
    long long a;
    long long b;
    long long c;
    long long d;
    scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
    int ia = conversion(a, b, 0);
    int ib = conversion(c, d, 1);
    preprint(0, ia); printf(" + "); preprint(1, ib);
    int ijia = conversion(a * d + c * b, b * d, 2);
    printf(" = "); preprint(2, ijia);
    
    printf("\n");
    preprint(0, ia); printf(" - "); preprint(1, ib);
    int ijian = conversion(a * d - c * b, b * d, 3);
    printf(" = "); preprint(3, ijian);
    
    printf("\n");
    preprint(0, ia); printf(" * "); preprint(1, ib);
    int icheng = conversion(a * c, b * d, 4);
    printf(" = "); preprint(4, icheng);
    
    printf("\n");
    preprint(0, ia); printf(" / "); preprint(1, ib);
    printf(" = ");
    if (c == 0) {
        printf("Inf");
    }else {
        if (c < 0) {
            c = 0 - c;
            a = 0 - a;
        }
        int ichu = conversion(a * d, c * b, 5);
        preprint(5, ichu);
    }
}
*/
