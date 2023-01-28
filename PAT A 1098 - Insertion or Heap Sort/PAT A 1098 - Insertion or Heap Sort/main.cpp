//
//  main.cpp
//  PAT A 1098 - Insertion or Heap Sort
//
//  Created by 97 on 2019/11/27.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int Init[110];
int Insert[110];
int Heap[110];
int out[110];
int N;

void Traversal(int a[]){
    for (int i = 1; i <= N ; i++) {
        printf("%d", a[i]);
        if (i != N) printf(" ");
    }
    printf("\n");
}

bool pd(int a[]){
    for (int i = 1; i <= N; i++) {
        if (a[i] != out[i]) return false;
    }
    return true;
}

bool InsertSort(){
    bool flag = false;
    for (int i = 2; i <= N; i++) {
        int t = Insert[i];
        int j = i - 1;
        for ( ; j >= 1; j--) {
            if (Insert[j] > t) Insert[j + 1] = Insert[j];
            else break;
        }
        Insert[j + 1] = t;
        if (flag == true) {
            printf("Insertion Sort\n");
            Traversal(Insert);
            return true;
        }
        if (pd(Insert) == true) flag = true;
    }
    return false;
}

void downAdjust(int low, int high){
    int i = low;
    int j = i * 2;
    while (j <= high) {
        if (j + 1 <= high && Heap[j + 1] > Heap[j]) j = j + 1;
        if (Heap[j] > Heap[i]) {
            swap(Heap[i], Heap[j]);
            i = j;
            j = j * 2;
        }else break;
    }
}

void CreateHeap(){
    for (int i = N / 2; i >= 1; i--) {
        downAdjust(i, N);
    }
}

bool HeapSort(){
    CreateHeap();
    bool flag = false;
    for (int i = N; i > 1; i--) {
        swap(Heap[i], Heap[1]);
        downAdjust(1, i - 1);
        if (flag == true) {
            printf("Heap Sort\n");
            Traversal(Heap);
            return true;
        }
        if (pd(Heap) == true) flag = true;
    }
    return false;
}

int main(){
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &Init[i]);
        Insert[i] = Heap[i] = Init[i];
    }
    for (int i = 1; i <= N; i++) {
        scanf("%d", &out[i]);
    }
    if (InsertSort() == true) return 0;
    if (HeapSort() == true) return 0;
    return 0;
}
