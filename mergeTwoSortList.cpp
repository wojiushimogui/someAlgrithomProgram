/*
合并两个排序的链表 

考虑的测试用例如下：
1）两个链表至少有一个为空链表
2）两个链表中都有节点 
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
	ListNode *cur1;
	ListNode *cur2;
	ListNode *next1;
	ListNode *next2;
	//先比较两个链表的首节点，首节点小的那个链表作为主链表，即将另外一个链表中的节点插入其中
	//即cur1为指向主链表的指针，cur2为指向即将插入到主链表中的链表 
	if(pHead1->mValue<=pHead2->mValue){
		cur1=pHead1;
		cur2=pHead2; 
	} 
	else{
		cur1=pHead2;
		cur2=pHead1;
	}
	ListNode *pHead=cur1;//保存返回链表的头结点 
	while(cur1->pNext!=NULL&&cur2->pNext!=NULL){
		//保存当前结点的下一个节点的指针 
		next1=cur1->pNext;
		next2=cur2->pNext; 
		if(cur1->mValue<=cur2->mValue&&cur1->pNext->mValue>cur2->mValue){//找到cur2要插入的位置 
			cur1->pNext=cur2;
			cur2->pNext=next1;
			cur1=cur1->pNext; //只能是cur1=cur1->pNext，不能是cur1=next1 
			cur2=next2;
		}
		else {
			cur1=cur1->pNext; 
		}
		
		 
	} 
	
	//处理两个链表经上面的连接后两个链表中至少有一个链表到达尾节点或者本来两个链表中至少有一个节点的情况
	if(cur1->pNext==NULL){//此时主链表已经到了链表最后一个元素 ，例如：1 3 5 7 和2 4 6 8 9 10 ,只需要将cur2赋给cur1->pNext即可 
		cur1->pNext=cur2; 
	}
	if(cur2->pNext==NULL){//此时第二个链表到达了最后一个元素，例如  1 3 5 7和4，此时只要将第二个链表的最后一个元素插入到合适的位置即可
		while(cur1->pNext!=NULL){
			next1=cur1->pNext;
			if(cur1->mValue<=cur2->mValue&&cur1->pNext->mValue>cur2->mValue){
				cur1->pNext=cur2;
				cur2->pNext=next1;
				cur1=cur1->pNext; //只能是cur1=cur1->pNext，不能是cur1=next1 
				break;
			}
			cur1=cur1->pNext;
		} 
		
		//当出现1 3 5 7 和 9这种情况时，在上面的while循环下并没有将节点 9 插入进去，因此还需要处理
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
