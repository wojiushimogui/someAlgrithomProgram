/*
��8����ת�������С���� 

��Ŀ����һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת������һ����������������һ����ת�������ת�������СԪ�ء�
��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1. 

��Ŀ����˼����Ҫ����������ת������е���Сֵ��ֻ�����鲻��һ���������飬����һ����������������һ����ת
һ��˼·���������һ��һ������������Ѱ����Сֵ������ֻ��Ҫ�����������鼴�ɡ������ַ�����ʱ�临�Ӷ�ΪO(n) 
���Ǵ����鲢����һ������飬���������Ҫ������ת������ص㣬�����Ż��� 
�Ż�˼·���������ö��ֲ��ҵ�˼·��������Сֵ�Ĳ���:���Խ���ת���鿴���������Ѿ�����������飬��ǰ��������е�Ԫ��ȫ�����ں����������е�Ԫ�أ���СԪ��Ϊ��������ķֽ��ߡ�
Ȼ������м�Ԫ�صĴ�С����ҪѰ�ҵķ�Χ��һ����С , 
*/

#include<stdio.h>
#include<stdlib.h>
#define N   10
//˳��ɨ������Ѱ����Сֵ 
void sequenceScanArrayFindMinNum(int *arr,int left,int right){
	int temp=arr[left];
		for(int i=left+1;i<=right;i++){
			if(temp>arr[i]){
				temp=arr[i];
			}
		} 	
	printf("%d",temp);
}

void  minNumInRotateArray(int *arr,int n){
	if(arr==NULL||n<=0){
		return ;
	}
	int left=0;
	int right=n-1;
	int mid=left;
	while(arr[left]>=arr[right]){
		if(right-left==1){//��ʱright��ָ��ľ�����Сֵ 
			mid=right;
			break;
		}
		mid=left+(right-left)/2;
		if(arr[left]==arr[right]&&arr[left]==arr[mid]){//�������ʱ�������������Сֵ������ left��mid֮�䣬Ҳ������mid��right֮�䣬
		//��������£����Ǿ���Ҫ˳��ɨ�����������ȷ����Сֵ
			sequenceScanArrayFindMinNum(arr,left,right);
			return;
			 
		}
		if(arr[left]<=arr[mid]){
			left=mid;
		}
		else if(arr[mid]<=arr[right]){
			right=mid;
		}
	}
	printf("%d",arr[mid]);
}
void input(int *arr,int n){
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
}
int main(void){
	int n;//������Ԫ�صĸ��� 
	while(scanf("%d",&n)!=EOF){
		 int *arr=(int *)malloc(n*sizeof(int));
		 if(arr==NULL){
		 	exit(EXIT_FAILURE);
		 }
		 input(arr,n); 
		minNumInRotateArray(arr,n) ;
	}
}

