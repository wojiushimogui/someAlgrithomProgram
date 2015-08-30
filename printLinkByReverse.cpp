/*
��Ŀ������һ�������ͷ��㣬��β��ͷ��������ӡ��ÿ������ֵ 
˼·���������ָ��ȫ������Ȼ��������� 
*/

#include<stdio.h>
#include<string.h>
#include <stdlib.h> 
typedef int  ElemType;
struct ListNode{
	ElemType mValue;
	ListNode *mpNext;
};

//������β������µĽ��
ListNode* addNodeToTailInList(ListNode *pHead,int value){
	//����value����һ���µĽ�� 
	//ListNode *pNew=new ListNode();
	ListNode *pNew;
	pNew=(ListNode *)malloc(sizeof(struct ListNode));
	pNew->mValue=value;
	pNew->mpNext=NULL; 
	//���*pHead Ϊ�գ����½���Ϊͷ��� 
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

//����һ�������ͷ��㣬�������� 
//@param  pHead  :ͷ����ָ�� 
ListNode* reverseList(ListNode *pHead){
	if(pHead==NULL) {
		return NULL;
		
	}
	ListNode *cur=pHead; 
	ListNode *pre=NULL;
	ListNode *next;
	while(cur->mpNext!=NULL){
		next=cur->mpNext;//�Ȱѵ�ǰ�����һ���ڵ㱣������,��Ϊ��һ��ѭ����λ�� 
		cur->mpNext=pre;
		pre=cur;
		cur=next; 
	} 
	cur->mpNext=pre;//�����һ���ڵ㷴������ 
	pHead=cur; //�����һ���ڵ��Ϊͷ��� 
	
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
	printf("%d",curNode->mValue);//������һ���ڵ����Ϣ 
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
	//�ȹ�������ΪN������
	ListNode *pHead;
	ElemType value;

	pHead=createList();
	//��������б����Ϣ 
	printList(pHead); 
	pHead=reverseList(pHead);
	//����һ�������ͷ��㣬��β��ͷ��������ӡ��ÿ������ֵ 
	printList(pHead); //������� 
	
	return 0;
}
