/*二叉树的镜像
输入：
输入可能包含多个测试样例，输入以EOF结束。
对于每个测试案例，输入的第一行为一个整数n(0<=n<=1000,n代表将要输入的二叉树节点的个数（节点从1开始编号）。接下来一行有n个数字,代表第i个二叉树节点的元素的值。接下来有n行，每行有一个字母Ci。
Ci=’d’表示第i个节点有两子孩子，紧接着是左孩子编号和右孩子编号。
Ci=’l’表示第i个节点有一个左孩子，紧接着是左孩子的编号。
Ci=’r’表示第i个节点有一个右孩子，紧接着是右孩子的编号。
Ci=’z’表示第i个节点没有子孩子。
输出：
对应每个测试案例，
按照前序输出其孩子节点的元素值。
若为空输出NULL。
样例输入：
7
8 6 10 5 7 9 11
d 2 3
d 4 5
d 6 7
z
z
z
z
样例输出：
8 10 11 9 6 7 5
*/
/*
思路：通过画图我们可以看到，二叉树的镜像就是将非叶子节点的左节点和右节点进行交换即可

注意：采用数组来作为保存二叉树节点的数据结构 

测试样例：
1）一般的二叉树（完成树）
2）非完全树（包含两种情况：一种是有的节点只有左子树、有的节点只有右子数） 
3）只有一个节点的树
4）特殊的输入 

*/

#include<stdio.h>
#include<stdlib.h>

//树的节点
//由于节点是保存在数组中，因此，每个节点的pLeftChild、pRightChild为左右两个节点在节点数组中的下标 
typedef  int ElementType;
struct TreeNode{
	ElementType mValue;
	int pLeftChild;
	int pRightChild;
}; 
/*
参数的说明
@param pNode:树节点的头指针 
@param  index：节点在节点数组中的下标 
*/
void mirrorBinaryTree(TreeNode *pNode,int index){
	if(pNode==NULL){
		return;		
	}
	if(index==-1){
		return;
	}
	if(pNode[index].pLeftChild==-1&&pNode[index].pRightChild==-1){//只有一个节点
		return; 
	}
	//交换此节点的左右节点
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
	//在得到二叉树的镜像的之前，我们需要创建一个树
	int n;
	while(scanf("%d",&n)!=EOF){
		if(n>0){
			TreeNode *pNode=(TreeNode*)malloc(n*sizeof(TreeNode));
			
			if(pNode==NULL){
				exit(EXIT_FAILURE);
			}
			
			//接下来开始接受每个节点的value
			int val;
			for(int i=0;i<n;i++){//这里节点下标是从0开始的 
			
				scanf("%d",&val);
				pNode[i].mValue=val;
				pNode[i].pLeftChild=-1;//-1表示无子节点 
				pNode[i].pRightChild=-1;
			}
			//接下来开始接受每个节点的左右节点
			int leftIndex;
			int rightIndex;
			for(int i=0;i<n;i++){
				char ch;
				scanf("%d",&ch);
				if(ch=='d'){//此节点有左右两个节点
					 
					 scanf("%d %d",&leftIndex,&rightIndex);//leftIndex为第leftIndex个节点 ，从1开始，因此为存储在数组中，需要减 1 
					 pNode[i].pLeftChild=leftIndex-1;
					 pNode[i].pRightChild=rightIndex-1;
					 
				}
				else if(ch=='l'){
					scanf("%d",&leftIndex);//leftIndex为第leftIndex个节点 ，从1开始，因此为存储在数组中，需要减 1 
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
			//以上创建好一个二叉树
			 
		}
		
		if(n<=0){
			printf("NULL\n");
		}
		mirrorBinaryTree(pNode,0); //得到镜像二叉树 
		
		//按前序遍历将节点中的value保存在一个数组中
		int * preTraversal;
		preTraversal=(int *)malloc(n*sizeof(int));
		saveValueByPreTraversal(pNode,0,preTraversal,n);
		for(int i=0;i<n;i++){
			printf("%d ",preTrversal[i]);
		}
	}
	
	//my_print(pHead);//打印镜像之前的二叉树 

	//my_print(pHead);//打印镜像二叉树 
	return 0;
}
