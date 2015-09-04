/*
��ת���� 
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef int ElementType;
//����һ���ṹ�� 
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
	if(pHead==NULL){//�ȼ����ͷ����Ƿ���Ч 
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
	//��ת���һ�����
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
	//������һ�����
	printf("  %d\n ",pHead->mValue); 
}
int main(void){
	//��һ�����ڷ�ת����֮ǰ���ȴ�������
	ListNode *pHead=createList(); 
	//Ϊ���ڹ۲�����Ľ�㣬���дһ���������ĺ���
	
	printList(pHead); 
	 
	//�ڶ�������ת����
	pHead=reverseList(pHead); 
	
	printList(pHead);
	 
	return 0;
} 
