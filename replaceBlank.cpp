#include<stdio.h>
#include<string.h>
//��Ŀ����ʵ��һ�����������ַ����е�ÿ���ո��滻�ɡ�%20�����������롰We are happy��,�������We%20are%20happy����
//���ո��á�%20���滻 
//Ҫ��ԭ�ռ��㹻���ܹ������滻����ַ��������ܿ����µĿռ� 
/*
��Ҫ���ǵĲ����������£�
1���ַ����д��ڿո񣨿ո�λ���ַ�������ǰ�桢�������м䣬�ո�ĸ��������������Ķ���� 
2���ַ����в����ڿո�
3������������ԣ��ַ����Ǹ�NULLָ�롢�ַ����Ǹ����ַ������ַ���ֻ��һ���ո���ַ������ַ�����ֻ����������ո� 
*/ 
void replaceBlank1(char str[],int len){
	if(str==NULL||len<=0||str==""){
		return ;
	} 
	int originLen=0;//������¼�滻ǰ�ַ��ĸ���
	int blankCount=0;//������¼���ַ����пո���ֵĸ��� 
	int index=0;
	while(str[index]!='\0'){
		originLen++;
		if(str[index]==' '){
			blankCount++;
		}
		index++;
	}
	int newLen=0;
	newLen=originLen+blankCount*2; //�����ǽ��ո��滻Ϊ��%20��������滻����ַ�������Ҫ�Ŀռ�Ϊԭ�ַ����Ŀռ�+�ո����*2 
	//�ж����滻������Ŀռ��Ƿ�����ܿռ� 
	if(newLen>len){
		return ;
		
		
	}
	//�趨����ָ��ֱ�ָ������λ�ã�Ȼ������ַ��ƶ��������ǿո�ʱ��ִ�п�������ʱ�ո�ʱ��������滻����ֱ������ָ��ָ��ͬһ��λ�� 
	int indexOrigin=originLen;//����ָʾ�滻ǰ�����һ��λ�� 
	int indexNew=newLen; //����ָʾ�滻������һ��λ�� 
	
	while(indexOrigin>=0&&indexOrigin<=indexNew){
		if(str[indexOrigin]!=' '){//�����ǿո�ʱ����ɿ�������
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
	//ֱ���ò������������в���
	char str1[]="     wuranghao";//�ո�5�������ַ�����ǰ��
	char str2[]="wuranghao     ";//�ո�5�������ַ��������
	char str3[]="wu     rang     hao";//���м䣨5���� 
	char str4[]="     wu     rang     hao     " ;//�ո����ַ�����ǰ�桢�м䡢��������� (5��)
	char str5[4];//��str5ΪNULL 
	char str6[]="" ;
	char str7[]=" "; //��һ���ո� 
	char str8[]="     ";//��5���ո� 
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
