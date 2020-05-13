#include  <iostream>
using  namespace  std;
class Complex
{
	public:
		Complex(double a,double b);
		Complex();
		~Complex();
		friend Complex operator +(Complex c1,Complex c2);
		friend Complex operator -(Complex c1,Complex c2);
		friend Complex operator +(double a,Complex c1);
		friend Complex operator -(double a,Complex c1);
		friend Complex operator +(Complex c1,double a);
		friend Complex operator -(Complex c1,double a);
		friend Complex operator +(int a,Complex c1);
		friend Complex operator -(int a,Complex c1);
		friend Complex operator +(Complex c1,int a);
		friend Complex operator -(Complex c1,int a);
		void print();
		friend ostream & operator <<(ostream &s,const Complex& c1){
			return s<<"("<<c1.real<<")+"<<"("<<c1.imag<<"i)"<<endl;
		}
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
Complex operator +(Complex c1,Complex c2)
{
	Complex c0;
	c0.real=c1.real+c2.real;
	c0.imag=c1.imag+c2.imag;
	return Complex(c0.real,c0.imag);
}
Complex operator -(Complex c1,Complex c2)
{
	Complex c0;
	c0.real=c1.real-c2.real;
	c0.imag=c1.imag-c2.imag;
	return Complex(c0.real,c0.imag);
}
Complex operator +(double a,Complex c1)
{
	Complex c0;
	c0.real=a+c1.real;
	return Complex(c0.real,c1.imag);
}
Complex operator -(double a,Complex c1)
{
	Complex c0;
	c0.real=a-c1.real;
	return Complex(c0.real,-c1.imag);
}
Complex operator +(Complex c1,double a)
{
	Complex c0;
	c0.real=a+c1.real;
	return Complex(c0.real,c1.imag);
}
Complex operator -(Complex c1,double a)
{
	Complex c0;
	c0.real=c1.real-a;
	return Complex(c0.real,c1.imag);
}
Complex operator +(int a,Complex c1)
{
	Complex c0;
	c0.real=a+c1.real;
	return Complex(c0.real,c1.imag);
}
Complex operator -(int a,Complex c1)
{
	Complex c0;
	c0.real=a-c1.real;
	return Complex(c0.real,-c1.imag);
}
Complex operator +(Complex c1,int a)
{
	Complex c0;
	c0.real=a+c1.real;
	return Complex(c0.real,c1.imag);
}
Complex operator -(Complex c1,int a)
{
	Complex c0;
	c0.real=c1.real-a;
	return Complex(c0.real,c1.imag);
}
void Complex::print()
{
	Complex c0;
	c0.real=real;
	c0.imag=imag;
	cout<<c0;
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
        c=100+a;
        cout<<"100+a=";
        c.print();
        cout<<endl;
        c=2.5-a;
        cout<<"2.5-a=";
        c.print();
        cout<<endl;
        return  0;
}











