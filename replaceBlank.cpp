#include<stdio.h>
#include<string.h>
//题目：请实现一个函数，吧字符串中的每个空格替换成“%20”。例如输入“We are happy”,则输出”We%20are%20happy“。
//将空格用“%20”替换 
//要求：原空间足够大，能够容纳替换后的字符串，不能开辟新的空间 
/*
需要考虑的测试用例如下：
1）字符串中存在空格（空格位于字符串的最前面、最后面和中间，空格的个数可以是连续的多个） 
2）字符串中不存在空格
3）特殊输入测试（字符串是个NULL指针、字符串是个空字符串、字符串只有一个空格的字符串、字符串中只有连续多个空格。 
*/ 
void replaceBlank1(char str[],int len){
	if(str==NULL||len<=0||str==""){
		return ;
	} 
	int originLen=0;//用来记录替换前字符的个数
	int blankCount=0;//用来记录此字符串中空格出现的个数 
	int index=0;
	while(str[index]!='\0'){
		originLen++;
		if(str[index]==' '){
			blankCount++;
		}
		index++;
	}
	int newLen=0;
	newLen=originLen+blankCount*2; //由于是将空格替换为“%20”，因此替换后的字符串所需要的空间为原字符串的空间+空格个数*2 
	//判断下替换后所需的空间是否大于总空间 
	if(newLen>len){
		return ;
		
		
	}
	//设定两个指针分别指向最后的位置，然后逐个字符移动，当不是空格时，执行拷贝，当时空格时，则完成替换任务，直至两个指针指向同一个位置 
	int indexOrigin=originLen;//用于指示替换前的最后一个位置 
	int indexNew=newLen; //用来指示替换后的最后一个位置 
	
	while(indexOrigin>=0&&indexOrigin<=indexNew){
		if(str[indexOrigin]!=' '){//当不是空格时，完成拷贝任务
			str[indexNew] =str[indexOrigin];
			indexNew--;
			indexOrigin--;
			 
		}
		else{
			str[indexNew--]='0';
			str[indexNew--]='2';
			str[indexNew--]='%';
			indexOrigin--;
		}
		
		
	}
	puts(str);
	
}
int main(void){
	char str[100];
//	gets(str);
//	replaceBlank1(str,100);
	//直接用测试用例来进行测试
	char str1[]="     wuranghao";//空格（5个）在字符串最前面
	char str2[]="wuranghao     ";//空格（5个）在字符串最后面
	char str3[]="wu     rang     hao";//在中间（5个） 
	char str4[]="     wu     rang     hao     " ;//空格在字符串的前面、中间、后面均存在 (5个)
	char str5[4];//即str5为NULL 
	char str6[]="" ;
	char str7[]=" "; //有一个空格 
	char str8[]="     ";//有5个空格 
	replaceBlank1(str1,100);
	replaceBlank1(str2,100);
	replaceBlank1(str3,100);
	replaceBlank1(str4,100);
	replaceBlank1(str5,100);
	replaceBlank1(str6,100);
	replaceBlank1(str7,100);
	replaceBlank1(str8,100);
	
	return 0;
}
