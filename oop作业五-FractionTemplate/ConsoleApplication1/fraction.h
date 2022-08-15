#pragma once
#define _CRT_SECURE_NO_WARNINGS
/*ͷ�ļ�����*/
#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
/*�궨��*/
#define INF -1
#define NUMBER 0
#define NAN 1
using namespace std;
/*define class*/
class Fraction {
private :
	int numerator;//����
	int denominator;//��ĸ
	int flag;//�����Ϸ���־
	void Simply();//�����Զ���Լ�ֻ���ģ��
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