/*
��Ŀ������
�����������һ����λָ�����ѭ�����ƣ�ROL���������и��򵥵����񣬾������ַ���ģ�����ָ�����������
����һ���������ַ�����S���������ѭ������Kλ���������������磬�ַ�����S=��abcXYZdef��,Ҫ�����ѭ������3λ��Ľ��������XYZdefabc����
���룺
����������ݣ�ÿ���������ݰ���һ���ַ�����S�ͷǸ�����K������S�ĳ��Ȳ�����1000��
�����
��Ӧÿ�����԰�������������С�
�������룺
UDBOJ 4
abba 1
���������
JUDBO
bbaa

*/
/*
��Ҫ���ǵĲ�������
1���������루n<len����str="abcdefghijklmn"   n=5 
2���������루n>len����str="abcdefghijklmn"   n=5 
3)��������� 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void ROLString(char *str,int n){
	
	if(str==NULL||n<0){//��������n����С��0����ʵ��ʵ�������ѭ�������У�n�ǿ���С��0 �� 
		return ;
	}
	int len=strlen(str);
	if(len<=0){
		return;
	}
	if(len==1){
		puts(str);
	} 
	n=n%len;//ѭ���ƶ�n�����ƶ�n%len��ͬ����ͨ������
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
