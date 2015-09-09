/*
翻转单词顺序
输入：
每个测试案例为一行，表示一句英文句子。
我们保证一个句子的单词数不会超过600，每个单词的长度也不会超过30。但是需要注意的是Fish是个不拘小节的人，有时候两个单词中间可能会有很多空格。为了方便起见，你可以认为一行的字符总数不会超过50000个，标点符号可以和普通字母一样处理。
输出：
对应每个测试案例，把翻转后的正确的句子单独输出一行。

样例输入：
student. a am I
I'm a Freshman and I like JOBDU!
样例输出：
I am a student.
JOBDU! like I and Freshman a I'm 

测试用例：空格也需要翻转 
1） student. a am I（正常输入，单词与单词之间只有一个空格） 
2） student.       a       am I（正常输入，单词与单词之间有多个空格）
3）"    "(只有空格构成)
4）NULL 
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void reverseString(char *str,int begin,int end);

void swap(char *str,int begin,int end){
	int temp=str[begin];
	str[begin]=str[end];
	str[end]=temp;
	
}
//以空格来作为分割单词的界线
/*
@param str:字符串
@param begin:指向字符串第一个非空格的字符 
@param end:指向字符串最后一个非空格的字符 
*/ 
void reverseWord(char *str,int begin,int end){
	int index=begin;
	while(index<=end){
		if(str[index]!=' '){
			index++;
		}
		else{
			//在遇到空格时 begin  与 index之间是一个单词，处理空格的方式就是不处理，直接跳过即可，因为在处理空格的时候begin==index 
			if(begin<index){
				reverseString(str,begin,index-1);
			} 
		
			index++;//这两条语句就是：处理空格的方式就是不处理，直接跳过
			begin=index;
			
			/*
			跳过多个空格
			while(str[index]==' '){
			index++;
			} 
			
			
			*/ 
		 
		}
	}
	
}
//翻转字符串 
void reverseString(char *str,int begin,int end){
	//判断str是否有效 
	if(str==NULL||begin>=end){//begin=end为只有一个字符，不需要返回，只返回 
		return;
	}

//	int begin=0;
//	int end=len-1;
	//检查字符是否全部由空格组成,若是，则退出 
	//并将两个指针begin、end，分别指向字符串中首字符和尾字符
	int index=0; 
	while(index<=end){
		if(str[index]!=' '){
			break;
		}
		else{
			index++; 
		} 
		
	}
	if(index==end){//如果begin==len,则说明此字符串全部由空格组成 
		return;
	} 

	
	//将begin、end暂存在temp_begin、temp_end 
	int temp_begin=begin;
	int temp_end=end;
	while(begin<end){
		swap(str,begin,end);//交换这两个位置的字符 
		++begin;
		--end;
	}
	
	//翻转单词
	reverseWord(str,temp_begin,temp_end); 
	
}

int main(void){
	char str[50000];
	gets(str);
	puts(str);
	int len=strlen(str);
	if(len>0){
		reverseString(str,0,len-1);
	}

	puts(str);
	return 0;
}
