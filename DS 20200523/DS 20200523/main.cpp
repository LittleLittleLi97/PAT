//
//  main.cpp
//  DS 20200523
//
//  Created by 97 on 2020/5/23.
//  Copyright © 2020 97. All rights reserved.
//

// typedef struct LNode
// LinkList HeadInsert(LinkList &L)
// LinkList TailInsert(LinkList &L)
// bool Insert(LinkList &L, int i, ElemType e)
// bool Delete(LinkList &L, int i, ElemType &e)
// void Traversal(LinkList L)
// int Length(LinkList L)

// typedef struct CNode
// CLinkList TailInsert(CLinkList &L)
// void Traversal(CLinkList L)

// typedef struct CDNode
// CDLinkList TailInsert(CDLinkList &L)
// void Traversal(CDLinkList L)

// typedef struct SqStack
// void Init(SqStack &S)
// bool Push(SqStack &S, ElemType e)
// bool Pop(SqStack &S, ElemType &e)
// bool GetTop(SqStack S, ElemType &e)
// bool IsEmpty(SqStack S)

// typedef struct SqQueue
// void Init(SqQueue &Q)
// bool EnQueue(SqQueue &Q, ElemType e)
// bool DeQueue(SqQueue &Q, ElemType &e)
// bool IsEmpty(SqQueue Q)

// List
// P40 1 void RecursiveDeleteAllX(LinkList &L, ElemType x)
// P40 2 void DeleteALLX(LinkList &L, ElemType x)
// P40 3 void ReversePrint(LinkList L)
// P40 4 void DeleteMin(LinkList &L)
// P40 5 void Reverse(LinkList &L)
// P40 6 void Sort(LinkList &L)
// P40 7 void DeleteAllStoT(LinkList &L, ElemType S, ElemType T)
// P41 8 LinkList SearchCommonNode(LinkList A, LinkList B)
// Sup void ConnectTwoLinkList(LinkList &A, LinkList &B, int i)
// P41 9 void AscendingPrintAndDelele(LinkList &L)
// P41 10 void Seperate(LinkList &A, LinkList &B)
// P41 11 void Seperate(LinkList &C, LinkList &A, LinkList &B)
// P41 12 void DelelteCommon(LinkList &L)
// P41 13 LinkList MergeAscendToNoAscend(LinkList &A, LinkList &B)
// P41 14 void CommonNodeToNewList(LinkList A, LinkList B, LinkList &C)
// P42 15 be similar to P42 14
// P42 16 bool IsSub(LinkList A, LinkList B)
// P42 17 bool IsSymmetric(CDLinkList L)
// P42 18 void ConnectTwoCLinkList(CLinkList &A, CLinkList &B)
// P42 19 void DeleteMinAndPrintToNULL(LinkList &L)
// P42 21 void SearchReverseKthAndPrint(LinkList L, int k)
// P43 22 be same to P41 8
// P43 23 void DeleteRestAbsoluteData(LinkList &L, int n)
// P44 24 LinkList SearchCirleEnterNode(LinkList L)
// Sup void ConnectTailWithith(LinkList &L, int i)
// P44 25 void IDontKnowThisFunctionName(LinkList &L)

// Stack
// P71 4 bool IsSymmetric(LinkList L, int n)
// void InConvertPost(char A[])
// Sup int OperatorPriority(char c)
// void InChangeToPost(char A[], int n)
// Sup int Prio(char a)

// Tree
// P149 4 void ReverseLevelTraversal(BiTree T)
// Get The Height of Tree In Recursive int GetHeight(BiTree T)
// P149 5 int GetHeightNoRecursive(BiTree T)
// P149 6 BiTree CreateTreePreAndIn(int Pre[], int In[], int PreLeft, int PreRight, int InLeft, int InRight)
// P150 7 bool IsCompleteBinaryTree(BiTree T)
// P150 8 int CalculateTwoChildNode(BiTree T)
// P150 9 void ExchangeLeftAndRight(BiTree &T)
// P150 10 int GetInOrderKthData(BiTree T, int k)
// P150 11 void DeleteAllXSubTree(BiTree &T, ElemType e) void DeleteAllXSubTreeRun(BiTree &T)
// P150 12 void InOrderSearchPath(BiTree T, ElemType e) stack<BiTree> SInOrderSearchPath;
// P150 14 int CalculateWidth(BiTree T)

// Search and Sort
// void Traversal(int A[], int n)
// void InsertSort(int A[], int n)
// void BinarySearch(int A[], int n, ElemType e)
// void BubbleSort(int A[], int n)
// void QuickSort(int A[], int low, int high)
// Sup int Partition(int A[], int low, int high)
// void SelectSort(int A[], int n)
// void HeapSort(int A[], int len)
// Sup void BuildHeap(int A[], int len)
// Sup void HeadAdjust(int A[], int k, int len)

int TreePre[8] = {1, 2, 4, 5, 7, 3, 6, 8};
int TreeIn[8] = {4, 2, 7, 5, 1, 6, 8, 3};
int TreePost[8] = {4, 7, 5, 2, 8, 6, 3, 1};

//                  1
//                /   \
//               2     3
//              / \    /
//             4   5  6
//                 /   \
//                7     8

int numsSort[9] = {0, 49, 38, 65, 97, 76, 13, 27, 49};  // index 0 is shaobing
int numsSearch[9] = {0, 12, 16, 28, 46, 52, 54, 63, 78};    // index 0 is not exist

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <queue>
#include <stack>
#define ElemType int
#define MaxSize 100
using namespace std;

typedef struct LNode {
    ElemType Data;
    struct LNode *Next;
} LNode, *LinkList;

LinkList HeadInsert(LinkList &L){
    L = (LNode *)malloc(sizeof(LNode));
    L->Next = NULL;
    ElemType e;
    scanf("%d", &e);
    while (e != 9999) {
        LNode *S = (LNode *)malloc(sizeof(LNode));
        S->Data = e;
        S->Next = L->Next;
        L->Next = S;
        scanf("%d", &e);
    }
    return L;
}

LinkList TailInsert(LinkList &L){
    L = (LNode *)malloc(sizeof(LNode));
    LNode *p = L;
    ElemType e;
    scanf("%d", &e);
    while (e != 9999) {
        LNode *S = (LNode *)malloc(sizeof(LNode));
        S->Data = e;
        p->Next = S;
        p = p->Next;
        scanf("%d", &e);
    }
    p->Next = NULL;
    return L;
}

bool Insert(LinkList &L, int i, ElemType e){
    if (i < 1) return false;
    int j = 0;
    LinkList pre = L;
    while (pre && j < i - 1) {
        pre = pre->Next;
        j++;
    }
    if (pre == NULL) return false;
    LNode *S = (LNode *)malloc(sizeof(LNode));
    S->Data = e;
    S->Next = pre->Next;
    pre->Next = S;
    return true;
}

bool Delete(LinkList &L, int i, ElemType &e){
    if (i < 1) return false;
    int j = 0;
    LinkList pre = L;
    while (pre->Next && j < i - 1) {
        pre = pre->Next;
        j++;
    }
    if (pre->Next == NULL) return false;
    LNode *S = pre->Next;
    e = S->Data;
    pre->Next = S->Next;
    free(S);
    return true;
}

void Traversal(LinkList L){
    LinkList p = L->Next;
    while (p) {
        printf("%d\t", p->Data);
        p = p->Next;
    }
    printf("\n");
}

int Length(LinkList L){
    LinkList p = L->Next;
    int count = 0;
    while (p) {
        count++;
        p = p->Next;
    }
    return count;
}

typedef struct CNode {
    ElemType Data;
    struct CNode *Next;
} CNode, *CLinkList;

CLinkList TailInsert(CLinkList &L){
    L = (CLinkList)malloc(sizeof(CNode));
    L->Next = L;
    CNode *p = L;
    ElemType e;
    scanf("%d", &e);
    while (e != 9999) {
        CNode *S = (CNode *)malloc(sizeof(CNode));
        S->Data = e;
        S->Next = p->Next;
        p->Next = S;
        p = p->Next;
        scanf("%d", &e);
    }
    return L;
}

void Traversal(CLinkList L){
    CLinkList p = L->Next;
    while (p != L) {
        printf("%d\t", p->Data);
        p = p->Next;
    }
    printf("\n");
}

typedef struct CDNode {
    ElemType Data;
    struct CDNode *Prior, *Next;
} CDNode, *CDLinkList;

CDLinkList TailInsert(CDLinkList &L){
    L = (CDNode *)malloc(sizeof(CDNode));
    L->Prior = L;
    L->Next = L;
    CDNode *p = L;
    ElemType e;
    scanf("%d", &e);
    while (e != 9999) {
        CDNode *S = (CDNode *)malloc(sizeof(CDNode));
        S->Data = e;
        S->Next = p->Next;
        p->Next = S;
        S->Prior = p;
        S->Next->Prior = S;
        p = p->Next;
        scanf("%d", &e);
    }
    return L;
}

void Traversal(CDLinkList L){
    CDLinkList p = L->Next;
    while (p != L) {
        printf("%d\t", p->Data);
        p = p->Next;
    }
    printf("\n");
}

typedef struct SqStack{
    ElemType Data[MaxSize];
    int top;
} SqStack;

void Init(SqStack &S){
    S.top = -1;
}

bool Push(SqStack &S, ElemType e){
    if (S.top == MaxSize - 1) return false;
    S.top++;
    S.Data[S.top] = e;
    return true;
}

bool Pop(SqStack &S, ElemType &e){
    if (S.top == -1) return false;
    e = S.Data[S.top--];
    return true;
}

bool GetTop(SqStack S, ElemType &e){
    if (S.top == -1) return false;
    e = S.Data[S.top];
    return true;
}

bool IsEmpty(SqStack S){
    if (S.top == -1) return true;
    else return false;
}

typedef struct SqQueue {
    ElemType Data[MaxSize];
    int front;
    int rear;
} SqQueue;

void Init(SqQueue &Q){
    Q.front = Q.rear = 0;
}

bool EnQueue(SqQueue &Q, ElemType e){
    if ((Q.rear + 1) % MaxSize == Q.front) return false;
    Q.Data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

bool DeQueue(SqQueue &Q, ElemType &e){
    if (Q.front == Q.rear) return false;
    e = Q.Data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

bool IsEmpty(SqQueue Q){
    if (Q.front == Q.rear) return true;
    else return false;
}

typedef struct BiTNode {
    ElemType Data;
    struct BiTNode *Left, *Right;
} BiTNode, *BiTree;

void LevelOrderTraversal(BiTree T){
    queue<BiTree> Q;
    Q.push(T);
    BiTree t;
    while (Q.empty() != true) {
        t = Q.front();
        Q.pop();
        printf("%d ", t->Data);
        if (t->Left) Q.push(t->Left);
        if (t->Right) Q.push(t->Right);
    }
}

void PreOrderTraversal(BiTree T){
    if (T) {
        printf("%d ", T->Data);
        PreOrderTraversal(T->Left);
        PreOrderTraversal(T->Right);
    }
}

void InOrderTraversal(BiTree T){
    if (T) {
        InOrderTraversal(T->Left);
        printf("%d ", T->Data);
        InOrderTraversal(T->Right);
    }
}

void PostOrderTraversal(BiTree T){
    if (T) {
        PostOrderTraversal(T->Left);
        PostOrderTraversal(T->Right);
        printf("%d ", T->Data);
    }
}

void RecursiveDeleteAllX(LinkList &L, ElemType x){
    if (L == NULL) return;
    if (L->Data == x) {
        LNode *p = L;
        L = L->Next;
        free(p);
        RecursiveDeleteAllX(L, x);
    }else {
        RecursiveDeleteAllX(L->Next, x);
    }
}

void DeleteALLX(LinkList &L, ElemType x){
    LinkList pre = L;
    LinkList p = L->Next;
    while (p) {
        if (p->Data == x) {
            pre->Next = p->Next;
            free(p);
            p = pre->Next;
        }else {
            pre = pre->Next;
            p = p->Next;
        }
    }
}

void ReversePrint(LinkList L){
    if (L->Next) ReversePrint(L->Next);
    if (L != NULL) printf("%d\t", L->Data);
}

void DeleteMin(LinkList &L){
    LinkList pre = L;
    LinkList p = L->Next;
    LNode *preMin = L;
    LNode *pMin = p;
    while (p) {
        if (p->Data < pMin->Data) {
            pMin = p;
            preMin = pre;
        }
        pre = pre->Next;
        p = p->Next;
    }
    preMin->Next = pMin->Next;
    free(pMin);
}

void Reverse(LinkList &L){
    LinkList p = L->Next;
    L->Next = NULL;
    while (p) {
        LNode *S = p;
        p = p->Next;
        S->Next = L->Next;
        L->Next = S;
    }
}

void Sort(LinkList &L){
    LinkList p = L->Next;
    L->Next = NULL;
    while (p) {
        LNode *pre = L;
        while (pre->Next && pre->Next->Data < p->Data) {
            pre = pre->Next;
        }
        LNode *S = p;
        p = p->Next;
        S->Next = pre->Next;
        pre->Next = S;
    }
}

void DeleteAllStoT(LinkList &L, ElemType S, ElemType T){
    LinkList pre = L;
    LNode *p = L->Next;
    while (p) {
        if (p->Data >= S && p->Data <= T) {
            pre->Next = p->Next;
            free(p);
            p = pre->Next;
        }else {
            pre = pre->Next;
            p = p->Next;
        }
    }
}

LinkList SearchCommonNode(LinkList A, LinkList B){
    int lenA = Length(A);
    int lenB = Length(B);
    LinkList pA = A->Next;
    LinkList pB = B->Next;
    for ( ; lenA > lenB; lenA--) pA = pA->Next;
    for ( ; lenA < lenB; lenB--) pB = pB->Next;
    while (pA && pB && pA != pB) {
        pA = pA->Next;
        pB = pB->Next;
    }
    return pA;
}

void ConnectTwoLinkList(LinkList &A, LinkList &B, int i){
    // Connect the tail of B to ith of A
    LinkList pA = A;
    LinkList pB = B;
    while (pB->Next) pB = pB->Next;
    int j = 0;
    while (j < i && pA) {
        j++;
        pA = pA->Next;
    }
    pB->Next = pA;
}

void AscendingPrintAndDelele(LinkList &L){
    LNode *pre; LNode *p;
    LNode *preMin; LNode *pMin;
    while (L->Next) {
        pre = L; p = L->Next;
        preMin = L; pMin = L->Next;
        while (p) {
            if (p->Data < pMin->Data) {
                pMin = p;
                preMin = pre;
            }
            pre = pre->Next;
            p = p->Next;
        }
        printf("%d\t", pMin->Data);
        preMin->Next = pMin->Next;
        free(pMin);
    }
    free(L);
}

void Seperate(LinkList &A, LinkList &B){
    LinkList p = A->Next;
    LinkList pA = A;
    LinkList pB = B;
    LNode *S;
    bool flag = false;
    while (p) {
        S = p;
        p = p->Next;
        if (flag == false) {
            pA->Next = S;
            pA = pA->Next;
            flag = true;
        }else {
            pB->Next = S;
            pB = pB->Next;
            flag = false;
        }
    }
    pA->Next = NULL;
    pB->Next = NULL;
}

void Seperate(LinkList &C, LinkList &A, LinkList &B){
    LinkList pC = C->Next;
    LinkList pA = A;
    LinkList pB = B;
    B->Next = NULL;
    LNode *S;
    bool flag = false;
    while (pC) {
        S = pC;
        pC = pC->Next;
        if (flag == false) {
            pA->Next = S;
            pA = pA->Next;
            flag = true;
        }else {
            S->Next = pB->Next;
            pB->Next = S;
            flag = false;
        }
    }
    pA->Next = NULL;
}

void DelelteCommon(LinkList &L){
    LNode *pre = L;
    LNode *p = L->Next;
    LNode *S;
    while (p) {
        if (p->Data == pre->Data) {
            S = p;
            pre->Next = p->Next;
            free(S);
            p = pre->Next;
        }else {
            pre = pre->Next;
            p = p->Next;
        }
    }
}

LinkList MergeAscendToNoAscend(LinkList &A, LinkList &B){
    LinkList pA = A->Next;
    LinkList pB = B->Next;
    LinkList p = A;
    p->Next = NULL;
    LNode *S;
    while (pA && pB) {
        if (pA->Data <= pB->Data) {
            S = pA;
            pA = pA->Next;
        }else {
            S = pB;
            pB = pB->Next;
        }
        S->Next = p->Next;
        p->Next = S;
    }
    while (pA) {
        S = pA;
        pA = pA->Next;
        S->Next = p->Next;
        p->Next = S;
    }
    while (pB) {
        S = pB;
        pB = pB->Next;
        S->Next = p->Next;
        p->Next = S;
    }
    return A;
}

void CommonNodeToNewList(LinkList A, LinkList B, LinkList &C){
    LinkList pA = A->Next;
    LinkList pB = B->Next;
    LinkList pre = C;
    while (pA && pB) {
        if (pA->Data < pB->Data) pA = pA->Next;
        else if (pA->Data > pB->Data) pB = pB->Next;
        else {
            LNode *S = (LNode *)malloc(sizeof(LNode));
            S->Data = pA->Data;
            S->Next = NULL;
            pre->Next = S;
            pre = pre->Next;
            pA = pA->Next;
            pB = pB->Next;
        }
    }
}

bool IsSub(LinkList A, LinkList B){
    LinkList pA = A->Next;
    LinkList p;
    LinkList pB = B->Next;
    while (pA && pB) {
        p = pA;
        pA = pA->Next;
        pB = B->Next;
        while (p && pB && p->Data == pB->Data) {
            p = p->Next;
            pB = pB->Next;
        }
    }
    if (pB == NULL) return true;
    else return false;
}

bool IsSymmetric(CDLinkList L){
    CDLinkList p = L->Next;
    CDLinkList q = L->Prior;
    bool flag = true;
    while (p != q && q->Next != p) {
        if (p->Data != q->Data) flag = false;
        p = p->Next;
        q = q->Prior;
    }
    return flag;
}

void ConnectTwoCLinkList(CLinkList &A, CLinkList &B){
    CNode *p = A->Next;
    while (p->Next != A) p = p->Next;
    p->Next = B->Next;
    CNode *q = B->Next;
    while (q->Next != B) q = q->Next;
    q->Next = A;
    free(B);
}

void DeleteMinAndPrintToNULL(LinkList &L){
    // yuan ti shi CLinkList, xie cheng LinkList le
    LNode *pre, *p, *preMin, *pMin;
    while (L->Next) {
        pre = L; p = L->Next;
        preMin = L; pMin = L->Next;
        while (p) {
            if (p->Data < pMin->Data) {
                pMin = p;
                preMin = pre;
            }
            pre = pre->Next;
            p = p->Next;
        }
        printf("%d\t", pMin->Data);
        preMin->Next = pMin->Next;
        free(pMin);
    }
    free(L);
}

void SearchReverseKthAndPrint(LinkList L, int k){
    LNode *p = L;
    int i = 0;
    while (p && i < k) {
        p = p->Next;
        i++;
    }
    if (p == NULL) return;
    LNode *q = L;
    while (p) {
        p = p->Next;
        q = q->Next;
    }
    printf("%d\n", q->Data);
}

void DeleteRestAbsoluteData(LinkList &L, int n){
    ElemType *Hash = (ElemType *)malloc((n + 1) * sizeof(ElemType));
    for (int i = 0; i <= n; i++) Hash[i] = 0;
    LNode *pre = L;
    LNode *p = L->Next;
    while (p) {
        if (Hash[abs(p->Data)] == 1) {
            pre->Next = p->Next;
            free(p);
            p = pre->Next;
        }else {
            Hash[abs(p->Data)] = 1;
            pre = pre->Next;
            p = pre->Next;
        }
    }
}

LinkList SearchCirleEnterNode(LinkList L){
    LNode *p = L;
    LNode *q = L;
    while (p != NULL && q->Next != NULL) {
        p = p->Next;
        q = q->Next->Next;
        if (p == q) break;
    }
    if (p == NULL || q == NULL) return NULL;
    LNode *s = L;
    LNode *t = p;
    while (s != t) {
        s = s->Next;
        t = t->Next;
    }
    return s;
}

void ConnectTailWithith(LinkList &L, int i){
    LNode *p = L;
    LNode *q;
    int count = 0;
    while (count < i && p) {
        count++;
        p = p->Next;
    }
    q = p;
    while(q->Next) q = q->Next;
    q->Next = p;
    printf("Connect: %d with %d\n", q->Data, p->Data);
}

void IDontKnowThisFunctionName(LinkList &L){
    LNode *p = L;
    LNode *q = L;
    while (q->Next != NULL) {
        p = p->Next;
        q = q->Next;
        if (q->Next != NULL) q = q->Next;
    }
    q = p->Next;
    p->Next = NULL;
    LNode *s;
    while (q) {
        s = q;
        q = q->Next;
        s->Next = p->Next;
        p->Next = s;
    }
    q = p->Next;
    p->Next = NULL;
    p = L->Next;
    while (q) {
        s = q;
        q = q->Next;
        s->Next = p->Next;
        p->Next = s;
        p = p->Next->Next;
    }
}

bool IsSymmetric(LinkList L, int n){
    ElemType S[n];
    int top = -1;
    int i = 0;
    LNode *p = L->Next;
    while (p && i < n / 2) {
        i++;
        S[++top] = p->Data;
        p = p->Next;
    }
    if (n % 2 == 1) p = p->Next;
    while (p && top != -1) {
        if (p->Data != S[top]) return false;
        p = p->Next;
        top--;
    }
    if (p || top != -1) return false;
    else return true;
}

int OperatorPriority(char c){
    if (c == '*' || c == '/') return 2;
    else return 1;
}

void InConvertPost(char A[]){
    // result is right, but bug, I dont know why
    char S[MaxSize];
    int top = -1;
    for (int i = 0; A[i] != '\0'; i++) {
        if (A[i] >= '0' && A[i] <= '9') {
            printf("%c", A[i]);
        }else {
            if (A[i] == '(') S[++top] = A[i];
            else if (A[i] == ')') {
                while (S[top] != '(' && top != -1) {
                    printf("%c", S[top--]);
                }
                top--;
            }else {
                while (top != -1 && OperatorPriority(S[top]) >= OperatorPriority(A[i]) && S[top] !='(') {
                    printf("%c", S[top--]);
                }
                S[++top] = A[i];
            }
        }
    }
    while (top != -1) {
        printf("%c", S[top--]);
    }
    printf("\n");
}

void ReverseLevelTraversal(BiTree T){
    BiTree Q[MaxSize];
    int front = 0; int rear = 0;
    BiTree S[MaxSize];
    int top = -1;
    Q[rear++] = T;
    BiTree t;
    while (front != rear) {
        t = Q[front++];
        S[++top] = t;
        if (t->Left) Q[rear++] = t->Left;
        if (t->Right) Q[rear++] = t->Right;
    }
    while (top != -1) {
        printf("%d\t", S[top]->Data);
        top--;
    }
}

int GetHeight(BiTree T){
    if (T == NULL) return 0;
    return GetHeight(T->Left) > GetHeight(T->Right) ? GetHeight(T->Left) + 1 : GetHeight(T->Right) + 1;
}

int GetHeightNoRecursive(BiTree T){
    BiTree Q[MaxSize];
    int front = 0; int rear = 0;
    int height = 0;
    BiTree Tail = T;
    BiTree Last = NULL;
    BiTree t;
    Q[rear++] = T;
    while (front != rear) {
        t = Q[front++];
        if (t->Left) {
            Q[rear++] = t->Left;
            Last = t->Left;
        }
        if (t->Right) {
            Q[rear++] = t->Right;
            Last = t->Right;
        }
        if (t == Tail) {
            height++;
            Tail = Last;
        }
    }
    return height;
}

BiTree CreateTreePreAndIn(int Pre[], int In[], int PreLeft, int PreRight, int InLeft, int InRight){
    BiTree root = (BiTNode *)malloc(sizeof(BiTNode));
    root->Data = Pre[PreLeft];
    root->Left = root->Right = NULL;
    int i = InLeft;
    for ( ; In[i] != Pre[PreLeft]; i++);
    int leftLen = i - InLeft;
    int rightLen = InRight - i;
    if (leftLen) root->Left = CreateTreePreAndIn(Pre, In, PreLeft + 1, PreLeft + leftLen, InLeft, i - 1);
    if (rightLen) root->Right = CreateTreePreAndIn(Pre, In, PreLeft + leftLen + 1, PreRight, i + 1, InRight);
    return root;
}

bool IsCompleteBinaryTree(BiTree T){
    BiTree p = T;
    BiTree Q[MaxSize];
    int front = 0; int rear = 0;
    Q[rear++] = p;
    bool flag = false;
    while (front != rear) {
        p = Q[front++];
        if (p->Left) {
            if (flag == true) return false;
            Q[rear++] = p->Left;
        }else flag = true;
        if (p->Right) {
            if (flag == true) return false;
            Q[rear++] = p->Right;
        }else flag = true;
    }
    return true;
}

int CalculateTwoChildNode(BiTree T){
    BiTree p = T;
    BiTree Q[MaxSize];
    int front = 0; int rear = 0;
    Q[rear++] = p;
    int count = 0;
    while (front != rear) {
        p = Q[front++];
        if (p->Left && p->Right) count++;
        if (p->Left) Q[rear++] = p->Left;
        if (p->Right) Q[rear++] = p->Right;
    }
    return count;
}

void ExchangeLeftAndRight(BiTree &T){
    if (T) {
        BiTree temp = T->Left;
        T->Left = T->Right;
        T->Right = temp;
        ExchangeLeftAndRight(T->Left);
        ExchangeLeftAndRight(T->Right);
    }
}

int GetInOrderKthData(BiTree T, int k){
    int count = 0;
    stack<BiTree> S;
    BiTree p = T;
    S.push(p);
    while (p || !S.empty()) {
        if (p) {
            count++;
            S.push(p);
            if (count == k) return p->Data;
            p = p->Left;
        }else {
            p = S.top();
            S.pop();
            p = p->Right;
        }
    }
    return -1;
}

void DeleteAllXSubTreeRun(BiTree &T){
    if (T) {
        DeleteAllXSubTreeRun(T->Left);
        DeleteAllXSubTreeRun(T->Right);
        free(T);
    }
}

void DeleteAllXSubTree(BiTree &T, ElemType e){
    if (T->Data == e) {
        DeleteAllXSubTreeRun(T);
        return;
    }
    BiTree p = T;
    BiTree Q[MaxSize];
    int front = 0; int rear = 0;
    Q[rear++] = p;
    while (front != rear) {
        p = Q[front++];
        if (p->Left) {
            if (p->Left->Data == e) {
                DeleteAllXSubTreeRun(p->Left);
                p->Left = NULL;
            }else Q[rear++] = p->Left;
        }
        if (p->Right) {
            if (p->Right && p->Right->Data == e) {
                DeleteAllXSubTreeRun(p->Right);
                p->Right = NULL;
            }else Q[rear++] = p->Right;
        }
    }
}

stack<BiTree> SInOrderSearchPath;
void InOrderSearchPath(BiTree T, ElemType e){
    if (T) {
        SInOrderSearchPath.push(T);
        if (T->Data == e){
            SInOrderSearchPath.pop();
            while (!SInOrderSearchPath.empty()) {
                printf("%d\t", SInOrderSearchPath.top()->Data);
                SInOrderSearchPath.pop();
            }
            exit(0);
        }
        if (T->Left) {
            InOrderSearchPath(T->Left, e);
            SInOrderSearchPath.pop();
        }
        if (T->Right) {
            InOrderSearchPath(T->Right, e);
            SInOrderSearchPath.pop();
        }
    }
}

int CalculateWidth(BiTree T){
    BiTree p = T;
    BiTree Q[MaxSize];
    int front = 0; int rear = 0;
    Q[rear++] = p;
    int nowWidth = 0;
    int maxWidth = 1;
    BiTree last = NULL;
    BiTree right = p;
    while (front != rear) {
        p = Q[front++];
        if (p->Left) {
            Q[rear++] = p->Left;
            nowWidth++;
            last = p->Left;
        }
        if (p->Right) {
            Q[rear++] = p->Right;
            nowWidth++;
            last = p->Right;
        }
        if (p == right) {
            if (nowWidth > maxWidth) maxWidth = nowWidth;
            nowWidth = 0;
            right = last;
        }
    }
    return maxWidth;
}

void Traversal(int A[], int n){
    for (int i = 1; i <= n; i++) {
        printf("%d\t", A[i]);
    }
    printf("\n");
}

void InsertSort(int A[], int n){
    int i, j;
    for (i = 2; i <= n; i++) {
        if (A[i] < A[i - 1]) {
            A[0] = A[i];
            for (j = i - 1; A[j] > A[0]; j--) {
                A[j + 1] = A[j];
            }
            A[j + 1] = A[0];
        }
    }
}

void BinarySearch(int A[], int n, ElemType e){
    int left = 1; int right = n;
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (A[mid] == e) {
            printf("OK\t%d\n", mid);
            return;
        }else if (A[mid] > e) right = mid - 1;
        else left = mid + 1;
    }
    printf("Not Found\nLeft:%d\tRight:%d\n", left, right);
}

void BubbleSort(int A[], int n){
    bool flag;
    for (int i = 1; i <= n - 1; i++) {
        flag = false;
        for (int j = n; j > i; j--) {
            if (A[j - 1] > A[j] ) {
                swap(A[j - 1], A[j]);
                flag = true;
            }
        }
//        Traversal(A, n);
        if (flag == false) break;
    }
}

int Partition(int A[], int low, int high){
    int pivot = A[low];
    while (low < high) {
        while (low < high && A[high] >= pivot) high--;
        A[low] = A[high];
        while (low < high && A[low] <= pivot) low++;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

void QuickSort(int A[], int low, int high){
    if (low < high) {
        int pivotIndex = Partition(A, low, high);
        QuickSort(A, low, pivotIndex - 1);
        QuickSort(A, pivotIndex + 1, high);
    }
}

void SelectSort(int A[], int n){
    for (int i = 1; i <= n; i++) {
        int minIndex = i;
        for (int j = i + 1; j <= n; j++) {
            if (A[j] < A[minIndex]) minIndex = j;
        }
        swap(A[i], A[minIndex]);
    }
}

void HeadAdjust(int A[], int k, int len){
    A[0] = A[k];
    for (int i = k * 2; i <= len; i *= 2) {
        if (i + 1 <= len && A[i + 1] > A[i]) i++;
        if (A[0] >= A[i]) break;
        else {
            A[k] = A[i];
            k = i;
        }
    }
    A[k] = A[0];
}

void BuildHeap(int A[], int len){
    for (int i = len / 2; i >= 1; i--) {
        HeadAdjust(A, i, len);
    }
}

void HeapSort(int A[], int len){
    BuildHeap(A, len);
    for (int i = len; i > 1; i--) {
        swap(A[1], A[i]);
        HeadAdjust(A, 1, i - 1);
    }
}

int Prio(char a){
    if (a == '*' || a == '/') return 2;
    if (a == '+' || a == '-') return 1;
    return 0;
}

void InChangeToPost(char A[], int n){
//    A+B*D-C/E
//    ((A+B)*D-C)/E
    stack<char> S;
    for (int i = 0; i < n; i++) {
        if (A[i] >= 'A' && A[i] <= 'Z') printf("%c", A[i]);
        else if (A[i] == '(') S.push(A[i]);
        else if (A[i] == ')') {
            while (!S.empty() && S.top() != '(') {
                printf("%c", S.top());
                S.pop();
            }
            S.pop();
        }else {
            while (!S.empty() && Prio(A[i]) <= Prio(S.top())) {
                printf("%c", S.top());
                S.pop();
            }
            S.push(A[i]);
        }
    }
    while (!S.empty()) {
        printf("%c", S.top());
        S.pop();
    }
}



int main(){
    
}
