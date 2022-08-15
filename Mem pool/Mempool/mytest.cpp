#include <iostream>
#include <random>
#include <vector>
#include<Windows.h>
#include<iomanip>
#include<list>
#include "MyAllocator.h"

template<class T>
using MyAllocator = Alloc::MyAllocator<T>; // replace the std::allocator with your allocator
template<class T>
using IniAllocator = std::allocator<T>;
using Point2D = std::pair<int, int>;
using namespace std;
const int TestSize = 10000;
const int PickSize = 1000;
const int test_size = 10;
double time_counter[2][10][test_size];
double time_counter_list[2][10][test_size];
int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	//std::uniform_int_distribution<> dis(1, TestSize);
	int distr[10] = { 8,32,64,128,256,512,1024,2000,5000,10000 };
	LARGE_INTEGER t1, t2, t3,t4,tc;//high precision clock
	double time_t1=0,time_t2=0;
    QueryPerformanceFrequency(&tc);//record frequency of the clock in cpu
	/*test for vector*/
	using IntVec = std::vector<int, MyAllocator<int>>;
	using IntVec_t = std::vector<int>;
	std::vector<IntVec, MyAllocator<IntVec>> vecints(TestSize);
	std::vector<IntVec_t> vecints_t(TestSize);

	for (int j = 0; j < 10; j++) {
	//实验组，使用自定义内存分配器
		std::uniform_int_distribution<> dis(1, distr[j]);
		time_t1 = 0;
		time_t2 = 0;
		for (int i = 0; i < TestSize; i++) {
			size_t size = dis(gen);
			QueryPerformanceCounter(&t1);
			vecints[i].resize(size);
			QueryPerformanceCounter(&t2);
			time_t1 += (double)((t2.QuadPart - t1.QuadPart) * 1000.0 / tc.QuadPart);
			if (i % 1000 == 0) {
				time_counter[0][j][i / 1000] = time_t1;
			}
		}
		//对照组，使用std::allocator
		for (int i = 0; i < TestSize; i++) {
			size_t size = dis(gen);
			QueryPerformanceCounter(&t3);
			vecints_t[i].resize(size);
			QueryPerformanceCounter(&t4);
			time_t2 += (double)((t4.QuadPart - t3.QuadPart) * 1000.0 / tc.QuadPart);
			if (i % 1000 == 0) {
				time_counter[1][j][i / 1000] = time_t2;
			}
		}
	}
	
	cout << "vector test result" << endl;
	for (int j = 0; j < 10; j++) {
		cout << "when resize is between 0 and " << distr[j] << endl<<endl;
		cout << setw(15) << setiosflags(ios::left) << "input scale:";
		for (int i = 0; i < 10000; i += 1000)cout << setw(10) << i;
		cout << endl;
		cout << setw(15) << setiosflags(ios::left) << "myallocator:";
		for (int i = 0; i < test_size; i++) {
			cout << setw(10) << time_counter[0][j][i] ;
		}
		cout << endl;
		cout << setw(15) << setiosflags(ios::left) << "std::allocator:";
		for (int i = 0; i < test_size; i++) {
			cout << setw(10) << time_counter[1][j][i] ;
		}
		cout << endl;
	}
}