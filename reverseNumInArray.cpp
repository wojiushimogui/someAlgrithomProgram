/*
��Ŀ������
�������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�����һ�����飬�����������е�����Ե�������
���룺
ÿ�����԰����������У�
��һ�а���һ������n����ʾ�����е�Ԫ�ظ���������1 <= n <= 10^5��
�ڶ��а���n��������ÿ�������Ϊint���͡�
�����
��Ӧÿ�����԰��������һ����������ʾ�����е�����Ե�������
�������룺
4
7 5 6 4
���������
5
*/
/*
˼·����������forѭ����ͳ��ÿ����ǰ����ڸ������� 
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
