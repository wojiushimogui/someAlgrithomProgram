/*
反转链表 
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef int ElementType;
//定义一个结构体 
struct ListNode{
	ElementType mValue;
	ListNode *pNext;
}; 
ListNode *createList(){
	ListNode *pHead=NULL;
	
	ElementType val;
	scanf("%d",&val);
	while(val!=-1){
		ListNode *pCurrentNode;
		ListNode *pNewNode;
		pNewNode=(ListNode *)malloc(sizeof(pNewNode));
		if(pNewNode==NULL){
			exit(EXIT_FAILURE);
		}
		pNewNode->mValue=val;
		pNewNode->pNext=NULL;
		if(pHead==NULL){
			pHead=pNewNode;
			pCurrentNode=pHead;
		
		}
		else{
			pCurrentNode->pNext=pNewNode;
			pCurrentNode=pNewNode;
		}
		
	scanf("%d",&val);	
		
	}
	return pHead; 
}
ListNode* reverseList(ListNode * pHead){
	if(pHead==NULL){//先检查下头结点是否有效 
		return NULL;
	}
	ListNode *preNode=NULL;
	ListNode *currNode=pHead;
	ListNode *next;
	while(currNode->pNext!=NULL){
		next=currNode->pNext;
		currNode->pNext=preNode;
		preNode=currNode; 
		
		currNode=next;
	}
	//反转最后一个结点
	pHead=currNode;
	currNode->pNext=preNode; 
	 
	return pHead;
}
void printList(ListNode *pHead){
	if(pHead==NULL){
		return ;
	}
	while(pHead->pNext!=NULL){
		printf("  %d  ",pHead->mValue);
		pHead=pHead->pNext;
	}
	//输出最后一个结点
	printf("  %d\n ",pHead->mValue); 
}
int main(void){
	//第一步：在反转链表之前，先创建链表
	ListNode *pHead=createList(); 
	//为便于观察链表的结点，因此写一个输出链表的函数
	
	printList(pHead); 
	 
	//第二步：反转链表
	pHead=reverseList(pHead); 
	
	printList(pHead);
	 
	return 0;
} 
