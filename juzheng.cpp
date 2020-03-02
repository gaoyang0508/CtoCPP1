#include<iostream>
using namespace std;
int main()
{
	int a[3][3],i,j,b[3][3],c[3][3],x=0,r;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		cin>>a[i][j];
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		cin>>b[i][j];
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			for(r=0;r<3;r++)
			{
				x=x+a[i][r]*b[r][j];
			}
			c[i][j]=x;
			x=0;
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<c[i][j];
			cout<<" ";
		}
		cout<<"\n";
	}
}
