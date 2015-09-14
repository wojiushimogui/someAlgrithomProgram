/*
求任意非负整数区间内整数中1出现的次数 

例如：1~13中包含1的数字有1、10、11、12、13因此共出现6次

输入：
输入有多组数据,每组测试数据为一行。
每一行有两个整数a,b(0<=a,b<=1,000,000,000)。
输出：
对应每个测试案例,输出a和b之间1出现的次数。
样例输入：
0 5
1 13
21 55
31 99
样例输出：
1
6
4
7 

此方法的解题思路为：按数字的每位上出现的数字 1 分开来统计 
得到的结论就是：
某位大于  1 时 则该为出现的次数为 [n/(10^(b+1))] 
*/

#include<stdio.h>
#inlucde<stdlib.h> 
int theNumberOfOne(int num){
	
}
int main(void){
	int begin;
	int end;
	int count=0;
	//求【begin  end】之间中  1出现的次数
	//即求【0 end】-【0 begin-1】 
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
