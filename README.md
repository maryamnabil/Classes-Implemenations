# Classes-Implemenations
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

Class Complex , Class Polynomial , Class Matrix , Class Points , Line and Polyline  
