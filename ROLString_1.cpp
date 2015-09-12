

/*
思路：三次翻转
例如： str="abcdefgh"　　ｋ＝３
第一次翻转：str="cbadefgh"  即将str的前k个字符进行翻转 
第二次翻转:str="cbahgfed"    即将str从k+1之后的字符进行翻转 
第三次翻转：str="defghabc" 	最后将str整体进行翻转即完成了字符的循环移位 
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
	
	if(str==NULL||n<0){//根据条件n不能小于0，其实在实际情况的循环左移中，n是可以小于0 的 
		return ;
	}
	int len=strlen(str);
	if(len<=1){
		return;
	} 
	n=n%len;//循环移动n次与移动n%len相同，故通过求余
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
