

/*
˼·�����η�ת
���磺 str="abcdefgh"�����룽��
��һ�η�ת��str="cbadefgh"  ����str��ǰk���ַ����з�ת 
�ڶ��η�ת:str="cbahgfed"    ����str��k+1֮����ַ����з�ת 
�����η�ת��str="defghabc" 	���str������з�ת��������ַ���ѭ����λ 
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(char *a,char *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void reverseString(char *str,int l,int r){
	if(str==NULL||l>=r||l<0||r<0){
		return;
	}
	while(l<r){
		swap(&str[l],&str[r]);
		l++;
		r--; 
	}	
}
void ROLString(char *str,int n){
	
	if(str==NULL||n<0){//��������n����С��0����ʵ��ʵ�������ѭ�������У�n�ǿ���С��0 �� 
		return ;
	}
	int len=strlen(str);
	if(len<=1){
		return;
	} 
	n=n%len;//ѭ���ƶ�n�����ƶ�n%len��ͬ����ͨ������
	if(n==0){
		return;
	}
	reverseString(str,0,n-1);
	reverseString(str,n,len-1);
	reverseString(str,0,len-1); 
	 
	 
}
int main(void){
	char str[1000];
	int n;
	while(scanf("%s  %d",str,&n)){
		ROLString(str,n);
		puts(str);
		
	}
	
	
	return 0;
}
