#include <iostream>
#include<iomanip>
#include <cmath>
using namespace std;

const double PI=3.1415926;
//请在此处完善类的设计
class cylinder
{
public:
double getvolumn();
double getarea();
void init(double H,double R);
private:
double r,h;
};
void cylinder::init(double H,double R)
{
h=H;
r=R;
}
double cylinder::getvolumn()
{
double v;
v=PI*r*r*h;
return v;
}
double cylinder::getarea()
{
double s;
s=2*PI*r*r+2*PI*r*h;
return s;
}


int main()
{
    double d,h;
    cin>>d>>h;
    cylinder can;

    can.init(h,d/2);
    cout<<fixed<<setprecision(6);
    cout<<"油桶的容积是"<<can.getvolumn()<<" "<<endl;
    cout<<"铁皮的面积是"<<can.getarea()<<endl;
}



