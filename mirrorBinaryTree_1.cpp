#include<stdio.h>  
#include<stdlib.h>  
  
typedef struct BTNode  
{  
    int data;  
    int rchild;  
    int lchild;  
}BTNode;  
  
  
/* 
�ж�pTree1�Ƿ����pTree2 
*/  
void MirrorTree(BTNode *pTree,int index)  
{  
    if(pTree == NULL)  
        return;  
    if(index == -1)  
        return;  
    if(pTree[index].lchild==-1 && pTree[index].rchild==-1)  
        return;  
  
    int temp = pTree[index].lchild;  
    pTree[index].lchild = pTree[index].rchild;  
    pTree[index].rchild = temp;  
  
    if(pTree[index].lchild!=-1)  
        MirrorTree(pTree,pTree[index].lchild);  
    if(pTree[index].rchild!=-1)  
        MirrorTree(pTree,pTree[index].rchild);  
}  
  
//��������ȫ�ֱ���i��Ŀ����Ϊ�˽������������Ԫ�����α��浽����preTraverse�У�  
//��Ŀ����Ϊ��ȷ�����һ�����Ԫ�أ������õ�������ĸ�ʽ��ʹ������ϲ���ϵͳ��Ҫ��  
int i = 0;  
void pre_traverse(BTNode *pTree,int index,int *preTraverse,int n)  
{  
    if(pTree == NULL)  
        return;  
    if(index != -1 && i<n)  
    {  
        preTraverse[i++] = pTree[index].data;  
        if(pTree[index].lchild != -1)  
            pre_traverse(pTree,pTree[index].lchild,preTraverse,n);  
        if(pTree[index].rchild != -1)  
            pre_traverse(pTree,pTree[index].rchild,preTraverse,n);  
    }  
}  
  
int main()  
{  
    int n;  
    while(scanf("%d",&n) != EOF)  
    {  
        //������pTree���ڵ��ֵ  
        BTNode *pTree = NULL;  
        if(n>0)  
        {  
            pTree = (BTNode *)malloc(n*sizeof(BTNode));  
            if(pTree == NULL)  
                exit(EXIT_FAILURE);  
            int i,data;  
            //����n���ڵ��data  
            for(i=0;i<n;i++)  
            {  
                scanf("%d",&data);  
                pTree[i].data = data;  
                pTree[i].rchild = -1;  
                pTree[i].lchild = -1;  
            }  
  
            //����n�нڵ����ӹ�ϵ  
            for(i=0;i<n;i++)  
            {  
                char ci;  
                //�����е�������Ϊ�������������еĻ��з�  
                //���ﲻ����fflush(stdin)��gcc��֧�֣���ֻ��һЩ�������Լӵģ�  
                //������ˣ�����ϵͳ�ᱨRE��  
                while(getchar() != '\n')  
                    continue;  
                scanf("%c",&ci);  
                if(ci == 'z')  
                    continue;  
                else if(ci == 'l')  
                {  
                    int lindex;  
                    scanf("%d",&lindex);  
                    pTree[i].lchild = lindex-1;  
                }  
                else if(ci == 'r')  
                {  
                    int rindex;  
                    scanf("%d",&rindex);  
                    pTree[i].rchild = rindex-1;  
                }  
                else if(ci == 'd')  
                {  
                    int lindex,rindex;  
                    scanf("%d",&lindex);  
                    scanf("%d",&rindex);  
                    pTree[i].lchild = lindex-1;  
                    pTree[i].rchild = rindex-1;  
                }  
            }  
        }  
          
        if(n == 0)  
        {  
            printf("NULL\n");  
            continue;  
        }  
        MirrorTree(pTree,0);  
        //�Ƚ�������Ԫ�����α��浽preTraverse������  
        int *preTraverse = (int *)malloc(n*sizeof(int));  
        if(preTraverse == NULL)  
            exit(EXIT_FAILURE);  
        pre_traverse(pTree,0,preTraverse,n);  
        int i;  
        for(i=0;i<n;i++)  
        {  
            //��������ϲ���ϵͳҪ��ĸ�ʽ  
            if(i == n-1)  
                printf("%d\n",preTraverse[i]);  
            else  
                printf("%d ",preTraverse[i]);     
        }  
  
        free(preTraverse);  
        preTraverse = NULL;  
  
        free(pTree);  
        pTree = NULL;  
    }  
    return 0;  
} 
