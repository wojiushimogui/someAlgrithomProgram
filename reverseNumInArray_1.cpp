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
上一种方法的思路：利用两层for循环来统计每个数前面大于该数个数 ，时间复杂度为O(n*n) 
这里提供另外一种方法，就是利用 快排的思想进行逆序对的统计 
*/

#include<stdio.h>
#include<stdlib.h>

long long mergeStatisticsReverseNum(int *arr,int start,int mid,int end){
	if(arr==NULL||start>end){
		return 0;
	}
	//下面开始归并并统计逆序对的个数
	//先定义两个临时数组来存放子数组
	int lenSubArr1=mid-start+1;//第一个子数组的长度 
	int lenSubArr2=end-mid;//第二个子数组的长度 
	int subArr1[lenSubArr1];
	int subArr2[lenSubArr2];
	
	for(int i=0;i<lenSubArr1;i++){
		subArr1[i]=arr[i+start];
	} 
	for(int j=0;j<lenSubArr2;j++){
		subArr2[j]=arr[mid+1+j];
	}
	
	int indexSubArr1=0;
	int indexSubArr2=0;
	int indexTotalArr=0;
	long long count=0;//统计逆序个数的变量 
	
	while(indexSubArr1<lenSubArr1&&indexSubArr2<lenSubArr2){ 
		if(subArr1[indexSubArr1]<=subArr2[indexSubArr2]){//第一个子数组的元素较小的情况 
			arr[indexTotalArr]=subArr1[indexSubArr1];
			indexTotalArr++;
			indexSubArr1++; 
		}
		else{//第二个子数组的元素较小的情况 ，此时会出现一个逆序对
			count++; 
			arr[indexTotalArr]=subArr2[indexSubArr2];
			indexTotalArr++;
			indexSubArr2++; 
		}
	}
	//将子数组中subArr1和aubArr2剩余的元素拷贝到arr中 
	while(indexSubArr1<lenSubArr1){//这种情况会出现逆序对，并且逆序对的个数为（第一个子数组剩余个数-1）*第二个子数组元素的个数;例如 3 4 5和1 2，当1 2放入到arr中后， 
			count+=lenSubArr2; 
			arr[indexTotalArr]=subArr1[indexSubArr1];
			indexTotalArr++;
			indexSubArr1++; 
			if(indexSubArr1==lenSubArr1-1){//减与1* 第二个子数组元素的个数，防止重复统计边界那个数的逆序对 
				count-=lenSubArr2;
			} 
	}
	while(indexSubArr2<lenSubArr2){//此种情况没有产生逆序对 
			arr[indexTotalArr]=subArr2[indexSubArr2];
			indexTotalArr++;
			indexSubArr2++; 
	}
	return count; 
}
//由于数组中元素的个数为1 <= n <= 10^5。 因此逆序对的个数的上界为等差数列的和：（10^5-1）*10^5/2 
//超过了int型的最大值（大约2*10^9）,因此将返回值定为 long long类型 
long long  statisticsReverseNumInTotalArrayByMerge(int *arr,int start,int end){
	if(arr==NULL||start>=end){
		return 0;
	}
	long long count=0;
	int mid=start+(end-start)/2;
	count+=statisticsReverseNumInTotalArrayByMerge(arr,start,mid);
	count+=statisticsReverseNumInTotalArrayByMerge(arr,mid+1,end);
	count+=mergeStatisticsReverseNum(arr,start,mid,end);
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
		printf("%lf",statisticsReverseNumInTotalArrayByMerge(arr,0,n-1));
		free(arr);
		arr=NULL;
	}
	return 0;
} 
