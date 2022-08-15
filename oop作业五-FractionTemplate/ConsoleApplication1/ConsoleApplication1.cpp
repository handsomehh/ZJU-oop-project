#include"fraction.h"
#include<fstream>

int main() {
	/*测试数据，将5个读入数据放在1.txt,将会在result中输出相关操作的结果*/
	ifstream File("1.txt");
	ofstream File2("result.txt");
	Fraction A, B, C, D,E;
	File >> A >> B >> C >> D>>E;
	File2 << "A:" << A << endl;
	File2 << "B:" << B<< endl;
	File2 << "C:" << C<< endl;
	File2 << "D:" << D << endl;
	File2 << "E:" << E << endl;
	File2 << "A+B=" << A + B << endl;
	File2 << "A-B=" << A - B << endl;
	File2 << "A*B=" << A * B << endl;
	File2 << "A/B=" << A / B << endl;
	File2 << "A<B:" << (A < B) << endl;
	File2 << "A<=B:" << (A <= B) << endl;
	File2 << "A==B:" << (A == B) << endl;
	File2 << "A!=B:" << (A != B )<< endl;
	File2 << "A>=B:" << (A >= B) << endl;
	File2 << "A>B:" << (A > B) << endl;
	File2 << "非常规数参与运算A*D:" << A*D << endl;
	File2 << "非常规数参与运算A/C:" << A /C << endl;
	File2 << "非常规数输出A/E:" << A /E << endl;
	File2 << "强转double(A)" << double(A) << endl;
	File2 << "强转字符串string(A)：" << "这是一个"+string(A)+"字符串" << endl;
	Fraction F("12.5");
	File2 << "用小数string初始化:" << F << endl;
	string tmp="0.125";
	F = tmp;
	File2 << "用小数赋值例1:" << F << endl;
	tmp = "11";
	F = tmp;
	File2 << "用小数赋值例2:" << F << endl;
	F = A;
	File2 << "用其他变量赋值：" << F << endl;
	File.close();
	File2.close();
}