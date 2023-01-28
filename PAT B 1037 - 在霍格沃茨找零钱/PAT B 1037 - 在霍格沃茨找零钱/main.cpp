//
//  main.cpp
//  PAT B 1037 - 在霍格沃茨找零钱
//
//  Created by 97 on 2019/8/5.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>

struct Node {
    int Galleon;
    int Sickle;
    int Knut;
    int total;
};

void calculate(Node &pointer){
    pointer.total = pointer.Galleon * 17 * 29 + pointer.Sickle * 29 + pointer.Knut;
}

int main(){
    Node P;
    Node A;
    scanf("%d.%d.%d %d.%d.%d", &P.Galleon, &P.Sickle, &P.Knut, &A.Galleon, &A.Sickle, &A.Knut);
    Node re;
    calculate(P); calculate(A);
//    printf("%d - %d", P.total, A.total);
    re.total = A.total - P.total;
    if (re.total < 0) {
        re.total = -re.total;
        printf("-");
    }
    re.Sickle = re.total / 29;
    re.Knut = re.total % 29;
    re.Galleon = re.Sickle / 17;
    re.Sickle = re.Sickle % 17;
    printf("%d.%d.%d", re.Galleon, re.Sickle, re.Knut);
}
