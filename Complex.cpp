#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <stack>
#include <string>
#include <stdarg.h>

using namespace std;

class Complex
{
private:
	double real;
	double img;

public:
	Complex();
	Complex(double R, double I);
	Complex(Complex& C);
	void copy(Complex& C);
	string getString(); 
	double magnitude();
	double angle();
	void negative();
	double Real();
	double imaginary();
	static Complex addComplex(Complex& A, Complex& B);
	void add(Complex& C);
	void Multiply(Complex&);

	//operators
	Complex operator=(Complex& C);
	Complex operator=(double D);
	void operator+=(Complex& C);
	Complex operator+=(double D);
	Complex operator+(Complex& C);
	Complex operator+(double D);
	double operator[](string);

	//unary cast stream Operaators 
	Complex operator-(); //Negative 
	operator const string(); //Cast 
	friend istream& operator >> (istream &is, Complex& C); //Stream 
	friend ostream& operator << (ostream &os, Complex& C); //Stream


};

Complex::Complex() {
	real = img = 0.0;
}

Complex::Complex(double R, double I) {
	real = R;
	img = I;
}

Complex::Complex(Complex& C) {
	copy(C); 
}

void Complex::copy(Complex& C) {
	real= C.real; 
	img = C.img;
}

string Complex::getString() {
	char text[100]; 
	if(img==0)
		sprintf(text, "%g", real);
	else if(real==0)
		sprintf(text, "%g * i", img); 
	else if(img>0)sprintf(text, "%g + %g * i", real, img); 
	else if(img<0)sprintf(text, "%g - %g * i", real, -img); 
	return string(text); 
}



double Complex::magnitude() { 
	return sqrt(real*real+img*img);
}
double Complex::angle() {
	return atan2(img, real);
}

void Complex::negative() { 
	real*=-1; 
	img*=-1;
}

double Complex::Real() {
	return real;
}


double Complex::imaginary() { 
	return img;
}

Complex Complex::addComplex(Complex& A, Complex& B) {
	Complex C;
	C.real = A.real + B.real;
	C.img = A.img + B.img;
	return C;
}


void Complex::add(Complex& C) { 
	real+= C.real; 
	img += C.img;
}

void Complex::Multiply(Complex& C) {
	real=real*C.real - img*C.img;
	img=real*C.img + img*C.real;

}
//operators 

Complex Complex::operator=(Complex& C) {
	copy(C);
	return *this;
}

Complex Complex::operator=(double D) { 
	real = D; 
	img = 0; 
	return *this; 
}

void Complex::operator +=(Complex& C) {
	add(C);
}

Complex Complex::operator +=(double D) {
	real+= D;
}


Complex Complex::operator+(Complex& C) { 
	return addComplex(*this, C);
}

Complex Complex::operator+(double D) {
	return addComplex(*this, Complex(D, 0));
}

// unary Cast Stream operators 
Complex Complex::operator-() { 
	return Complex(-real, -img); 
}


Complex::operator const string() {
	return getString();
}

istream& operator >> (istream &is, Complex& C) {

is>>C.real;
is>>C.img;
return is;
}

ostream& operator << (ostream& os, Complex& C) {
	os<<C.getString();
	return os; 
}


double Complex::operator[](string s){
	if (s=="magnitude") return magnitude();
	if (s=="angle") return angle();
}
