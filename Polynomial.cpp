#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <stack>
#include <string>
#include <stdarg.h>

using namespace std;

class Polynomial{

	double *values;
	int numberCoff;  // number of coffecients in the array of values

	public:
		Polynomial();
		Polynomial(int);
		Polynomial(int , double,...);
		string getString();
		~Polynomial();
		Polynomial(Polynomial&);
		void Copy(Polynomial&);
		void fixPolynomial();
		static Polynomial AddPolynomial(Polynomial&, Polynomial&);
		//operators 
		Polynomial operator = (Polynomial&);
		Polynomial operator + (Polynomial&);


};

Polynomial::Polynomial(){
	values=NULL;
	numberCoff=0;
}

Polynomial:: Polynomial(int n){
	numberCoff=n;
	values= new double[n];
	for(int i=0;i<n;i++)
	{
		values[i]=0;
	}

}

Polynomial::Polynomial(int n , double first,...){
	numberCoff=n;
	values=new double[n];
	va_list v1;
	va_start(v1,n);
	for( int i=0; i<n;i++)
		values[i]=va_arg(v1,double);
	va_end(v1);

}

string Polynomial::getString(){

	string str;
	for (int i=numberCoff-1;i>=0;i--)
	{
		char text[20]="";
		sprintf(text,"(%g)X ^ %d",values[i],i);
		str += (str.length()>0)?" + ":"";
		str+=text;
	}
	return str;
		
}

Polynomial::~Polynomial(){
	if(values) delete[] values;
	numberCoff=0;
}


void Polynomial::Copy(Polynomial& x){

	numberCoff=x.numberCoff;
	values= new double[numberCoff];
	for(int i=0; i<numberCoff;i++)
		values[i]=x.values[i];

}

Polynomial::Polynomial(Polynomial& x){

	values=NULL;
	Copy(x);

}

void Polynomial::fixPolynomial(){

	for (int i=numberCoff-1;i>=0;i--)
		if(values[i]==0)
			numberCoff--;
		else
			break;
}


Polynomial Polynomial::AddPolynomial(Polynomial& x , Polynomial& y ){

	Polynomial z(max(x.numberCoff , y.numberCoff));
	for(int i=z.numberCoff-1;i>=0;i--)
	{
		double av=(i<x.numberCoff)? x.values[i]:0;
		double bv=(i<y.numberCoff)? y.values[i]:0;
		z.values[i]=av+bv;
	
	}
	z.fixPolynomial();
		return z;

}


Polynomial Polynomial::operator=(Polynomial& x){
 Copy(x);
 return *this;

}

Polynomial Polynomial::operator+(Polynomial& x){
	Polynomial y= Polynomial::AddPolynomial(*this ,x);
	return y;
}



int main() {

	Polynomial M(4, 9.8, 2.3, 7.4, 9.5);
	cout<<"M(X) = "<<M.getString()<<endl;

}