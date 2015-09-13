/*
题目描述：
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
输入：
每个测试案例包括两行：
第一行包含一个整数n，表示数组中的元素个数。其中1 <= n <= 10^5。
第二行包含n个整数，每个数组均为int类型。
输出：
对应每个测试案例，输出一个整数，表示数组中的逆序对的总数。
样例输入：
4
7 5 6 4
样例输出：
5
*/
/*
思路：利用两层for循环来统计每个数前面大于该数个数 
*/

#include<stdio.h>
#include<stdlib.h>
int  statisticsReverseNumInArray(int *arr,int n){
	if(arr==NULL||n<=0){
		return -1;
	}
	int count=0;
	for(int i=n-1;i>=1;i--){
		for(int j=i-1;j>=0;j--){
			if(arr[i]<arr[j]){
				count++;
			}
		}
	}
	return count;
}
void input(int *arr,int n){
	if(arr==NULL||n<=0){
		return;
	}
	for(int i=0;i<n;i++){
		scanf("%d",arr+i);
	}
}
int main(void){
	int n;
	while(scanf("%d",&n)!=EOF){
		int *arr=(int *)malloc(n*sizeof(int));
		if(arr==NULL){
			exit(EXIT_FAILURE);
		}
		input(arr,n);
		printf("%d",statisticsReverseNumInArray(arr,n));
		free(arr);
		arr=NULL;
	}
	return 0;
} 
