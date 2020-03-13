#include<iostream> 
#include<iomanip>
using namespace std;
float power(float a,float b)
{
	float c;
	c=a-b;
	return (c);
}
int main()
{
	float a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	cout<<fixed<<setprecision(2)<<power(a1,b1)<<" "<<power(a2,b2);
	return 0;
}
