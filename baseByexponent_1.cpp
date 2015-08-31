/*
������11����ֵ�������η� 
��Ŀ��ʵ�ֺ���double Power(double base,int exponent), 
��base��exponent�η�������ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ�������
*/
/*��Ҫ���ǵĲ�����������
//base��exponent���߶���Ϊ������ 
 base=3 ,exponent=4//������ָ����Ϊ����
 base=-3,exponent=4//����Ϊ����ָ��Ϊ��
 base=3��exponent=-4//����Ϊ����ָ��Ϊ��
 base=-3��exponent=-4//������ָ����Ϊ��
 
 //base��exponent������һ��Ϊ������ 
 
 base=0,exponent=1
 base=0,exponent=-1//�ر�Ҫע�� 
 base=0,exponent=0 

*/


#include<stdio.h>
//����һ��ȫ�ֱ���������־�����Ƿ���Ч����������Ч�� base=0,exponent=-1//�ر�Ҫע�� ����ʱ�򣬸�ֵΪtrue 
bool  g_InvalidInput=false; 
bool my_equal(double base,double num){
	if(base-num<0.0001&&base-num>-0.0001){
		return true;
	}
	return false;
}

/*���ܣ�����Ч�������ֵ�������η������� 
��for(int i=0;i<exponent;i++){
        result*=base;
    }����Ч 
@param base:����
@param exponent:ָ��  �Ҵ��ڵ���0 
*/
double PowerWithUnsiginedExponent(double base,int exponent){
	if(exponent==0){
		return 1.0;
	}
	if(exponent==1){
		return base;
	} 
	double result=PowerWithUnsiginedExponent(base,exponent>>1);
	result*=result;
	if(exponent&0x01){
		result*=base;
	}
	return result; 
	
}
double  my_Power(double base,int exponent){
	g_InvalidInput=false;//��ʼ��Ϊfalse��Ŀ����Ϊ�˷�ֹ��ε��øú�����g_InvalidInput�ı�־λ������Ϊ��true���Ժ���ĵ��õĽ������һ����Ӱ�� 
	//���ж������Ƿ���Ч�����ж��Ƿ������ base=0,exponent=-1�������
	/*��ΪbaseΪdouble�����ݣ���˲���ֱ����base==0���ж����Ƿ����0��
	������Ϊ������ڱ�ʾС��ʱ������float��double������һ������� ��
	����ж�����С���Ƿ���ȣ�ֻ���ж�����֮��ľ���ֵ�Ƿ���һ���ķ�Χ�� */
	if(my_equal(base,0.0)&&exponent<0){
		g_InvalidInput=true;
		return 0.0;
	} 
	
	//��0��0�η������ó�������
	if(my_equal(base,0.0)&&exponent==0) {
		return 1.0;
	}
    double result=1.0;
    int negative=1;//ָ���Ƿ�Ϊ�����ı�־λ 
    if(exponent<0){
        negative=-1;
        exponent=-exponent; 
    }
    result=PowerWithUnsiginedExponent( base, exponent);
   // printf("%lf\n",result);
   // printf("%lf\n",1.0/result);
    return (negative==1?result:(1.0/result));
} 


int main(void){
    double base;
    int exponent;
 //   scanf("%lf",&base);//����ע����ǣ�����double���͵�����ĸ�ʽΪ����%lf�� 
 //   scanf("%d",&exponent); 
 //   printf("%lf\n",Power(base,exponent));
    
    printf("%lf\n",my_Power(3.0,4));
    printf("%lf\n",my_Power(-3.0,4));
    printf("%lf\n",my_Power(3.0,-1));
    printf("%lf\n",my_Power(0.0,-1));
    printf("%lf\n",my_Power(0.0,1));
    printf("%lf\n",my_Power(0.0,0));
    return 0;
}
