#ifndef VECTOR_H
#define VECTOR_H
#include<iostream>
using namespace std;
const int DEF_CAPACITY = 10;
const int CAPACITY_MULT = 2;

template <typename T>
class MyVec {

public:
	class Iterator {
		/*
		 * This class supports ranged for loops.
		 * It includes:
		 * Iterator(int*)
		 * operator++
		 * operator*
		 * operator!=
		 * */
	public:
		friend bool operator!=(Iterator& rhs, Iterator& lhs) {

			return(rhs.iptr != lhs.iptr);
		}
		Iterator(T* ip) : iptr(ip) {}

		Iterator& operator++() {
			iptr++;
			return *this;
		}

		T operator*() {
			return *iptr;
		}

	private:
		T* iptr;
	};

	MyVec() : sz(0) {
		capacity = DEF_CAPACITY;
		data = new int[DEF_CAPACITY];
	}

	MyVec(int sz, T val = 0) : sz{ sz } {
		capacity = sz;
		data = new T[capacity];
		for (int i = 0; i < sz; i++) {
			data[i] = val;
		}
	}

	// copy control:
	MyVec(const MyVec& v2) {
		copy(v2);
	}
	~MyVec() {
		delete[] data;
	}
	MyVec& operator=(const MyVec& v2) {
		if (this != &v2) {
			delete[] data;
			copy(v2);
		}
		return *this;
	}

	void push_back(int val) {
		sz++;
		if (sz > capacity) {
			cout << "Increasing capacity\n";
			int* old_data = data;
			data = new int[capacity * CAPACITY_MULT];
			for (int i = 0; i < sz; i++) {
				data[i] = old_data[i];
			}
			capacity *= CAPACITY_MULT;
			delete[] old_data;
		}
		data[sz - 1] = val;
	}
	int size() const { return sz; }
	T operator[](int i) const {
		return data[i];
	}
	T& operator[](int i) {
		return data[i];
	}
	Iterator begin() const {
		return MyVec<T>::Iterator(data);
	}
	Iterator end() const {
		return MyVec<T>::Iterator(data + sz);
	}

private:
	
	void copy(const MyVec& v2) {
		sz = v2.sz;
		capacity = v2.capacity;
		data = new T[capacity];
		for (int i = 0; i < sz; i++) {
			data[i] = v2.data[i];
		}
	}
	T* data;
	int sz;
	int capacity;
};

template <typename T>
void print_vector(const MyVec<T>& v) {
	for (T i : v) cout << i << " ";
	cout << endl;
}

template <typename T>
bool operator==(MyVec<T>& v1, MyVec<T>& v2) {
	if (v1.size() == v2.size()) {
		for (int i = 0; i <= v1.size(); i++) {
			if (v1[i] != v2[i]) {
				return false;
			}
		}
		return true;
	}
	return false;
}
#endif
