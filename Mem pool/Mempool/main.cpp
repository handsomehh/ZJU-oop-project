#define TEST_TYPE 1//当这个数值设置为1时，对应pta的测试程序，当设置为0时，对应课程钉钉群上传的测试程序

#if TEST_TYPE
#include "MyAllocator.h"
#include <vector>
#include <iostream>

#define INT 1
#define FLOAT 2
#define DOUBLE 3
#define CLASS  4

#define MyAllocator Alloc::MyAllocator

class vecWrapper
{
public:
	vecWrapper() {
		m_pVec = NULL;
		m_type = INT;
	}
	virtual ~vecWrapper() {
	}
public:
	void setPointer(int type, void* pVec) { m_type = type; m_pVec = pVec; }
	virtual void visit(int index) = 0;
	virtual int size() = 0;
	virtual void resize(int size) = 0;
	virtual bool checkElement(int index, void* value) = 0;
	virtual void setElement(int idex, void* value) = 0;
protected:
	int m_type;
	void* m_pVec;
};

template<class T>
class vecWrapperT : public vecWrapper
{
public:
	vecWrapperT(int type, std::vector<T, MyAllocator<T> >* pVec)
	{
		m_type = type;
		m_pVec = pVec;
	}
	virtual ~vecWrapperT() {
		if (m_pVec)
			delete ((std::vector<T, MyAllocator<T> > *)m_pVec);
	}
public:
	virtual void visit(int index)
	{
		T temp = (*(std::vector<T, MyAllocator<T> > *)m_pVec)[index];
	}
	virtual int size()
	{
		return ((std::vector<T, MyAllocator<T> > *)m_pVec)->size();
	}
	virtual void resize(int size)
	{
		((std::vector<T, MyAllocator<T> > *)m_pVec)->resize(size);
	}
	virtual bool checkElement(int index, void* pValue)
	{
		T temp = (*(std::vector<T, MyAllocator<T> > *)m_pVec)[index];
		if (temp == (*((T*)pValue)))
			return true;
		else
			return false;
	}

	virtual void setElement(int index, void* value)
	{
		(*(std::vector<T, MyAllocator<T> > *)m_pVec)[index] = *((T*)value);
	}
};

class myObject
{
public:
	myObject() : m_X(0), m_Y(0) {}
	myObject(int t1, int t2) :m_X(t1), m_Y(t2) {}
	myObject(const myObject& rhs) { m_X = rhs.m_X; m_Y = rhs.m_Y; }
	~myObject() { /*std::cout << "my object destructor called" << std::endl;*/ }
	bool operator == (const myObject& rhs)
	{
		if ((rhs.m_X == m_X) && (rhs.m_Y == m_Y))
			return true;
		else
			return false;
	}
protected:
	int m_X;
	int m_Y;
};

#define TESTSIZE 10000

int main()
{
	vecWrapper** testVec;
	testVec = new vecWrapper * [TESTSIZE];

	int tIndex, tSize;
	//test allocator
	for (int i = 0; i < TESTSIZE - 4; i++)
	{
		tSize = (int)((float)rand() / (float)RAND_MAX * 100);
		vecWrapperT<int>* pNewVec = new vecWrapperT<int>(INT, new std::vector<int, MyAllocator<int>>(tSize));
		testVec[i] = (vecWrapper*)pNewVec;
		//std::cout << i<<std::endl;
	}

	for (int i = 0; i < 4; i++)
	{
		tSize = (int)((float)rand() / (float)RAND_MAX * 10000);
		vecWrapperT<myObject>* pNewVec = new vecWrapperT<myObject>(CLASS, new std::vector<myObject, MyAllocator<myObject>>(tSize));
		testVec[TESTSIZE - 4 + i] = (vecWrapper*)pNewVec;
	}

	//test resize
	for (int i = 0; i < 100; i++)
	{
		tIndex = (int)((float)rand() / (float)RAND_MAX * (float)TESTSIZE);
		tSize = (int)((float)rand() / (float)RAND_MAX * (float)TESTSIZE);
		testVec[tIndex]->resize(tSize);
	}

	//test assignment
	tIndex = (int)((float)rand() / (float)RAND_MAX * (TESTSIZE - 4 - 1));
	int tIntValue = 10;
	testVec[tIndex]->setElement(testVec[tIndex]->size() / 2, &tIntValue);
	if (!testVec[tIndex]->checkElement(testVec[tIndex]->size() / 2, &tIntValue))
		std::cout << "incorrect assignment in vector %d\n" << tIndex << std::endl;

	tIndex = TESTSIZE - 4 + 3;
	myObject tObj(11, 15);
	testVec[tIndex]->setElement(testVec[tIndex]->size() / 2, &tObj);
	if (!testVec[tIndex]->checkElement(testVec[tIndex]->size() / 2, &tObj))
		std::cout << "incorrect assignment in vector %d\n" << tIndex << std::endl;

	myObject tObj1(13, 20);
	if (!testVec[tIndex]->checkElement(testVec[tIndex]->size() / 2, &tObj1))
		std::cout << "incorrect assignment in vector " << tIndex << " for object (13,20)" << std::endl;

	for (int i = 0; i < TESTSIZE; i++)
		delete testVec[i];

	delete[]testVec;
	system("pause");
	return 0;

}

#else
#include <iostream>
#include <random>
#include <vector>
#include "MyAllocator.h"

template<class T>
using MyAllocator = Alloc::MyAllocator<T>; // replace the std::allocator with your allocator
using Point2D = std::pair<int, int>;

const int TestSize = 10000;
const int PickSize = 1000;
int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, TestSize);
	// vector creation
	using IntVec = std::vector<int, MyAllocator<int>>;
	std::vector<IntVec, MyAllocator<IntVec>> vecints(TestSize);
	for (int i = 0; i < TestSize; i++) {
		size_t size = dis(gen);
		// std::cout << i << " " << size << std::endl;
		vecints[i].resize(size);
	}


	using PointVec = std::vector<Point2D, MyAllocator<Point2D>>;
	std::vector<PointVec, MyAllocator<PointVec>> vecpts(TestSize);
	for (int i = 0; i < TestSize; i++)
		vecpts[i].resize(dis(gen));

	// vector resize
	for (int i = 0; i < PickSize; i++)
	{
		int idx = dis(gen) - 1;
		int size = dis(gen);
		vecints[idx].resize(size);
		vecpts[idx].resize(size);
	}

	// vector element assignment
	{
		int val = 10;
		int idx1 = dis(gen) - 1;
		int idx2 = vecints[idx1].size() / 2;
		vecints[idx1][idx2] = val;
		if (vecints[idx1][idx2] == val)
			std::cout << "correct assignment in vecints: " << idx1 << std::endl;
		else
			std::cout << "incorrect assignment in vecints: " << idx1 << std::endl;
	}
	{
		Point2D val(11, 15);
		int idx1 = dis(gen) - 1;
		int idx2 = vecpts[idx1].size() / 2;
		vecpts[idx1][idx2] = val;
		if (vecpts[idx1][idx2] == val)
			std::cout << "correct assignment in vecpts: " << idx1 << std::endl;
		else
			std::cout << "incorrect assignment in vecpts: " << idx1 << std::endl;
	}

	return 0;
}
#endif