#include <iostream>
#include <iomanip>
using namespace std;

struct complex
{
    double r;
    double i;
};

complex add(complex a,complex b)
{
complex ad;
ad.r=a.r+b.r;
ad.i=a.i+b.i;
return ad;
}
complex add(complex a,double num)
{
complex ad;
ad.r=a.r+num;
ad.i=a.i;
return ad;
}
complex add(double num,complex b)
{
complex ad;
ad.r=num+b.r;
ad.i=b.i;
return ad;
}


int main()
{
    double num;
    complex a, b, c;
    cin >> a.r >> a.i;
    cin >> b.r >> b.i;
    cin >> num;
    c = add(a, b);
    cout << c.r << "+" << c.i << "i" << endl;
    c = add(a, num);
    cout << c.r << "+" << c.i << "i" << endl;
    c = add(num, b);
    cout << c.r << "+" << c.i << "i" << endl;
}


