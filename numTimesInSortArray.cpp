/*
题目描述：
统计一个数字在排序数组中出现的次数。
输入：
每个测试案例包括两行：
第一行有1个整数n，表示数组的大小。1<=n <= 10^6。
第二行有n个整数，表示数组元素，每个元素均为int。
第三行有1个整数m，表示接下来有m次查询。1<=m<=10^3。

下面有m行，每行有一个整数k，表示要查询的数。
输出：
对应每个测试案例，有m行输出，每行1整数，表示数组中该数字出现的次数。
样例输入：
8
1 2 3 3 3 3 4 5
1
3
样例输出：
4
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void output(int *arr,int m){
	if(arr==NULL||m<=0){
		return;
	}
	for(int i=0;i<m;i++){
		printf("%d  ",arr[i]);
	}
}
void numTimesInsortArray(int * arr,int n,int *findNumArray,int m) {
	if(arr==NULL||n<=0||findNumArray==NULL||m<=0){
		return;
	}
	int index=0;
	int result[m];
	memset(result,0,sizeof(result));
	while(index<m){
		if(findNumArray[index]<arr[0]||findNumArray[index]>arr[n-1]){
			break;
		}
		//由于我们不知道我们数组中的数字的大小，因此，我们也不知道应该开辟多大的空间来存储数组中每个数字出现的呃次数，
		//因此我们只能遍历来统计我们要查询数字的次数 
		for(int i=0;i<n;i++){
			if(findNumArray[index]==arr[i]){
				result[index]++;
			}
		}
		index++;
	}
	output(result,m);
	
	
}
void input(int *arr,int n){
	if(n<0){
		return;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
}
//这里需要在已经排序的数组中查找数字出现的次数，这里为了方便，我们直接输入的数组就是已经排序好的
//如果需要输入乱序，我们可以写一个排序函数，排序函数比较简单，这里不再实现 
int main(void){
	int n;
	scanf("%d",&n);//按题目要求：第一行为数组的长度 
	int arr[n];
	input(arr,n);//第二行输入为数组的内容 
	int m;
	scanf("%d",&m);//第三行输入为要查询的次数 
	int findNumArray[m];
	input(findNumArray,m);//第四行输入为要查询的内容 
	numTimesInsortArray(arr,n,findNumArray,m); 
	return 0;
}
