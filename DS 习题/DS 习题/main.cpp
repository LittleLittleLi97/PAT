#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <stack>
#define ElemType int
using namespace std;

// P19 1 void DeleteMin(LinkList &L);
// P19 6 void DeleteSame(SqList &L);
// P20 9 void BinarySearch_ExchangeOrInsert(ElemType L[], int n, ElemType x);
// P20 10 void Reverse(int a[], int st, int ed); void Move(int R[], int n, int p);
// P20 11 int SearchMid(int S1[], int S2[], int L1, int L2);
// P20 12 int FindMainElement(int A[], int n);
// P21 13 int SearchMinNever(int A[], int n);

// P40 1 void DeleteAllx_Recursive(LinkList &L, int x);
// P40 2 void DeleteAllx(LinkList &L, int x);
// P40 3 void ReversePrint(LinkList L);
// P40 4 void DeleteMin(LinkList &L);
// P40 5 void Reverse(LinkList &L);
// P40 6 void Sort(LinkList &L);
// P40 7 void DeleteAllsTot(LinkList &L, int s, int t);
// P41 9 void PrintAscendantAndDelete(LinkList &head);
// P41 10 void Seperate(LinkList &A, LinkList &B);
// P41 11 void Seperate(LinkList &hc, LinkList &A, LinkList &B);

// P149 3 void PostOrder2(BiTree T);
// P149 5 int NoRecursiveDepth(BiTree T);
// 非递归树高 int RecursiveDepth(BiTree T);
// P149 6 BiTree PreAndInCreate(ElemType A[], ElemType B[], int preleft, int preritht, int inleft, int inright);
// P150 7 bool IsCompleteTree(BiTree T);
// P150 8 int Have_LeftAndRight_NodeNum(BiTree T);
// P150 9 void ExchangeLeftAndRight(BiTree &T);
// P150 10 ElemType KthPreOrder(BiTree T, int k);
// P150 11 void DeleteXSubTree(BiTree T, ElemType x); void DeleteTree(BiTree T);
// P150 12 void AllParentsX(BiTree T, ElemType x);

int num[10] = {1,2,3,4,5,6,7,8,9,10};
int mainElem[10] = {1,1,1,2,2,1,3,4,5,10};

int TreeLevel[8] = {1,2,3,4,5,6,7,8};
int TreePre[8] = {1,2,4,5,7,3,6,8};
int TreeIn[8] = {4,2,7,5,1,3,6,8};
int TreePost[8] = {4,7,5,2,8,6,3,1};

//                  1
//                /   \
//               2     3
//             /   \    \
//            4     5    6
//                 /      \
//                7        8

typedef struct {
    int Data[100];
    int Length;
} SqList;
SqList L;

typedef struct LNode {
    int Data;
    struct LNode *Next;
} LNode, *LinkList;

typedef struct BiTNode {
    int Data;
    struct BiTNode *Left;
    struct BiTNode *Right;
} BiTNode, *BiTree;

void Traversal(int a[], int length);

void Init(LinkList &L){
    L = (LNode *)malloc(sizeof(LNode));
    L->Next = NULL;
}

bool Insert(LinkList &L, int i, int e){
    if (i < 1) return false;
    int j = 0;
    LNode *p = L;
    while (j < i - 1 && p != NULL) {
        p = p->Next;
        j++;
    }
    if (p == NULL) return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->Data = e;
    s->Next = p->Next;
    p->Next = s;
    return true;
}

void Reverse(int a[], int st, int ed){
    while (st < ed) {
        int t = a[st];
        a[st] = a[ed];
        a[ed] = t;
        st++; ed--;
    }
}

void Reverse(LinkList &L){
    LNode *p = L->Next;
    L->Next = NULL;
    while (p != NULL) {
        LNode *s = p;
        p = p->Next;;
        s->Next = L->Next;
        L->Next = s;
    }
}

void DeleteAllx_Recursive(LinkList &L, int x){
    //递归
    // 题目没有头结点  但是貌似有没有都行
    if (L == NULL) return;
    if (L->Data == x) {
        LNode *s = L;
        L = L->Next;
        free(s);
        DeleteAllx_Recursive(L, x);
    }else DeleteAllx_Recursive(L->Next, x);
}

void DeleteAllx(LinkList &L, int x){
    LNode *p = L->Next;
    LNode *pre = L;
    while (p != NULL) {
        if (p->Data == x) {
            LNode *s = p;
            pre->Next = p->Next;
            p = p->Next;
            free(s);
        }else {
            pre = pre->Next;
            p = p->Next;
        }
    }
}

void ReversePrint(LinkList L){
    if (L->Next != NULL) ReversePrint(L->Next);
    printf("%d\t", L->Data);
}

void DeleteMin(LinkList &L){
    LNode *pre = L; LNode *p = L->Next;
    LNode *preMin = pre; LNode *minNode = p;
    while (p != NULL) {
        if (p->Data < minNode->Data) {
            minNode = p;
            preMin = pre;
        }
        pre = pre->Next;
        p = p->Next;
    }
    LNode *s = minNode;
    preMin->Next = minNode->Next;
    free(s);
}

void DeleteAllsTot(LinkList &L, int s, int t){
    LNode *p = L->Next;
    LNode *pre = L;
    while (p != NULL) {
        if (p->Data > s && p->Data < t) {
            LNode *a = p;
            p = p->Next;
            pre->Next = p;
            free(a);
        }else {
            pre = pre->Next;
            p = p->Next;
        }
    }
}

void Sort(LinkList &L){
    LNode *p = L->Next;
    L->Next = NULL;
    while (p != NULL) {
        LNode *s = p;
        p = p->Next;
        LNode *pre = L;
        while (pre->Next != NULL && s->Data > pre->Next->Data) {
            pre = pre->Next;
        }
        s->Next = pre->Next;
        pre->Next = s;
    }
}

void PrintAscendantAndDelete(LinkList &head){
    LNode *p; LNode *pre;
    while (head->Next != NULL) {
        LNode *minPre = head;
        p = head->Next;
        pre = head;
        int min = p->Data;
        while (p != NULL) {
            if (p->Data < min) {
                min = p->Data;
                minPre = pre;
            }
            p = p->Next;
            pre = pre->Next;
        }
        printf("%d\t", min);
        LNode *s = minPre->Next;
        minPre->Next = s->Next;
        free(s);
    }
    free(head);
}

void Seperate(LinkList &A, LinkList &B){
    LNode *pA = A->Next;
    LNode *preA = A;
    LNode *pB = B;
    int i = 1;
    while (pA != NULL) {
        if (i % 2 == 0) {
            LNode *s = pA;
            preA->Next = pA->Next;
            pA = pA->Next;
            pB->Next = s;
            s->Next = NULL;
            pB = pB->Next;
        }else {
            pA = pA->Next;
            preA = preA->Next;
        }
        i++;
    }
}

void Seperate(LinkList &hc, LinkList &A, LinkList &B){
    bool flag = false;
    LNode *pc = hc->Next;
    LNode *pa = A;
    LNode *pb = B;
    while (pc != NULL) {
        if (flag == false) {
            LNode *s = pc;
            pc = pc->Next;
            pa->Next = s;
            s->Next = NULL;
            pa = pa->Next;
            flag = true;
        }else {
            LNode *s = pc;
            pc = pc->Next;
            s->Next = pb->Next;
            pb->Next = s;
            flag = false;
        }
    }
}

void DeleteSame(SqList &L){
    int last = L.Data[0];
    int k = 0;
    for (int i = 1; i < L.Length; i++) {
        if (L.Data[i] == last) {
            k++;
        } else {
            L.Data[i - k] = L.Data[i];
            last = L.Data[i];
        }
    }
    L.Length -= k;
}

void BinarySearch_ExchangeOrInsert(ElemType L[], int n, ElemType x){
    int i = 0;
    int j = n - 1;
    int mid = 0;
    while (i <= j) {
        mid = (i + j) / 2;
        if (L[mid] == x) break;
        else if (L[mid] < x) i = mid + 1;
        else j = mid - 1;
    }
    if (L[mid] == x){
        if (mid + 1 >= n) return;
        ElemType temp = L[mid];
        L[mid] = L[mid + 1];
        L[mid + 1] = temp;
        return;
    }
    if (L[mid] != x){
        for (int p = n; p >= i; p--) L[p + 1] = L[p];
        L[i] = x;
        return;
    }
}

void Move(int R[], int n, int p){
    Reverse(R, 0, n - 1);
    Reverse(R, 0, n - 1 - p);
    Reverse(R, n - p, n - 1);
}

int SearchMid(int S1[], int S2[], int L1, int L2){
    int Mid;
    if ((L1 + L2) % 2 == 0) Mid = (L1 + L2) / 2;
    else Mid = (L1 + L2) / 2 + 1;
    int last = 0;
    int p1 = 0; int p2 = 0;
    int count = 0;
    while (count < Mid && p1 < L1 && p2 < L2) {
        if (S1[p1] <= S2[p2]) last = S1[p1++];
        else last = S2[p2++];
        count++;
    }
    while (count < Mid && p1 < L1) {
        last = S1[p1++];
        count++;
    }
    while (count < Mid && p2 < L2) {
        last = S2[p2++];
        count++;
    }
    return last;
}

int FindMainElement(int A[], int n){
    int *H = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) H[i] = 0;
    for (int i = 0; i < n; i++) H[A[i]]++;
    int u = 0; int max = H[0];
    for (int i = 1; i < n; i++) {
        if (H[i] > max) {
            max = H[i];
            u = i;
        }
    }
    if (max > n / 2) return u;
    else return -1;
}

int SearchMinNever(int A[], int n){
    int *H = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) H[i] = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] < 0 || A[i] >= n) continue;
        H[A[i]] = 1;
    }
    int i;
    for (i = 1; i < n; i++){
        if (H[i] == 0) break;
    }
    return i;
}

void Traversal(SqList L){
    for (int i = 0; i < L.Length; i++) {
        printf("%d\t", L.Data[i]);
    }
    printf("\n");
}

void Traversal(int a[], int length){
    for (int i = 0; i < length; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void Traversal(LinkList L){
    LNode *p = L->Next;
    while (p != NULL) {
        printf("%d\t", p->Data);
        p = p->Next;
    }
    printf("\n");
}

BiTree PreAndInCreate(ElemType A[], ElemType B[], int preleft, int preritht, int inleft, int inright){
    BiTNode *root = (BiTNode *)malloc(sizeof(BiTNode));
    root->Data = A[preleft];
    root->Left = NULL; root->Right = NULL;
    int i = inleft;
    for ( ; B[i] != root->Data; i++);
    int leftlen = i - inleft;
    int rightlen = inright - i;
    if (leftlen) root->Left = PreAndInCreate(A, B, preleft + 1, preleft + leftlen, inleft, i - 1);
    if (rightlen) root->Right = PreAndInCreate(A, B, preleft + leftlen + 1, preritht, i + 1, inright);
    return root;
}

int NoRecursiveDepth(BiTree T){
    if (T == NULL) return 0;
    int depth = 0;
    BiTree p = T;
    BiTree last = p;
    BiTree tail = p;
    queue<BiTree> Q;
    Q.push(p);
    while (Q.empty() == false) {
        p = Q.front();
        Q.pop();
        if (p->Left) {
            Q.push(p->Left);
            last = p->Left;
        }
        if (p->Right) {
            Q.push(p->Right);
            last = p->Right;
        }
        if (p == tail) {
            depth++;
            tail = last;
        }
    }
    return depth;
}

int RecursiveDepth(BiTree T){
    if (T == NULL) return 0;
    int leftdepth = RecursiveDepth(T->Left);
    int rightdepth = RecursiveDepth(T->Right);
    if (leftdepth > rightdepth) return leftdepth + 1;
    else return rightdepth + 1;
}

void PostOrder2(BiTree T){
    BiTree p = T;
    stack<BiTree> S;
    BiTree r = NULL;
    while (p || S.empty() == false) {
        if (p) {
            S.push(p);
            p = p->Left;
        }else {
            p = S.top();
            if (p->Right && p->Right != r) {
                p = p->Right;
//                S.push(p);
//                p = p->Left;
            }else {
                S.pop();
                printf("%d\t", p->Data);
                r = p;
                p = NULL;
            }
        }
    }
    printf("\n");
}

void BFS(BiTree T){
    if (T == NULL) return;
    BiTree p = T;
    queue<BiTree> Q;
    Q.push(p);
    while (Q.empty() == false) {
        p = Q.front();
        Q.pop();
        printf("%d\t", p->Data);
        if (p->Left) Q.push(p->Left);
        if (p->Right) Q.push(p->Right);
    }
    printf("\n");
}

bool IsCompleteTree(BiTree T){
    if (T == NULL) return false;
    bool flag = false;
    queue<BiTree> Q;
    BiTree p = T;
    Q.push(p);
    while (Q.empty() == false) {
        p = Q.front();
        Q.pop();
        if (p->Left) {
            if (flag == true) return false;
            else Q.push(p->Left);
        }else flag = true;
        if (p->Right) {
            if (flag == true) return false;
            else Q.push(p->Right);
        }else flag = true;
    }
    return true;
}

int Have_LeftAndRight_NodeNum(BiTree T){
    if (T == NULL) return 0;
    int num = 0;
    queue<BiTree> Q;
    BiTree p = T;
    Q.push(p);
    while (Q.empty() == false) {
        p = Q.front();
        Q.pop();
        if (p->Left && p->Right) num++;
        if (p->Left) Q.push(p->Left);
        if (p->Right) Q.push(p->Right);
    }
    return num;
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

ElemType KthPreOrder(BiTree T, int k){
    stack<BiTree> S;
    BiTree p = T;
    int num = 0;
    BiTree result = p;
    while (p || S.empty() == false) {
        if (p) {
            num++;
            if (num == k) {
                result = p;
                break;
            }
            S.push(p);
            p = p->Left;
        }else {
            p = S.top();
            S.pop();
            p = p->Right;
        }
    }
    return result->Data;
}

void DeleteTree(BiTree T){
    if (T) {
        DeleteTree(T->Left);
        DeleteTree(T->Right);
        free(T);
    }
}

void DeleteXSubTree(BiTree T, ElemType x){
    //如果x是根结点，有bug
    if (T == NULL) return;
    if (T->Data == x) {
        DeleteTree(T);
        return;
    }
    queue<BiTree> Q;
    BiTree p = T;
    Q.push(p);
    while (Q.empty() == false) {
        p = Q.front();
        Q.pop();
        if (p->Left) {
            if (p->Left->Data == x) {
                DeleteTree(p->Left);
                p->Left = NULL;
            }else Q.push(p->Left);
        }
        if (p->Right) {
            if (p->Right->Data == x) {
                DeleteTree(p->Right);
                p->Right = NULL;
            }else Q.push(p->Right);
        }
    }
}

void AllParentsX(BiTree T, ElemType x){
    stack<BiTree> S;
    BiTree p = T;
    BiTree r = NULL;
    while (p || S.empty() == false) {
        if (p) {
            S.push(p);
            p = p->Left;
        }else {
            p = S.top();
            if (p->Right && p->Right != r) {
                p = p->Right;
                S.push(p);
                p = p->Left;
            }else {
                S.pop();
                if (p->Data == x) {
                    break;
                }
                r = p;
                p = NULL;
            }
        }
    }
    while (S.empty() == false) {
        p = S.top();
        S.pop();
        printf("%d\t", p->Data);
    }
    printf("\n");
}

int main(){
    LinkList L; Init(L);
    for (int i = 0; i < 10; i++) {
        Insert(L, 1, i);
    }
    
    
    BiTree root = PreAndInCreate(TreePre, TreeIn, 0, 7, 0, 7);
    cout << sizeof(int) << '\t' << (long int)root << endl;
    return 0;
    BiTree r = (BiTNode *)malloc(sizeof(BiTNode));
    r->Data = 1; r->Left = r->Right = NULL;
    
    int s1[8] = {2,4,6,8,10,12,14,16}; int s2[3] = {1,3,5};
    cout << SearchMid(s1, s2, 8, 3);
}
