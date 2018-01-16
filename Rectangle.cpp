#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <stack>
#include <string>

using namespace std;

class CRectangle
{
	float length,width;

public:
	enum {LW , WL};
	static int showMethod;
	CRectangle() ;
	CRectangle(float , float );
	float getWidth();
	float getLength();
	string getString();
	float getArea();
	float getCircumference();
	void offset(float, float);
	void flatten(float , float);
	CRectangle unionRectangles(CRectangle,CRectangle);
	CRectangle intersectionRectangles(CRectangle , CRectangle);
};


CRectangle::CRectangle() 
	{
		length=0;
		width=0;
	}

CRectangle::CRectangle(float length, float width){

	this->length=length;
	this->width=width;
}

float CRectangle:: getWidth(){
	return width;
}

float CRectangle:: getLength() {
	return length;
}

string CRectangle::getString(){
	char text[100];
	if(showMethod==LW)
		sprintf(text,"(%g , %g)",length,width);
	if(showMethod==WL)
		sprintf(text,"(%g ,%g)",width,length);
	return string(text);
}

float CRectangle::getArea(){

	return length*width;
}

float CRectangle::getCircumference(){

	return 2*(length*width);
}


void CRectangle::offset(float dx , float dy){
	
	length+=dy;
	width+=dx;
}

void CRectangle::flatten(float dx , float dy){
	
	length-=dy;
	width-=dx;
}


CRectangle CRectangle::unionRectangles(CRectangle x, CRectangle y){

	CRectangle z;
	z.length=min(x.length, y.length);
	z.width=max(x.width,y.width);
	return z;
}

CRectangle CRectangle::unionRectangles(CRectangle x, CRectangle y){

	CRectangle z;
	z.length=max(x.length, y.length);
	z.width=min(x.width,y.width);
	return z;
}



int CRectangle::showMethod=CRectangle::WL;
int main() {

	CRectangle x(50,250);
	//cout<<x.getString()<<endl;
	CRectangle::showMethod=CRectangle::LW;
	cout<<x.getString()<<endl;


}