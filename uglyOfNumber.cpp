/*
��Ŀ������
��ֻ��������2��3��5��������������Ugly Number��������6��8���ǳ�������14���ǣ���Ϊ����������7��
ϰ�������ǰ�1�����ǵ�һ���������󰴴�С�����˳��ĵ�N��������
���룺
�������һ������N(1<=N<=1500)��
�����
�����ж���������ݣ�����ÿ�����ݣ�
�����N��������

�������룺
3
���������
3

˼·����򵥵ķ���������ͨ����һ�������ϳ���2��3��5���ж������ǲ��ǳ�����
�����ڴ�1��ʼ�����������ж�ÿ�����ǲ��ǳ����������³����ĸ���������������ĸ���Ϊ����ֵʱ��
������Ҫ��ĵ�n�����������ַ�����ʱ�临�Ӷ�ΪO��k���������kΪ��n�������Ĵ�С��
�����1500�������Ĵ�СΪ859963392����ô����Ҫ�ж�859963392�Σ�ʱ��Ч�ʷǳ��͡�
    ֱ�۵��Ż���ʩ���ǿ��ܲ��ܽ�ʱ�临�ӶȽ��͵�O��n������ֻ�ڳ����ϻ�ʱ�䣬�����ڷǳ������˷�ʱ�䡣
	��ָoffer�ϸ���˼·�ܺã���O��n���ĸ����ռ����õ�O(n)��ʱ�临�Ӷȡ�
	�����˼���ǣ�ÿһ��������Ȼ����֮ǰ��ĳ��������2��3��5�ĳ˻��õ��ģ�
	������һ����������֮ǰ�ĳ����ֱ����2��3��5���ҳ�����������С�Ĳ��Ҵ��ڵ�ǰ��������ֵ����Ϊ��һ��Ҫ��ĳ�����
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int my_min(int a,int b,int c){
	int temp=a<b?a:b;//����a��b����Сֵ
	return (temp<c?temp:c); 
}

int getUglyOfNumber(int num){
	//����O(n)���ռ䣬����ʱ�临�ӶȽ�ΪO��n�� 
	int uglyNumber[1500]; 
	memset(uglyNumber,0,sizeof(uglyNumber));
	if(num<=0||num>1500){
		return -1;
	}
	
	uglyNumber[0]=1;
	int currentUglyIndex=1;//��ǰ�������±�
	int *p2=uglyNumber;
	int *p3=uglyNumber;
	int *p5=uglyNumber;
//	int min=0;
	while(currentUglyIndex<num){
		int	min=my_min(2*(*p2),3*(*p3),5*(*p5));
		uglyNumber[currentUglyIndex]=min;
		//����3��whileѭ��ʼ�ձ�֤  ��һ������һ���� 2*(*p2),2*(*p3),2*(*p5)�в��� 
		while(2*(*p2)<=min){
			++p2;
		}
		while(3*(*p3)<=min){
			++p3;
		}
		while(5*(*p5)<=min){
			++p5;
		}
		++currentUglyIndex;
	} 
	
	return uglyNumber[num-1];
	
}

int main(void){
	int num;

	while(scanf("%d",&num)!=EOF){//ע�⣺ scanf("%d\n",&num)!=EOF;ǧ��Ҫ��һ��\n,��������ȷ�Ķ�ȡ����������֣���debugҲ�Ҳ��������� 
		printf("%d\n",num);
		printf("%d\n",getUglyOfNumber(num));
	}
	

	return 0;
} 
