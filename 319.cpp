#include<iostream> 
using namespace std;
#include<iomanip>
#define PI 3.1415926
class cylinder
{
	private:		
	double r,h;	
	public:		
	cylinder(double a,double b);	
	~cylinder();	
	double getvolumn();	
	double getarea();	
};
cylinder::cylinder(double a,double b)
{
	h=a;
	r=b;
	cout<<"构造函数被调用" <<endl;
}
cylinder::~cylinder()
{
	cout<<"析构函数被调用"<<endl;
}
double cylinder::getvolumn()
{
	return(PI*r*r*h);
}
double cylinder::getarea()
{
	return(2*PI*r*r+2*r*PI*h);
}
int main()

{

    double d,h;

    cin>>d>>h;

    cylinder can(h,d/2);

    cout<<fixed<<setprecision(6);

    cout<<"油桶的容积是"<<can.getvolumn()<<" "<<endl;

    cout<<"铁皮的面积是"<<can.getarea()<<endl;

}
