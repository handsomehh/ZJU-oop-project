#include"Fraction.h"
/*function: copy
* -----------------------------------------------------
* usage: copy the class and return a same fraction
* call way: B = A.copy(),same as B = A
*/
Fraction Fraction::copy() {
	return Fraction(numerator, denominator);
}
/*function: operator =
* -----------------------------------------------------
* usage: assign
* call way:  B = A,make B's elements same as A
*/
Fraction& Fraction::operator=(const Fraction& r){
	if (this != &r) {
		denominator = r.denominator;
		numerator = r.numerator;
		flag = r.flag;
	}
	return *this;
}
/*function: operator +
* -----------------------------------------------------
* usage:add
* call way:  B + A,return a class
* INF+INF = INF
* NAN + anything is NAN
*/
const Fraction Fraction::operator+(const Fraction& r)const {
	if (r.flag == NAN || flag == NAN) return Fraction(0,0);
	else if (r.flag == INF || flag == INF)return Fraction(1, 0);
	else return Fraction( numerator * r.denominator + r.numerator * denominator, denominator * r.denominator);
}
/*function: operator -
* -----------------------------------------------------
* usage:sub
* call way:  B - A,return a class
* INF-INF = INF
* NAN - anything is NAN
*/
const Fraction Fraction::operator-(const Fraction& r)const {
	if (r.flag == NAN || flag == NAN) return Fraction(0, 0);
	else if (r.flag == INF || flag == INF)return Fraction(1, 0);
	else return Fraction( numerator * r.denominator - r.numerator * denominator, denominator * r.denominator);
}
/*function: operator *
* -----------------------------------------------------
* usage:multiply
* call way:  B * A,return a class
* INF*INF = INF
* NAN * anything is NAN
*/
const Fraction Fraction::operator*(const Fraction& r)const {
	if (r.flag == NAN || flag == NAN) return Fraction(0, 0);
	else if (r.flag == INF || flag == INF)return Fraction(1, 0);
	return Fraction(numerator*r.numerator, denominator*r.denominator);
}
/*function: operator /
* -----------------------------------------------------
* usage:divisor
* call way:  B / A,return a class
* INF/INF = INF
* NAN / anything is NAN
*/
const Fraction Fraction::operator/(const Fraction& r)const {
	if (r.flag == NAN || flag == NAN) return Fraction(0, 0);
	else if (r.flag == INF || flag == INF)return Fraction(1, 0);
	return Fraction(numerator * r.denominator, denominator * r.numerator);
}
/*function: operator <
* -----------------------------------------------------
* usage:judge small
* call way:  B < A,return a bool
*/
bool Fraction::operator<(const Fraction& r)const {
	if (r.flag == INF || flag == INF)return false;
	else return double(*this) < double(r);
}
/*function: operator >
* -----------------------------------------------------
* usage:judege big
* call way:  B > A,return a bool
*/
bool Fraction::operator<=(const Fraction& r)const {
	if (r.flag == INF || flag == INF)return false;
	else return double(*this) <= double(r);
}
/*function: operator ==
* -----------------------------------------------------
* usage:judege equal
* call way:  B == A,return a bool
*/
bool Fraction::operator==(const Fraction& r)const {
	if (r.flag == INF || flag == INF)return false;
	 return double(*this) == double(r);
}
/*function: operator !=
* -----------------------------------------------------
* usage:judege unequal
* call way:  B != A,return a bool
*/
bool Fraction::operator!=(const Fraction& r)const {
	if (r.flag == INF || flag == INF)return false;
	else return double(*this) != double(r);
}
/*function: operator >=
* -----------------------------------------------------
* usage:judege big and equal
* call way:  B >= A,return a bool
*/
bool Fraction::operator>=(const Fraction& r)const {
	return !((*this) < r);
}
/*function: operator >
* -----------------------------------------------------
* usage:judege big
* call way:  B > A,return a bool
*/
bool Fraction::operator>(const Fraction& r)const {
	return !((*this) <= r);
}
/*function: operator double
* -----------------------------------------------------
* usage:cast to double
* call way:  double(A),return a double
*/
Fraction::operator double() const {
		return double(numerator) / denominator;
}
/*function: operator string
* -----------------------------------------------------
* usage:cast to string()
* call way:  string(A),return a double
*/
Fraction::operator string() const {
	if (flag == NAN)return "NAN";
	else if (flag == INF)return "INF";
	else {
		if (double(*this) < 0) {
			if (abs(denominator) == 1)return "-" +std::to_string(abs(numerator));
			else return "-(" + std::to_string(abs(numerator) )+ "/" + std::to_string(abs(denominator) )+ ")";
		}
		else if (double(*this) > 0) {
			if (abs(denominator) == 1)return std::to_string(abs(numerator));
			else return  std::to_string(abs(numerator) )+ "/" + std::to_string(abs(denominator));
		}
		else {
			return "0";
		}
	}
}
/*function: simply()
* -----------------------------------------------------
* usage:»¯¼ò·ÖÊý
*/
void Fraction::Simply() {
	if (flag == NAN || flag == INF)return;
	else {
		int min = (int)fabs(numerator)> (int)fabs(denominator)? (int)fabs(denominator): (int)fabs(numerator);
		for (int i = 2; i <=min; i++) {
			if (numerator % i == 0 && denominator % i == 0) {
				numerator /= i;
				denominator /= i;
				Fraction::Simply();
				break;
			}
		}
	}
}

Fraction::Fraction() {
	numerator = 0;
	denominator = 1;
	flag = NUMBER;
}
Fraction::Fraction(int a, int b) {
	numerator = a;
	denominator = b;
	if (b == 0 && a == 0) {
		flag = NAN;
	}
	else if (b == 0) {
		flag = INF;
	}
	else {
		flag = NUMBER;
		Fraction::Simply();
	}
}
/*function:to_int
* -----------------------------------------------------
* usage:cast char* to int
* call way:  to_int(p),return a int
*/
int to_int(char* p) {
	int i,sum=0;
	for (i = 0; p[i] != '\0'; i++) {
		if (p[i] < '0' || p[i]>'9')return -1;
		sum = sum * 10 + p[i] - '0';
	}
	return sum;
}
/*function:Fraction(string str)
* -----------------------------------------------------
* usage:initial by string
* call way:  Fraction A(str);
*				  Fraction A = str;
*/
Fraction::Fraction(string str) {
	char ch[100], * p;
	strcpy(ch, str.c_str());
	if (str.find('.')==-1) {
		int tmp1 = to_int(ch);
		numerator = tmp1;
		denominator = 1;
		flag = NUMBER;
	}
	else {
		p = strtok(ch, ".");
		int tmp1 = to_int(p);
		p = strtok(NULL, ".");
		int tmp2 = to_int(p);
		int tmp3 = tmp2;
		int index = 1;
		while (tmp3 > 0) {
			tmp3 = tmp3 / 10;
			index *= 10;
		}
		Fraction a1(tmp1, 1), a2(tmp2, index), a3;
		a3 = a1 + a2;
		pair<int, int> k = a3.ReadEle();
		int flag_f = a3.readflag();
		numerator = k.first;
		denominator = k.second;
		flag = flag_f;
	}
}
/*function: operator >>
* -----------------------------------------------------
* usage: input stream
* call way:  cin>>A,file>>A
*/
istream& operator>>(istream& is, Fraction& obj) {
	int i1, i2;
	char ch;
	is >> i1>>ch>>i2;
	if (ch == '/') {
		Fraction tmp(i1,i2);
		obj = tmp.copy();
	}
	return is;
}
/*function: operator <<
* -----------------------------------------------------
* usage: output stream
* call way:  cout<<A,FIle<<A
*/
ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.flag == INF) { os << "INF"; }
	else if (obj.flag == NAN) { os << "NAN"; }
	else {
		if (double(obj) < 0) {
			if (abs(obj.denominator) == 1)os << "-" << abs(obj.numerator) ;
			else os << "-(" << abs(obj.numerator) << "/" << abs(obj.denominator) << ")";
		}
		else if (double(obj) > 0) {
			if (abs(obj.denominator) == 1)os << abs(obj.numerator);
			else os << abs(obj.numerator) << "/" << abs(obj.denominator);
		}
		else {
			os << "0";
		}
	}
	return os;
}