/*�������ľ���
���룺
������ܰ����������������������EOF������
����ÿ�����԰���������ĵ�һ��Ϊһ������n(0<=n<=1000,n����Ҫ����Ķ������ڵ�ĸ������ڵ��1��ʼ��ţ���������һ����n������,�����i���������ڵ��Ԫ�ص�ֵ����������n�У�ÿ����һ����ĸCi��
Ci=��d����ʾ��i���ڵ������Ӻ��ӣ������������ӱ�ź��Һ��ӱ�š�
Ci=��l����ʾ��i���ڵ���һ�����ӣ������������ӵı�š�
Ci=��r����ʾ��i���ڵ���һ���Һ��ӣ����������Һ��ӵı�š�
Ci=��z����ʾ��i���ڵ�û���Ӻ��ӡ�
�����
��Ӧÿ�����԰�����
����ǰ������亢�ӽڵ��Ԫ��ֵ��
��Ϊ�����NULL��
�������룺
7
8 6 10 5 7 9 11
d 2 3
d 4 5
d 6 7
z
z
z
z
���������
8 10 11 9 6 7 5
*/
/*
˼·��ͨ����ͼ���ǿ��Կ������������ľ�����ǽ���Ҷ�ӽڵ����ڵ���ҽڵ���н�������

ע�⣺������������Ϊ����������ڵ�����ݽṹ 

����������
1��һ��Ķ��������������
2������ȫ�����������������һ�����еĽڵ�ֻ�����������еĽڵ�ֻ���������� 
3��ֻ��һ���ڵ����
4����������� 

*/

#include<stdio.h>
#include<stdlib.h>

//���Ľڵ�
//���ڽڵ��Ǳ����������У���ˣ�ÿ���ڵ��pLeftChild��pRightChildΪ���������ڵ��ڽڵ������е��±� 
typedef  int ElementType;
struct TreeNode{
	ElementType mValue;
	int pLeftChild;
	int pRightChild;
}; 
/*
������˵��
@param pNode:���ڵ��ͷָ�� 
@param  index���ڵ��ڽڵ������е��±� 
*/
void mirrorBinaryTree(TreeNode *pNode,int index){
	if(pNode==NULL){
		return;		
	}
	if(index==-1){
		return;
	}
	if(pNode[index].pLeftChild==-1&&pNode[index].pRightChild==-1){//ֻ��һ���ڵ�
		return; 
	}
	//�����˽ڵ�����ҽڵ�
	int temp=pNode[index].pLeftChild;
	pNode[index].pLeftChild=pNode[index].pRightChild;
	pNode[index].pRightChild=temp;
	if(pNode[index].pLeftChild!=-1){
		mirrorBinaryTree(pNode,pNode[index].pLeftChild);
	}
	if(pNode[index].pRightChild!=-1){
		mirrorBinaryTree(pNode,pNode[index].pRightChild);
	}
	
	
}
int i;
void saveValueByPreTraversal(TreeNode *pNode,int index,int *preTraversal,int len){
	if(pNode==NULL||preTraversal==NULL||len<=0||index==-1)
		return;
	if(index!=-1&&index<len){
		preTraversal[i++]=pNode[index].mValue;
		if(pNode[index].pLeftChild!=-1){
			saveValueByPreTraversal(pNode,pNode[index].pLeftChild,preTraversal,len);
		}
		if(pNode[index].pRightChild!=-1){
			saveValueByPreTraversal(pNode,pNode[index].pRightChild,preTraversal,len);
		}
	}
		
}
int main(void){
	//�ڵõ��������ľ����֮ǰ��������Ҫ����һ����
	int n;
	while(scanf("%d",&n)!=EOF){
		if(n>0){
			TreeNode *pNode=(TreeNode*)malloc(n*sizeof(TreeNode));
			
			if(pNode==NULL){
				exit(EXIT_FAILURE);
			}
			
			//��������ʼ����ÿ���ڵ��value
			int val;
			for(int i=0;i<n;i++){//����ڵ��±��Ǵ�0��ʼ�� 
			
				scanf("%d",&val);
				pNode[i].mValue=val;
				pNode[i].pLeftChild=-1;//-1��ʾ���ӽڵ� 
				pNode[i].pRightChild=-1;
			}
			//��������ʼ����ÿ���ڵ�����ҽڵ�
			int leftIndex;
			int rightIndex;
			for(int i=0;i<n;i++){
				char ch;
				scanf("%d",&ch);
				if(ch=='d'){//�˽ڵ������������ڵ�
					 
					 scanf("%d %d",&leftIndex,&rightIndex);//leftIndexΪ��leftIndex���ڵ� ����1��ʼ�����Ϊ�洢�������У���Ҫ�� 1 
					 pNode[i].pLeftChild=leftIndex-1;
					 pNode[i].pRightChild=rightIndex-1;
					 
				}
				else if(ch=='l'){
					scanf("%d",&leftIndex);//leftIndexΪ��leftIndex���ڵ� ����1��ʼ�����Ϊ�洢�������У���Ҫ�� 1 
					pNode[i].pLeftChild=leftIndex-1;
				}
				else if(ch=='r'){
					scanf("%d",&rightIndex);
					pNode[i].pRightChild=rightIndex-1;
					
				}
				else if(ch=='z'){
					continue;
				}
				else{
					exit(EXIT_FAILURE);
				} 
			
			}
			//���ϴ�����һ��������
			 
		}
		
		if(n<=0){
			printf("NULL\n");
		}
		mirrorBinaryTree(pNode,0); //�õ���������� 
		
		//��ǰ��������ڵ��е�value������һ��������
		int * preTraversal;
		preTraversal=(int *)malloc(n*sizeof(int));
		saveValueByPreTraversal(pNode,0,preTraversal,n);
		for(int i=0;i<n;i++){
			printf("%d ",preTrversal[i]);
		}
	}
	
	//my_print(pHead);//��ӡ����֮ǰ�Ķ����� 

	//my_print(pHead);//��ӡ��������� 
	return 0;
}
