#include<stdio.h>  
#include<stdlib.h>  
  
typedef int ElemType;  
  
 struct Node  
{  
    ElemType mValue;  
    struct Node *mpNext;  
};  
  
/* 
递归从尾到头打印单链表 
*/  
void PrintListReverse(Node* pHead)  
{  
    if(pHead == NULL)  
        return;  
    if(pHead->mpNext != NULL)  
        PrintListReverse(pHead->mpNext);  
    printf("%d\n",pHead->mValue);  
}  
  
Node* CreateList()  
{  
    ElemType val;  
    Node* pHead = NULL;  
    Node* pCur = NULL;  
    do  
    {  
        scanf("%d",&val);  
        if(val != -1)  
        {  
            Node* pNew = (Node*)malloc(sizeof(Node));  
            if(pNew == NULL)  
                exit(EXIT_FAILURE);  
            pNew->mValue = val;  
            pNew->mpNext = NULL;  
  
            if(pHead == NULL)  
            {  
                pHead = pNew;  
                pCur = pHead;  
            }  
            else  
            {  
                pCur->mpNext = pNew;  
                pCur = pCur->mpNext;  
            }  
        }  
    }while(val != -1);  
  
    return pHead;  
}  
  
void DestroyList(Node* pHead)  
{  
    if(pHead == NULL)  
        return;  
    Node* p = NULL;  
    while(pHead != NULL)  
    {  
        p = pHead->mpNext;  
        free(pHead);  
        pHead = p;  
    }  
}  
int main()  
{  
    Node* pHead = CreateList();  
    PrintListReverse(pHead);  
    DestroyList(pHead);  
    return 0;  
} 
