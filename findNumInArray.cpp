/*
������3����ά�����еĲ���
��Ŀ����һ����ά�����У�ÿһ�ж����մ����ҵ�˳�����������ÿһ�ж����մ��ϵ��½���������
����������һ����ά����arr��һ������k���ж��������Ƿ�����������

����������Ҫ���ǵ������
1�� ��ά�����а���Ҫ���ҵ����֣��������ֵ����Сֵ���м��ֵ��
2����ά�����в�����Ҫ���ҵ����֣������������������ 
	2.1��Ҫ���ҵ�ֵС�ڶ�ά�����е���Сֵ
	2.2��Ҫ���ҵ�ֵ���ڶ�ά�����е����ֵ
	2.3��Ҫ���ҵ�ֵ�ڶ�ά��������ֵ����Сֵ֮�䵫�ǲ����ڴ�ֵ��
3������������ԣ���ָ�룩 
*/


#include<stdio.h>
#include<string.h>
#define N  4
#define M  4
/*
@param  arr:�����ָ��
@param  rows�����������
@param  columns:���������
@param  num����Ҫ���ҵ��� 

*/

void findNumInArray(int (*arr)[N],int rows,int columns,int num){
	
	//�ȼ��arr�Ƿ���Ч
	if(arr==NULL||rows<1||columns<1){
		return ;
	} 
	
	//��ʼ��arr��Ѱ��num�Ƿ����
	//�����Ͻǿ�ʼ���� �����Ҫ���ҵ��������Ͻǵ�ֵ������ҷ�Χɾ������������ʵ�ʵ�ɾ����ֻ��Ҫ�ı��±꼴�ɣ���һ�У����Ҫ���ҵ��������Ͻǵ�ֵС������ҷ�Χɾ������һ�� 
	int row=0;
	int column=columns-1;
	bool flag=false;
	while(row<rows&&column>=0){//num==arr[row*columns+column
		int temp=arr[row][column];
			if(num==temp){
			flag=true;
			break;//����whileѭ�� 
		}
		else if(num<temp){//ɾ������
			column--; 
		}
		else{//ɾ������
			row++; 
			
		}
		
	}
	if(flag==true){
		printf("%d�����������д���\n",num);
		
	}
	else{
		printf("%d�����������в�����\n",num);
	}
	
	 
}

int main(void){
	int arr[N][M]={	
	{1,2,3,7},	
	{3,5,6,8},	
	{4,7,8,9},	
	{6,8,10,12}	
	};
	//��� 
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			printf("%d  ",arr[i][j]);
		}
		printf("\n");
	}
//	int num;
//	scanf("%d",&num);
	//������������
	int num1=1;//��Сֵ����arr�д��� 
	int num2=4;//�м�ֵ����arr�д��� 
	int num3=12;//���ֵ����arr�д���
	//ά�����в�����Ҫ���ҵ����ֵ����ֲ������� 
	int num4=0;
	int num5=20;
	int num6=11;
	 
	findNumInArray(arr,N,M,num1); 
	findNumInArray(arr,N,M,num2); 
	findNumInArray(arr,N,M,num3); 
	findNumInArray(arr,N,M,num4); 
	findNumInArray(arr,N,M,num5); 
	findNumInArray(arr,N,M,num6);  	
	return 0;
} 
