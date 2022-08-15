#pragma once
#define _CRT_SECURE_NO_WARNINGS
/*头文件引用*/
#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
/*宏定义*/
#define INF -1
#define NUMBER 0
#define NAN 1
using namespace std;
/*define class*/
class Fraction {
private :
	int numerator;//分子
	int denominator;//分母
	int flag;//分数合法标志
	void Simply();//分数自定义约分化简模块
public:
	/*Initial of the class*/
	Fraction();//default initial 0 to class
	Fraction(int a, int b);//initial class by two integer
	Fraction(string str);//initial class by string
	/*operator list*/
	Fraction copy();//copy function,return a same class element
	friend istream& operator>>(istream& is, Fraction& obj);//operator overload >>
	friend ostream& operator<<(ostream& os, const Fraction& obj); //operator overload <<
	const Fraction operator+(const Fraction& r)const;//operator overload +
	const Fraction operator-(const Fraction& r)const;//operator overload -
	const Fraction operator*(const Fraction& r)const;//operator overload *
	const Fraction operator/(const Fraction& r)const;//operator overload /
	Fraction& operator=(const Fraction& r);//operator overload =
	bool operator<(const Fraction& r)const;//operator overload <
	bool operator<=(const Fraction& r)const;//operator overload <=
	bool operator==(const Fraction& r)const;//operator overload ==
	bool operator!=(const Fraction& r)const;//operator overload !=
	bool operator>=(const Fraction& r)const;//operator overload >=
	bool operator>(const Fraction& r)const;//operator overload >
	operator double() const;//cast to double
	operator string() const;//cast to string
	int readflag() { return flag; };//read flag
	pair<int, int> ReadEle() {//read elements in class
		return make_pair(numerator, denominator);
	}
	~Fraction() {};
};