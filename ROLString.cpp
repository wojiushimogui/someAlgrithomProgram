/*
题目描述：
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。
输入：
多组测试数据，每个测试数据包含一个字符序列S和非负整数K。其中S的长度不超过1000。
输出：
对应每个测试案例，输出新序列。
样例输入：
UDBOJ 4
abba 1
样例输出：
JUDBO
bbaa

*/
/*
需要考虑的测试用例
1）正常输入（n<len）：str="abcdefghijklmn"   n=5 
2）正常输入（n>len）：str="abcdefghijklmn"   n=5 
3)特殊的输入 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void ROLString(char *str,int n){
	
	if(str==NULL||n<0){//根据条件n不能小于0，其实在实际情况的循环左移中，n是可以小于0 的 
		return ;
	}
	int len=strlen(str);
	if(len<=0){
		return;
	}
	if(len==1){
		puts(str);
	} 
	n=n%len;//循环移动n次与移动n%len相同，故通过求余
	for(int i=0;i<len;i++){
		putchar(str[(i+n)%len]);
	} 
	 
}
int main(void){
	char str[1000];
	int n;
	while(scanf("%s,%d",str,n)){
		ROLString(str,n);
		
	}
	
	
	return 0;
}
