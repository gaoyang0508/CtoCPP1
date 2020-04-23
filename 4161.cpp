#include  <iostream>
using  namespace  std;
const  float  pi=3.14159;
class Shape
{
	private:
		int m_ID;
	public:
		double getArea();
		Shape(int i);
		~Shape();
		int GetID();
}; 
Shape::Shape(int i)
{
	m_ID=i;
	cout<<"Shape constructor called:"<<m_ID<<endl;
}
double Shape::getArea()
{
	return 0;
}
Shape::~Shape()
{
	cout<<"Shape destructor called:"<<m_ID<<endl;
}
int Shape::GetID()
{
	return m_ID;
}
class Circle:public Shape
{
	private:
		int r;
	public:
		Circle(int r0,int i);
		~Circle();
		double getArea();
};
Circle::Circle(int r0,int i):Shape(i)
{
	r=r0;
	cout<<"Circle constructor called:"<<GetID()<<endl;
}
Circle::~Circle()
{
	cout<<"Circle destructor called:"<<GetID()<<endl;
}
double Circle::getArea()
{
	double area;
	area=pi*r*r;
	return area;
}
class Rectangle:public Shape
{
	private:
		int h,w;
	public:
		Rectangle(int h0,int w0,int i);
		~Rectangle();
		int getArea();
};
Rectangle::Rectangle(int h0,int w0,int i):Shape(i)
{
	h=h0;
	w=w0;
	cout<<"Rectangle constructor called:"<<GetID()<<endl;
}
Rectangle::~Rectangle()
{
	cout<<"Rectangle destructor called:"<<GetID()<<endl;
}
int Rectangle::getArea()
{
	return h*w;
}
int  main()
{
        Shape  s(1);//1表示ID
        Circle  c(4,2);//4表示半径，2表示ID
        Rectangle  r(4,  5,3);//4和5表示长和宽，3表示ID
        cout<<"Shape的面积"<<s.getArea()<<endl;
        cout<<"Circle的面积"<<c.getArea()<<endl;
        cout<<"Rectangle的面积"<<r.getArea()<<endl;
}

