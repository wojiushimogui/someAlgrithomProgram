#include<stdio.h>

int main(){
	int a[5]={1,2,3,4,5};
	int *p;
	int **k;
	p=a;
	k=&p;
	printf("%d",*p);
	printf("%d",*p++);//*p++与*(p++)是等价的 
	printf("%d\n",a[0]);
	
	printf("%d",(*p)++);//*p++与*(p++)是等价的 
	printf("%d\n",a[1]);
	 
	printf("%d",*(p++));//先输出p所指向的值，然后指针p+1 
	printf("%d",**k);
	return 0;
}
