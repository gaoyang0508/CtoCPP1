#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	char a[10],b[10];
	int i,j,min,c;
	cin>>a>>b;
	for(i=0;a[i]!='\0';i++)
	{
		if(65<=a[i]&&a[i]<=90)
		{a[i]=a[i]+32;} 
	}
	for(j=0;b[j]!='\0';j++)
	{
		if(65<=b[j]&&b[j]<=90)
		{b[j]=b[j]+32;} 
	}
	min=fabs(a[0]-b[0]);
	for(i=0;a[i]!='\0';i++)
	{
		for(j=0;b[j]!='\0';j++)
		{
			c=fabs(a[i]-b[j]);
			if(min>c) min=c;
		}
	}
	cout<<min;
	return 0;
}
