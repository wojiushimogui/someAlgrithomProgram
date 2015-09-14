/*
��Ŀ������
�������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�����һ�����飬�����������е�����Ե�������
���룺
ÿ�����԰����������У�
��һ�а���һ������n����ʾ�����е�Ԫ�ظ���������1 <= n <= 10^5��
�ڶ��а���n��������ÿ�������Ϊint���͡�
�����
��Ӧÿ�����԰��������һ����������ʾ�����е�����Ե�������
�������룺
4
7 5 6 4
���������
5
*/
/*
��һ�ַ�����˼·����������forѭ����ͳ��ÿ����ǰ����ڸ������� ��ʱ�临�Ӷ�ΪO(n*n) 
�����ṩ����һ�ַ������������� ���ŵ�˼���������Ե�ͳ�� 
*/

#include<stdio.h>
#include<stdlib.h>

long long mergeStatisticsReverseNum(int *arr,int start,int mid,int end){
	if(arr==NULL||start>end){
		return 0;
	}
	//���濪ʼ�鲢��ͳ������Եĸ���
	//�ȶ���������ʱ���������������
	int lenSubArr1=mid-start+1;//��һ��������ĳ��� 
	int lenSubArr2=end-mid;//�ڶ���������ĳ��� 
	int subArr1[lenSubArr1];
	int subArr2[lenSubArr2];
	
	for(int i=0;i<lenSubArr1;i++){
		subArr1[i]=arr[i+start];
	} 
	for(int j=0;j<lenSubArr2;j++){
		subArr2[j]=arr[mid+1+j];
	}
	
	int indexSubArr1=0;
	int indexSubArr2=0;
	int indexTotalArr=0;
	long long count=0;//ͳ����������ı��� 
	
	while(indexSubArr1<lenSubArr1&&indexSubArr2<lenSubArr2){ 
		if(subArr1[indexSubArr1]<=subArr2[indexSubArr2]){//��һ���������Ԫ�ؽ�С����� 
			arr[indexTotalArr]=subArr1[indexSubArr1];
			indexTotalArr++;
			indexSubArr1++; 
		}
		else{//�ڶ����������Ԫ�ؽ�С����� ����ʱ�����һ�������
			count++; 
			arr[indexTotalArr]=subArr2[indexSubArr2];
			indexTotalArr++;
			indexSubArr2++; 
		}
	}
	//����������subArr1��aubArr2ʣ���Ԫ�ؿ�����arr�� 
	while(indexSubArr1<lenSubArr1){//����������������ԣ���������Եĸ���Ϊ����һ��������ʣ�����-1��*�ڶ���������Ԫ�صĸ���;���� 3 4 5��1 2����1 2���뵽arr�к� 
			count+=lenSubArr2; 
			arr[indexTotalArr]=subArr1[indexSubArr1];
			indexTotalArr++;
			indexSubArr1++; 
			if(indexSubArr1==lenSubArr1-1){//����1* �ڶ���������Ԫ�صĸ�������ֹ�ظ�ͳ�Ʊ߽��Ǹ���������� 
				count-=lenSubArr2;
			} 
	}
	while(indexSubArr2<lenSubArr2){//�������û�в�������� 
			arr[indexTotalArr]=subArr2[indexSubArr2];
			indexTotalArr++;
			indexSubArr2++; 
	}
	return count; 
}
//����������Ԫ�صĸ���Ϊ1 <= n <= 10^5�� �������Եĸ������Ͻ�Ϊ�Ȳ����еĺͣ���10^5-1��*10^5/2 
//������int�͵����ֵ����Լ2*10^9��,��˽�����ֵ��Ϊ long long���� 
long long  statisticsReverseNumInTotalArrayByMerge(int *arr,int start,int end){
	if(arr==NULL||start>=end){
		return 0;
	}
	long long count=0;
	int mid=start+(end-start)/2;
	count+=statisticsReverseNumInTotalArrayByMerge(arr,start,mid);
	count+=statisticsReverseNumInTotalArrayByMerge(arr,mid+1,end);
	count+=mergeStatisticsReverseNum(arr,start,mid,end);
	return count;	
}
void input(int *arr,int n){
	if(arr==NULL||n<=0){
		return;
	}
	for(int i=0;i<n;i++){
		scanf("%d",arr+i);
	}
}

int main(void){
	int n;
	while(scanf("%d",&n)!=EOF){
		int *arr=(int *)malloc(n*sizeof(int));
		if(arr==NULL){
			exit(EXIT_FAILURE);
		}
		input(arr,n);
		printf("%lf",statisticsReverseNumInTotalArrayByMerge(arr,0,n-1));
		free(arr);
		arr=NULL;
	}
	return 0;
} 
