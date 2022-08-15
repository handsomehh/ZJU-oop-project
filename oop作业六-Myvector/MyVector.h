#pragma once
#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;
template <class T>
class Vector {
public:
	Vector();                      // creates an empty vector
	Vector(int size);              // creates a vector for holding 'size' elements
	Vector(const Vector& r);       // the copy ctor
	~Vector();                     // destructs the vector 
	T& operator[](int index);      // accesses the specified element without bounds checking
	T& at(int index);              // accesses the specified element, throws an exception of type 'std::out_of_range' when index <0 or >=m_nSize
	int size() const;         // return the size of the container
	void push_back(const T& x);    // adds an element to the end 
	void clear();                  // clears the contents
	bool empty() const;            // checks whether the container is empty
	//friend ostream& operator<<(ostream& os, const Vector<T>& obj);
	inline int GetSize() { return m_nSize; }
	inline int GetCap() { return m_nCapacity; }
private:
	void inflate();                // expand the storage of the container to a new capacity, e.g. 2*m_nCapacity
	T* m_pElements;                // pointer to the dynamically allocated storage
	int m_nSize;                   // the number of elements in the container
	int m_nCapacity;               // the number of elements that can be held in currently allocated storage
};
template <class T>
Vector<T>::Vector() {//constructor function
	m_nSize = 0;
	m_nCapacity = 0;
	m_pElements = nullptr;
}

template <class T>
Vector<T>::Vector(int size) {//constructor by size interger
	m_nSize = 0;
	if (size >= 0)m_nCapacity = size;//make sure capacity is bigger than 0
	else m_nCapacity = 0;
	m_pElements = new T[size];
}

template <class T>
Vector<T>::Vector(const Vector& r) {//constructor by other vector
	m_nCapacity = r.m_nCapacity;
	m_nSize = r.m_nSize;
	m_pElements = new T[m_nCapacity];
	memcpy(m_pElements, r.m_pElements, r.m_nSize * sizeof(T));
}

template <class T>
Vector<T>::~Vector() {//deconstructor
	delete[] m_pElements;
}
template <class T>
T& Vector<T>::operator[](int index) {//return index's elements without bounding test
		return m_pElements[index];
}

template <class T>
int Vector<T>::size() const {//return size
	return m_nSize;
}

template <class T>
void Vector<T>::push_back(const T& x) {//insert one element at tail
	if (m_nSize < m_nCapacity) {
		m_pElements[m_nSize++] = x;
	}
	else {
		inflate();//inflate if necessary
		m_pElements[m_nSize++] = x;
	}
}

template <class T>
void Vector<T>::clear(){//clear all elements
	m_nSize = 0;
	delete[]m_pElements;
	m_pElements = nullptr;
	m_nCapacity = 0;
}

template <class T>
bool Vector<T>::empty() const {//judge if vector is empty
	if (m_nSize == 0) return true;
	else return  false;
}

template <class T>
void Vector<T>::inflate() {//allocate new memory to store elelments
	T* new_ele;
	if (m_nCapacity == 0) { //if cap is 0,we set it to 1
		new_ele = new T[1]; 
		m_nCapacity = 1;
	}
	else {//if cap is bigger than 0 ,we double it size 
		new_ele = new T[2 * m_nCapacity];
		m_nCapacity = 2 * m_nCapacity;
	}
	for (int i = 0; i < m_nSize; i++) {
		new_ele[i] = m_pElements[i];
	}
	delete[]m_pElements;
	m_pElements = new_ele;
}

template <class T>
T& Vector<T>::at(int index) {//get elemets by examining bound
	if (index >= 0 && index < m_nSize) {
		return m_pElements[index];
	}
	else {
		std::out_of_range  err("message");
		throw err;
	}
}