/*
在O(1)时间删除链表结点 
题目：给定单向链表的头指针和一个结点指针，定义一个函数在 O(1)时间删除链表结点 

方法就是：删除该节点的下一个节点，然后改变该节点的value值即可 ，这种效果就类似于删除了该节点 


要删除的节点会可能会出现的位置如下：
	1、是最后一个节点
		1）链表为多个结点时的最后一个节点 
		2） 链表为一个节点时的最后一个节点
	2、不是最后一个节点 
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

ListNode * randomProduceNodePointer(ListNode *pHead){
	
	if(pHead==NULL){
		return NULL;
	}
	ListNode *temp=pHead;
	int num=1;//统计链表中的节点数量 
	while(temp->pNext!=NULL){
		num++;
		temp=temp->pNext;
	}
	int index=rand()%num;
	
	ListNode *curNode=pHead;
	while(index>0){
		curNode=curNode->pNext;
		index--;
	}
	
	return curNode;
}

void deleteListNode(ListNode *pHead,ListNode* pNode){
	
	if(pHead==NULL||pNode==NULL){
		return;
	}
	/*
	要删除的节点会可能会出现的位置如下：
	1、是最后一个节点
		1）链表为多个结点时的最后一个节点 
		2） 链表为一个节点时的最后一个节点
	2、不是最后一个节点 
	*/ 
	if(pNode->pNext!=NULL){//如果删除节点不是最后一个节点时 
		ListNode *next=pNode->pNext;	
		ElementType value=next->mValue;//保存下一个节点的value 
		pNode->pNext=pNode->pNext->pNext;
		pNode->mValue=value; 
		free(next);
		//delete[] next;
		next=NULL;
	}
	else if(pHead==pNode){//链表为一个节点时，删除的是最后一个节点
		
	//	delete[] pNode;
		free(pNode);
		pNode=NULL;
		pHead=NULL;//由于表中只有一个节点，因此也要将头结点设置为NULL 
		
	} 
	else{//链表为多个结点时，删除的是最后一个节点
		//此时只能遍历整个链表
		
		ListNode *curNode=pHead;
		if(curNode->pNext!=pNode){
			curNode=curNode->pNext;
		}
		
		curNode->pNext=NULL;
		free(pNode);
	//	delete[] pNode;
		pNode=NULL; 
				 
	}

	
}


int main(void){
	//创建链表 
	int i=5;
	while(i>0){
		ListNode *pHead=createList();
		printList(pHead);
		//随机返回链表中的某个节点的指针作为删除节点	
		ListNode *pNode=randomProduceNodePointer(pHead); 
		
		printf("%d\n",pNode->mValue);
		//删除节点 
		deleteListNode(pHead,pNode); 
		printList(pHead);
		
		i--;
	}
	
	
	return 0;
}
