/*
面试题11：数值的整数次方 
题目：实现函数double Power(double base,int exponent), 
求base的exponent次方，不得使用库函数，同时不需要考虑大数问题
*/
/*需要考虑的测试用例如下
//base、exponent两者都不为零的情况 
 base=3 ,exponent=4//基数和指数均为正数
 base=-3,exponent=4//基数为负，指数为正
 base=3，exponent=-4//基数为正，指数为负
 base=-3，exponent=-4//基数、指数均为正
 
 //base、exponent至少有一个为零的情况 
 
 base=0,exponent=1
 base=0,exponent=-1//特别要注意 
 base=0,exponent=0 

*/


#include<stdio.h>
//定义一个全局变量，来标志输入是否有效，当输入无效（ base=0,exponent=-1//特别要注意 ）的时候，该值为true 
bool  g_InvalidInput=false; 
bool my_equal(double base,double num){
	if(base-num<0.0001&&base-num>-0.0001){
		return true;
	}
	return false;
}

/*功能：更高效的完成数值的整数次方的运算 
比for(int i=0;i<exponent;i++){
        result*=base;
    }更高效 
@param base:基数
@param exponent:指数  且大于等于0 
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
	g_InvalidInput=false;//初始化为false，目的是为了防止多次调用该函数，g_InvalidInput的标志位被设置为了true，对后面的调用的结果产生一定的影响 
	//先判断输入是否有效，即判断是否出现了 base=0,exponent=-1这种情况
	/*因为base为double型数据，因此不能直接用base==0来判断其是否等于0，
	这是因为计算机内表示小数时（包括float和double）都有一定的误差 ，
	因此判断两个小数是否相等，只能判断他们之差的绝对值是否在一定的范围内 */
	if(my_equal(base,0.0)&&exponent<0){
		g_InvalidInput=true;
		return 0.0;
	} 
	
	//将0的0次方单独拿出来考虑
	if(my_equal(base,0.0)&&exponent==0) {
		return 1.0;
	}
    double result=1.0;
    int negative=1;//指数是否为负数的标志位 
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
 //   scanf("%lf",&base);//这里注意的是：对于double类型的输入的格式为：“%lf” 
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
