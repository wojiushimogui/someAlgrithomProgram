/*
������Ǹ�����������������1���ֵĴ��� 

���磺1~13�а���1��������1��10��11��12��13��˹�����6��

���룺
�����ж�������,ÿ���������Ϊһ�С�
ÿһ������������a,b(0<=a,b<=1,000,000,000)��
�����
��Ӧÿ�����԰���,���a��b֮��1���ֵĴ�����
�������룺
0 5
1 13
21 55
31 99
���������
1
6
4
7 

�˷����Ľ���˼·Ϊ�������ֵ�ÿλ�ϳ��ֵ����� 1 �ֿ���ͳ�� 
�õ��Ľ��۾��ǣ�
ĳλ����  1 ʱ ���Ϊ���ֵĴ���Ϊ [n/(10^(b+1))] 
*/

#include<stdio.h>
#inlucde<stdlib.h> 
int theNumberOfOne(int num){
	
}
int main(void){
	int begin;
	int end;
	int count=0;
	//��begin  end��֮����  1���ֵĴ���
	//����0 end��-��0 begin-1�� 
	while(scanf("%d",&begin,&end)){
		if(end>=begin){
			count=theNumberOfOne(end)-theNumberOfOne(begin-1);
		}
		else{
			count=theNumberOfOne(begin)-theNumberOfOne(end-1);
		}
		printf("%d",theNumberOfOne(begin,end));
	}
	return 0;
}
