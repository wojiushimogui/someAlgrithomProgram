/*
��Ŀ������
ͳ��һ�����������������г��ֵĴ�����
���룺
ÿ�����԰����������У�
��һ����1������n����ʾ����Ĵ�С��1<=n <= 10^6��
�ڶ�����n����������ʾ����Ԫ�أ�ÿ��Ԫ�ؾ�Ϊint��
��������1������m����ʾ��������m�β�ѯ��1<=m<=10^3��

������m�У�ÿ����һ������k����ʾҪ��ѯ������
�����
��Ӧÿ�����԰�������m�������ÿ��1��������ʾ�����и����ֳ��ֵĴ�����
�������룺
8
1 2 3 3 3 3 4 5
1
3
���������
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
		//�������ǲ�֪�����������е����ֵĴ�С����ˣ�����Ҳ��֪��Ӧ�ÿ��ٶ��Ŀռ����洢������ÿ�����ֳ��ֵ���������
		//�������ֻ�ܱ�����ͳ������Ҫ��ѯ���ֵĴ��� 
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
//������Ҫ���Ѿ�����������в������ֳ��ֵĴ���������Ϊ�˷��㣬����ֱ���������������Ѿ�����õ�
//�����Ҫ�����������ǿ���дһ�����������������Ƚϼ򵥣����ﲻ��ʵ�� 
int main(void){
	int n;
	scanf("%d",&n);//����ĿҪ�󣺵�һ��Ϊ����ĳ��� 
	int arr[n];
	input(arr,n);//�ڶ�������Ϊ��������� 
	int m;
	scanf("%d",&m);//����������ΪҪ��ѯ�Ĵ��� 
	int findNumArray[m];
	input(findNumArray,m);//����������ΪҪ��ѯ������ 
	numTimesInsortArray(arr,n,findNumArray,m); 
	return 0;
}
