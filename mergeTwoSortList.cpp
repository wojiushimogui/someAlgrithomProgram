/*
合并两个排序的链表 
*/

#include<stdio.h>
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

ListNode* merge2sortList(ListNode *pHead1,ListNode *pHead2){
	
	if(pHead1==NULL){
		return pHead2;
	}
	if(pHead2==NULL){
		return pHead1;
	}
	//第三种情况：两个链表都有节点
	//从头往后开始扫描
	ListNode *cur1=pHead1;
	ListNode *cur2=pHead2;
	while(pHead1->pNext!=NULL&&pHead2->pNext!=NULL){
		if(cur1->mValue>)
		
	} 
	
}

int main(void){
	ListNode *pHead1=createList();
	printList(pHead1);
	ListNode  *pHead2=createList(); 
	printList(pHead2);
	
	ListNode *pHead1=merge2sortList(pHead1,pHead2); 
	
	
	return 0;
}
