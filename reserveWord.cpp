/*
��ת����˳��
���룺
ÿ�����԰���Ϊһ�У���ʾһ��Ӣ�ľ��ӡ�
���Ǳ�֤һ�����ӵĵ��������ᳬ��600��ÿ�����ʵĳ���Ҳ���ᳬ��30��������Ҫע�����Fish�Ǹ�����С�ڵ��ˣ���ʱ�����������м���ܻ��кܶ�ո�Ϊ�˷���������������Ϊһ�е��ַ��������ᳬ��50000���������ſ��Ժ���ͨ��ĸһ������
�����
��Ӧÿ�����԰������ѷ�ת�����ȷ�ľ��ӵ������һ�С�

�������룺
student. a am I
I'm a Freshman and I like JOBDU!
���������
I am a student.
JOBDU! like I and Freshman a I'm 

�����������ո�Ҳ��Ҫ��ת 
1�� student. a am I���������룬�����뵥��֮��ֻ��һ���ո� 
2�� student.       a       am I���������룬�����뵥��֮���ж���ո�
3��"    "(ֻ�пո񹹳�)
4��NULL 
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
//�Կո�����Ϊ�ָ�ʵĽ���
/*
@param str:�ַ���
@param begin:ָ���ַ�����һ���ǿո���ַ� 
@param end:ָ���ַ������һ���ǿո���ַ� 
*/ 
void reverseWord(char *str,int begin,int end){
	int index=begin;
	while(index<=end){
		if(str[index]!=' '){
			index++;
		}
		else{
			//�������ո�ʱ begin  �� index֮����һ�����ʣ�����ո�ķ�ʽ���ǲ�����ֱ���������ɣ���Ϊ�ڴ���ո��ʱ��begin==index 
			if(begin<index){
				reverseString(str,begin,index-1);
			} 
		
			index++;//�����������ǣ�����ո�ķ�ʽ���ǲ�����ֱ������
			begin=index;
			
			/*
			��������ո�
			while(str[index]==' '){
			index++;
			} 
			
			
			*/ 
		 
		}
	}
	
}
//��ת�ַ��� 
void reverseString(char *str,int begin,int end){
	//�ж�str�Ƿ���Ч 
	if(str==NULL||begin>=end){//begin=endΪֻ��һ���ַ�������Ҫ���أ�ֻ���� 
		return;
	}

//	int begin=0;
//	int end=len-1;
	//����ַ��Ƿ�ȫ���ɿո����,���ǣ����˳� 
	//��������ָ��begin��end���ֱ�ָ���ַ��������ַ���β�ַ�
	int index=0; 
	while(index<=end){
		if(str[index]!=' '){
			break;
		}
		else{
			index++; 
		} 
		
	}
	if(index==end){//���begin==len,��˵�����ַ���ȫ���ɿո���� 
		return;
	} 

	
	//��begin��end�ݴ���temp_begin��temp_end 
	int temp_begin=begin;
	int temp_end=end;
	while(begin<end){
		swap(str,begin,end);//����������λ�õ��ַ� 
		++begin;
		--end;
	}
	
	//��ת����
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
