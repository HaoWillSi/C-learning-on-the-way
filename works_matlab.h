#根据自己的需要写了一些类似于MATLAB里功能的函数，比如序列求和，最值，保留小数点
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include<iostream>
#include<fstream>
#include<string> 
#include<vector>

using namespace std;
double getmin(double *arr,int count)//数组中的最小值
{
	double temp=arr[0];
	for(int i=1;i<count;i++){
		if(temp>arr[i]){
			temp=arr[i];
		}		
	}
	return temp;	
}

double getmax(double *arr,int count)//数组中的最小值
{
	double temp=arr[0];
	for(int i=1;i<count;i++){
		if(temp<arr[i]){
			temp=arr[i];
		}		
	}	
	return temp;
}

double sum(double *arr,int onset,int offset)//数组的求和，指定起始位置
{
	double temp;
	for(int i=onset;i<=offset;i++){
		temp += arr[i];
	}	
	return temp;
}

//Rounding to retain N decimal places 保留小数点后几位数字
double round(double number, unsigned int bits) {
    double integerPart = floor(number);
    number -= integerPart;
    for (unsigned int i = 0; i < bits; ++i)
        number *= 10;
    number = floor(number + 0.5);
    for (unsigned int i = 0; i < bits; ++i)
        number /= 10;
    return integerPart + number;
}


double *linspace(double onset,double offset,int num){
	//vector<double> temp(num);
	 double *temp = new double[num];
	double delt;
	delt = (offset-onset)/(num-1);
	for(int i=0;i<num;i++){
		temp[i]=onset + delt*i;
	}
	return temp;	
	delete []temp;
}

int *randperm(int Num)//产生1到Num的Num个数字的随机排序
{
	int *temp1 = new int[Num];
    vector<int> temp;
    for (int i = 0; i < Num; ++i)
    {
        temp.push_back(i + 1);
    }

    random_shuffle(temp.begin(), temp.end());

    for (int i = 0; i < temp.size(); i++)
    {
        temp1[i] = temp[i];
    }
    return temp1;
    delete []temp1;
}
