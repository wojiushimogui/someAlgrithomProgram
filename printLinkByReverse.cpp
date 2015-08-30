/*
题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值 
思路：将链表的指针全部反向，然后输出即可 
*/

#include<stdio.h>
#include<string.h>
#include <stdlib.h> 
typedef int  ElemType;
struct ListNode{
	ElemType mValue;
	ListNode *mpNext;
};

//向链表尾部添加新的结点
ListNode* addNodeToTailInList(ListNode *pHead,int value){
	//根据value构造一个新的结点 
	//ListNode *pNew=new ListNode();
	ListNode *pNew;
	pNew=(ListNode *)malloc(sizeof(struct ListNode));
	pNew->mValue=value;
	pNew->mpNext=NULL; 
	//如果*pHead 为空，则新结点就为头结点 
	if(pHead==NULL){
		pHead=pNew;
		
	}
	ListNode  *temp=pHead;
	while(temp->mpNext!=NULL){
		temp=temp->mpNext;
	} 
	
	temp->mpNext=pNew;
	return pHead;
	
} 

//输入一个链表的头结点，反向链表 
//@param  pHead  :头结点的指针 
ListNode* reverseList(ListNode *pHead){
	if(pHead==NULL) {
		return NULL;
		
	}
	ListNode *cur=pHead; 
	ListNode *pre=NULL;
	ListNode *next;
	while(cur->mpNext!=NULL){
		next=cur->mpNext;//先把当前结点下一个节点保存起来,作为下一次循环的位置 
		cur->mpNext=pre;
		pre=cur;
		cur=next; 
	} 
	cur->mpNext=pre;//将最后一个节点反向链接 
	pHead=cur; //将最后一个节点变为头结点 
	
	return pHead;
}
void printList(ListNode* pHead){
	if(pHead==NULL){
		return ;
	}
	ListNode *curNode=pHead;
	while(curNode->mpNext!=NULL){
		
		printf("%d",curNode->mValue);
		curNode=curNode->mpNext;
	}
	printf("%d",curNode->mValue);//输出最后一个节点的信息 
	printf("\n");
	
	
}
ListNode* createList()  
{  
    ElemType value;  
    ListNode* pHead = NULL;  
    ListNode* pCur = NULL;  
    do  
    {  
        scanf("%d",&value);  
        if(value != -1)  
        {  
            ListNode *pNew = (ListNode*)malloc(sizeof( ListNode));  
            if(pNew == NULL)  
                exit(EXIT_FAILURE);  
            pNew->mValue = value;  
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
    }while(value != -1);  
  
    return pHead;  
}  
int main(void){
	//先构造结点数为N的链表
	ListNode *pHead;
	ElemType value;

	pHead=createList();
	//输出正序列表的信息 
	printList(pHead); 
	pHead=reverseList(pHead);
	//输入一个链表的头结点，从尾到头反过来打印出每个结点的值 
	printList(pHead); //反向输出 
	
	return 0;
}
