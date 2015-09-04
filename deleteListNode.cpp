/*
��O(1)ʱ��ɾ�������� 
��Ŀ���������������ͷָ���һ�����ָ�룬����һ�������� O(1)ʱ��ɾ�������� 

�������ǣ�ɾ���ýڵ����һ���ڵ㣬Ȼ��ı�ýڵ��valueֵ���� ������Ч����������ɾ���˸ýڵ� 


Ҫɾ���Ľڵ����ܻ���ֵ�λ�����£�
	1�������һ���ڵ�
		1������Ϊ������ʱ�����һ���ڵ� 
		2�� ����Ϊһ���ڵ�ʱ�����һ���ڵ�
	2���������һ���ڵ� 
	*/ 


#include<stdio.h>
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

ListNode * randomProduceNodePointer(ListNode *pHead){
	
	if(pHead==NULL){
		return NULL;
	}
	ListNode *temp=pHead;
	int num=1;//ͳ�������еĽڵ����� 
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
	Ҫɾ���Ľڵ����ܻ���ֵ�λ�����£�
	1�������һ���ڵ�
		1������Ϊ������ʱ�����һ���ڵ� 
		2�� ����Ϊһ���ڵ�ʱ�����һ���ڵ�
	2���������һ���ڵ� 
	*/ 
	if(pNode->pNext!=NULL){//���ɾ���ڵ㲻�����һ���ڵ�ʱ 
		ListNode *next=pNode->pNext;	
		ElementType value=next->mValue;//������һ���ڵ��value 
		pNode->pNext=pNode->pNext->pNext;
		pNode->mValue=value; 
		free(next);
		//delete[] next;
		next=NULL;
	}
	else if(pHead==pNode){//����Ϊһ���ڵ�ʱ��ɾ���������һ���ڵ�
		
	//	delete[] pNode;
		free(pNode);
		pNode=NULL;
		pHead=NULL;//���ڱ���ֻ��һ���ڵ㣬���ҲҪ��ͷ�������ΪNULL 
		
	} 
	else{//����Ϊ������ʱ��ɾ���������һ���ڵ�
		//��ʱֻ�ܱ�����������
		
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
	//�������� 
	int i=5;
	while(i>0){
		ListNode *pHead=createList();
		printList(pHead);
		//������������е�ĳ���ڵ��ָ����Ϊɾ���ڵ�	
		ListNode *pNode=randomProduceNodePointer(pHead); 
		
		printf("%d\n",pNode->mValue);
		//ɾ���ڵ� 
		deleteListNode(pHead,pNode); 
		printList(pHead);
		
		i--;
	}
	
	
	return 0;
}
