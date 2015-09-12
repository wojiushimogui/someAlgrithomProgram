/*
题8：旋转数组的最小数字 

题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1. 

题目的意思就是要求我们找旋转数组的中的最小值。只是数组不是一般的随机数组，而是一个递增排序的数组的一个旋转
一般思路：如果是在一个一般的随机数组中寻找最小值，我们只需要遍历整个数组即可。而此种方法的时间复杂度为O(n) 
但是此数组并不是一般的数组，因此我们需要利用旋转数组的特点，进行优化。 
优化思路：我们利用二分查找的思路来进行最小值的查找:可以将旋转数组看成是两个已经排序的子数组，且前面的数组中的元素全部大于后面子数组中的元素，最小元素为两个数组的分界线。
然后根据中间元素的大小来将要寻找的范围进一步缩小 , 
*/

#include<stdio.h>
#include<stdlib.h>
#define N   10
//顺序扫描数组寻找最小值 
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
		if(right-left==1){//此时right所指向的就是最小值 
			mid=right;
			break;
		}
		mid=left+(right-left)/2;
		if(arr[left]==arr[right]&&arr[left]==arr[mid]){//三者相等时的特殊情况，最小值可能在 left和mid之间，也可能在mid和right之间，
		//这种情况下，我们就需要顺序扫描这个数组来确定最小值
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
	int n;//数组中元素的个数 
	while(scanf("%d",&n)!=EOF){
		 int *arr=(int *)malloc(n*sizeof(int));
		 if(arr==NULL){
		 	exit(EXIT_FAILURE);
		 }
		 input(arr,n); 
		minNumInRotateArray(arr,n) ;
	}
}

