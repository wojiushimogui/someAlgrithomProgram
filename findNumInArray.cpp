/*
面试题3：二维数组中的查找
题目：在一个二维数组中，每一行都按照从左到右的顺序进行了排序，每一列都按照从上到下进行了排序。
输入这样的一个二维数组arr和一个整数k，判断数组中是否存在这个数。

测试用例需要考虑的情况：
1） 二维数组中包含要查找的数字（例如最大值、最小值、中间的值）
2）二维数组中不包含要查找的数字，会有如下三种情况： 
	2.1）要查找的值小于二维数组中的最小值
	2.2）要查找的值大于二维数组中的最大值
	2.3）要查找的值在二维数组的最大值与最小值之间但是不存在此值。
3）特殊输入测试（空指针） 
*/


#include<stdio.h>
#include<string.h>
#define N  4
#define M  4
/*
@param  arr:数组的指针
@param  rows：数组的行数
@param  columns:数组的列数
@param  num：需要查找的数 

*/

void findNumInArray(int (*arr)[N],int rows,int columns,int num){
	
	//先检查arr是否有效
	if(arr==NULL||rows<1||columns<1){
		return ;
	} 
	
	//开始在arr中寻找num是否存在
	//从右上角开始查找 ：如果要查找的数比右上角的值大，则查找范围删除掉（并不是实际的删除，只需要改变下标即可）这一行，如果要查找的数比右上角的值小，则查找范围删除掉这一列 
	int row=0;
	int column=columns-1;
	bool flag=false;
	while(row<rows&&column>=0){//num==arr[row*columns+column
		int temp=arr[row][column];
			if(num==temp){
			flag=true;
			break;//跳出while循环 
		}
		else if(num<temp){//删除该列
			column--; 
		}
		else{//删除该行
			row++; 
			
		}
		
	}
	if(flag==true){
		printf("%d在上面数组中存在\n",num);
		
	}
	else{
		printf("%d在上面数组中不存在\n",num);
	}
	
	 
}

int main(void){
	int arr[N][M]={	
	{1,2,3,7},	
	{3,5,6,8},	
	{4,7,8,9},	
	{6,8,10,12}	
	};
	//输出 
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			printf("%d  ",arr[i][j]);
		}
		printf("\n");
	}
//	int num;
//	scanf("%d",&num);
	//测试用例如下
	int num1=1;//最小值，在arr中存在 
	int num2=4;//中间值，在arr中存在 
	int num3=12;//最大值，在arr中存在
	//维数组中不包含要查找的数字的三种测试用例 
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
