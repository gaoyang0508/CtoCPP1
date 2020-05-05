#include  <iostream>
using  namespace  std;
class Complex
{
	public:
		Complex(double a,double b);
		Complex();
		~Complex();
		Complex operator +(Complex c2);
		Complex operator -(Complex c2);
		Complex operator +(double);
		Complex operator -(double);
		Complex operator +(int);
		Complex operator -(int);
		void print();
	private:
		double real,imag;
}; 

Complex::Complex(double a,double b)
{
	real=a;
	imag=b;
}
Complex::Complex()
{
	real=0.0;
	imag=0.0;
}
Complex::~Complex()
{
}
Complex Complex::operator +(Complex c2)
{
	Complex c1;
	c1.real=real+c2.real;
	c1.imag=imag+c2.imag;
	return Complex(c1.real,c1.imag);
}
Complex Complex::operator -(Complex c2)
{
	Complex c1;
	c1.real=real-c2.real;
	c1.imag=imag-c2.imag;
	return Complex(c1.real,c1.imag);
}
Complex Complex::operator +(double a)
{
	Complex c1;
	c1.real=a+real;
	return Complex(c1.real,imag);
}
Complex Complex::operator -(double a)
{
	Complex c1;
	c1.real=real-a;
	return Complex(c1.real,imag);
}
Complex Complex::operator +(int a)
{
	Complex c1;
	c1.real=a+real;
	return Complex(c1.real,imag);
}
Complex Complex::operator -(int a)
{
	Complex c1;
	c1.real=real-a;
	return Complex(c1.real,imag);
}
void Complex::print()
{
	cout<<real<<"+"<<imag<<"i"<<endl;
}
int  main()
{
        Complex  a(3,4),b(1,-1),c;
        c=a+b;
        cout<<"a+b=";
        c.print();
        cout<<endl;
        c=a-b;
        cout<<"a-b=";
        c.print();
        cout<<endl;
        c=a+100;
        cout<<"a+100=";
        c.print();
        cout<<endl;
        c=a-2.5;
        cout<<"a-2.5=";
        c.print();
        cout<<endl;

        return  0;
}
