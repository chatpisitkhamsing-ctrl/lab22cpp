#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double x = 0, double y = 0);
		
		// ใช้ friend functions เพื่อแก้ปัญหา Ambiguity และรองรับการสลับฝั่ง double
		friend ComplexNumber operator+(const ComplexNumber &a, const ComplexNumber &b);
		friend ComplexNumber operator-(const ComplexNumber &a, const ComplexNumber &b);
		friend ComplexNumber operator*(const ComplexNumber &a, const ComplexNumber &b);
		friend ComplexNumber operator/(const ComplexNumber &a, const ComplexNumber &b);
		friend bool operator==(const ComplexNumber &a, const ComplexNumber &b);
		friend ostream& operator<<(ostream &os, const ComplexNumber &c);

		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x, double y){
	real = x; imag = y;
}

// Operator Implementation (จัดการทุกกรณีผ่านการแปลงค่าอัตโนมัติของ Constructor)
ComplexNumber operator+(const ComplexNumber &a, const ComplexNumber &b){
	return ComplexNumber(a.real + b.real, a.imag + b.imag);
}

ComplexNumber operator-(const ComplexNumber &a, const ComplexNumber &b){
	return ComplexNumber(a.real - b.real, a.imag - b.imag);
}

ComplexNumber operator*(const ComplexNumber &a, const ComplexNumber &b){
	return ComplexNumber(a.real*b.real - a.imag*b.imag, a.real*b.imag + a.imag*b.real);
}

ComplexNumber operator/(const ComplexNumber &a, const ComplexNumber &b){
	double den = b.real*b.real + b.imag*b.imag;
	return ComplexNumber((a.real*b.real + a.imag*b.imag)/den, (a.imag*b.real - a.real*b.imag)/den);
}

bool operator==(const ComplexNumber &a, const ComplexNumber &b){
	return (a.real == b.real && a.imag == b.imag);
}

double ComplexNumber::abs(){
	return sqrt(real*real + imag*imag);
}

double ComplexNumber::angle(){
	return atan2(imag, real) * 180 / M_PI;
}

// การแสดงผลตามเงื่อนไขในตาราง
ostream& operator<<(ostream &os, const ComplexNumber &c){
	if(c.real == 0 && c.imag == 0) return os << "0";
	if(c.real == 0) return os << c.imag << "i";
	if(c.imag == 0) return os << c.real;
	if(c.imag > 0) return os << c.real << "+" << c.imag << "i";
	return os << c.real << c.imag << "i";
}