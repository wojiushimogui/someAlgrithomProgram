/*
�Թ�˾����Ա��������������򣬹�˾�ܹ��м�����Ա����Ҫ��ʱ�临�Ӷ�ΪO��n����

˼·�������Եļ���������Ŀ��Ա��������϶���һ����Χ֮�ڣ�
�������������0-99֮�ڣ���ܴ��ˣ������Ϳ��Կ���һ������Ϊ100�����飬������������Ա���ĸ���,Ȼ�����򼴿ɡ�
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void sortAge(int * arrAge,int n){
	if(arrAge==NULL||n<=0){
		return;
	}
	int timeOfAge[100];//�����������������ֵĴ��� 
	memset(timeOfAge,0,sizeof(timeOfAge));//��ʼ��Ϊ 0
	//ͳ�� 
	for(int i=0;i<n;i++){
		timeOfAge[arrAge[i]]++;
	} 
	//���
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
