//
//  main.cpp
//  20201121 Sort
//
//  Created by 97 on 2020/11/21.
//  Copyright © 2020 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#define MaxSize 100
using namespace std;

int numSort[11] = {0, 85, 55, 82, 57, 68, 92, 99, 98, 66, 56};  // the element of index 0 is shaobing

int Partition(int A[], int low, int high){
    int pivotkey = A[low];
    while (low < high) {
        while (low < high && A[high] > pivotkey) high--;
        A[low] = A[high];
        while (low < high && A[low] < pivotkey) low++;
        A[high] = A[low];
    }
    A[low] = pivotkey;
    return low;
}

void QuickSort(int A[], int low, int high){
    if (low < high) {
        int pivot = Partition(A, low, high);
        QuickSort(A, low, pivot - 1);
        QuickSort(A, pivot + 1, high);
    }
}

void Traversal(int A[], int n){
    for (int i = 1; i <= n; i++) {
        printf("%d\t", A[i]);
    }
    printf("\n");
}

void HeapAdjust(int A[], int i, int n){
    int j = i * 2;
    int k = A[i];
    while (j <= n) {
        if (j + 1 <= n && A[j + 1] > A[j]) j++;
        if (A[j] > k) {
            A[i] = A[j];
            i = j;
            j = j * 2;
        }else break;
    }
    A[i] = k;
}

void CreateHeap(int A[], int n){
    for (int i = n / 2; i >= 1; i--) {
        HeapAdjust(A, i, n);
    }
}

void HeapSort(int A[], int n){
    CreateHeap(A, n);
    for (int i = n; i > 1; i--) {
        swap(A[1], A[i]);
        HeapAdjust(A, 1, i - 1);
    }
}

int *MergeSup = (int *)malloc(sizeof(MaxSize));
void Merge(int A[], int low, int mid, int high){
    for (int i = low; i <= high; i++) {
        MergeSup[i] = A[i];
    }
    int pa = low;
    int pb = mid + 1;
    int p = low;
    while (pa <= mid && pb <= high) {
        if (MergeSup[pa] <= MergeSup[pb]) A[p++] = MergeSup[pa++];
        else A[p++] = MergeSup[pb++];
    }
    while (pa <= mid) A[p++] = MergeSup[pa++];
    while (pb <= high) A[p++] = MergeSup[pb++];
}

void MergeSort(int A[], int low, int high){
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(A, low, mid);
        MergeSort(A, mid + 1, high);
        Merge(A, low, mid, high);
    }
}

int main(){
    
}
