/*
对公司所有员工的年龄进行排序，公司总共有几万名员工，要求时间复杂度为O（n）。

思路：很明显的计数排序题目，员工的年龄肯定在一个范围之内，
我们这里假设在0-99之内，算很大了，这样就可以开辟一个长度为100的数组，保存各个年龄的员工的个数,然后排序即可。
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void sortAge(int * arrAge,int n){
	if(arrAge==NULL||n<=0){
		return;
	}
	int timeOfAge[100];//用来保存各个年龄出现的次数 
	memset(timeOfAge,0,sizeof(timeOfAge));//初始化为 0
	//统计 
	for(int i=0;i<n;i++){
		timeOfAge[arrAge[i]]++;
	} 
	//输出
	for(int i=0;i<100;i++){
		int times=0;
		while(times<timeOfAge[i]){
			printf("%d  ",i);
			times++;
		}
	} 
}

void input(int *arr,int n){
	if(arr==NULL||n<=0){
		return;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
}
int main(void){
	int n;
	while(scanf("%d",n)!=EOF){
		if(n>0){
			int *arrAge;
			arrAge=(int *)malloc(n*sizeof(int));
			if(arrAge==NULL){
				exit(EXIT_FAILURE);
			}
			input(arrAge,n);
			sortAge(arrAge,n);	
			
		}
	
		
	}
	return 0;
} 
