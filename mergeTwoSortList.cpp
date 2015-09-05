/*
�ϲ�������������� 

���ǵĲ����������£�
1����������������һ��Ϊ������
2�����������ж��нڵ� 
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

ListNode* merge2sortList(ListNode *pHead1,ListNode *pHead2){
	
	if(pHead1==NULL){
		return pHead2;
	}
	if(pHead2==NULL){
		return pHead1;
	}
	//��������������������нڵ�
	//��ͷ����ʼɨ��
	ListNode *cur1;
	ListNode *cur2;
	ListNode *next1;
	ListNode *next2;
	//�ȱȽ�����������׽ڵ㣬�׽ڵ�С���Ǹ�������Ϊ��������������һ�������еĽڵ��������
	//��cur1Ϊָ���������ָ�룬cur2Ϊָ�򼴽����뵽�������е����� 
	if(pHead1->mValue<=pHead2->mValue){
		cur1=pHead1;
		cur2=pHead2; 
	} 
	else{
		cur1=pHead2;
		cur2=pHead1;
	}
	ListNode *pHead=cur1;//���淵�������ͷ��� 
	while(cur1->pNext!=NULL&&cur2->pNext!=NULL){
		//���浱ǰ������һ���ڵ��ָ�� 
		next1=cur1->pNext;
		next2=cur2->pNext; 
		if(cur1->mValue<=cur2->mValue&&cur1->pNext->mValue>cur2->mValue){//�ҵ�cur2Ҫ�����λ�� 
			cur1->pNext=cur2;
			cur2->pNext=next1;
			cur1=cur1->pNext; //ֻ����cur1=cur1->pNext��������cur1=next1 
			cur2=next2;
		}
		else {
			cur1=cur1->pNext; 
		}
		
		 
	} 
	
	//��������������������Ӻ�����������������һ��������β�ڵ���߱�������������������һ���ڵ�����
	if(cur1->pNext==NULL){//��ʱ�������Ѿ������������һ��Ԫ�� �����磺1 3 5 7 ��2 4 6 8 9 10 ,ֻ��Ҫ��cur2����cur1->pNext���� 
		cur1->pNext=cur2; 
	}
	if(cur2->pNext==NULL){//��ʱ�ڶ��������������һ��Ԫ�أ�����  1 3 5 7��4����ʱֻҪ���ڶ�����������һ��Ԫ�ز��뵽���ʵ�λ�ü���
		while(cur1->pNext!=NULL){
			next1=cur1->pNext;
			if(cur1->mValue<=cur2->mValue&&cur1->pNext->mValue>cur2->mValue){
				cur1->pNext=cur2;
				cur2->pNext=next1;
				cur1=cur1->pNext; //ֻ����cur1=cur1->pNext��������cur1=next1 
				break;
			}
			cur1=cur1->pNext;
		} 
		
		//������1 3 5 7 �� 9�������ʱ���������whileѭ���²�û�н��ڵ� 9 �����ȥ����˻���Ҫ����
		cur1->pNext=cur2;
		
	}
	return  pHead; 
	
}

int main(void){
	ListNode *pHead1=createList();
	printList(pHead1);
	ListNode  *pHead2=createList(); 
	printList(pHead2);
	
	ListNode *pHead=merge2sortList(pHead1,pHead2); 
	
	printList(pHead);
	
	
	return 0;
}
