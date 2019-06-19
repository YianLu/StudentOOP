#include <iostream>
#include "vector.h"

using namespace std;

void print_vector(const MyVec& v) {
	for (size_t i = 0; i < v.size();i++) {
		cout << v[i] << endl;
	}
}


MyVec::MyVec(){
	sz=0;
	data = new int[0];
	capacity = 0;
}

MyVec::MyVec(const MyVec& v2) {
	sz = v2.sz;
	capacity = v2.capacity;
	data = new int[capacity];
	for (size_t i = 0;i < size();i++) {
		data[i] = v2.data[i];
	}
}

MyVec::~MyVec() {
	delete[]data;
}

MyVec& MyVec::operator=(const MyVec& v2) {
	if (this != &v2) {
		delete[]data;
		sz = v2.sz;
		capacity = v2.capacity;
		data = new int[capacity];
		for (size_t i = 0;i < size();i++) {
			data[i] = v2.data[i];
		}
		return *this;
	}
}


/*
 * == is true when every element of the vectors are the same in
 * the same order. (Thus they must be the same size.)
 * */
bool operator==(MyVec& v1, MyVec& v2) {
	bool flag = true;
	
	if (v1.size() == v2.size()) {
		for (size_t i = 0; i < v1.size();i++) {
			if (v1[i] != v2[i]) {
				flag = false;
			}
		}
	
	}
	else {
		flag = false;
	}
	
	return flag;
}

/*
 * Puts an element at the back of a vector.
 * */
void MyVec::push_back(int val) {
	if (capacity == 0) {
		capacity++;
		data = new int[capacity];
	}
	if (sz == capacity) {
		int* olddata = data;
		data = new int[2*capacity];
		capacity *= 2;
		for (size_t i = 0;i < size();i++) {
			data[i] = olddata[i];
		}
		delete[]olddata;

	}
	data[sz] = val;
	++sz;
}

/*
 * this [] is for reading items from the MyVec:
 * It returns the i-th element.
 * */
int MyVec::operator[](int i) const {
	return data[i];
}

/*
 * this [] allows write access to items in the MyVec:
 * It returns a reference to the i-th element.
 * */
int& MyVec::operator[](int i) {
	return data[i];
}