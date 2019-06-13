#include <iostream>
#include <istream>
#include <iomanip>
#include <cmath>
#include "complex.h"

using namespace std;

Complex::Complex(double real, double imag) : real( real ), imag(imag ) {};


ostream& operator<< (ostream& os, const Complex& c) {
	os << "the real part of the complex number is " << c.get_real()
		<< "the imaginary part is" << c.get_imag()
		<< fixed <<setprecision(3) << showpos << endl;

	/*
	 * Outputting a `Complex` instance, while illustrating some of the
	 * capabilities of I/O streams: `setprecision` gives us a fixed
	 * number of decimal places, while `showpos` turns on the plus
	 * sign for positive numbers.
	 * */
	return os;
}


/*
 * Read a `Complex` number from an input stream.
 * */
istream& operator>> (istream& is, Complex& c) {
	double real;
	double imag;
	is >> real;
	is >> imag;
	c.real = real;
	c.imag = imag;
	return is;
}


Complex::operator bool() const {
	if (real == 0 || imag == 0) {
		return true;
	}
	else {
		return false;
	}
}

Complex& Complex::operator++() {
	++real;
	return *this;
}

Complex Complex::operator++(int dummy) {
	Complex temp;
	temp.real = real++;
	temp.imag = imag;
	return temp;
}

Complex& Complex::operator--() {
	--real;
	return *this;
}

Complex Complex::operator--(int dummy) {
	Complex temp;
	temp.real = real--;
	temp.imag = imag;
	return temp;
}

double Complex::get_real() const {
	return real;
}

double Complex::get_imag() const {
	return imag;
}

Complex& Complex::operator-=(const Complex& c) {
	real = real - c.real;
	imag = imag - c.imag;
	return *this;
}
Complex Complex::operator*(const int i) {
	Complex temp;
	temp.real = i * real;
	temp.imag = i * imag;
	return temp;
}

bool operator==(const Complex& c1, const Complex& c2) {
	return ((abs(c1.get_real() - c2.get_real()) < 0.000001) && ((abs(c1.get_imag() == c2.get_imag()) < 0.000001)));
}
bool operator!=(const Complex& c1, const Complex& c2) {
	return !(c1 == c2);
}

Complex operator+(const Complex& c1, const Complex& c2) {
	double real;
	double imag;
	real = c1.get_real() + c2.get_real();
	imag = c1.get_imag() + c2.get_imag();
	Complex temp = Complex(real, imag);
	return temp;

}

Complex operator-(const Complex & c1, const Complex& c2) {
	double real;
	double imag;
	real = c1.get_real() - c2.get_real();
	imag = c1.get_imag() - c2.get_imag();
	Complex temp = Complex(real, imag);
	return temp;
}