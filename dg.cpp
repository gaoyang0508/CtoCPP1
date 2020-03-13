#include<iostream>
using namespace std;
int power(int a,int b,int sum)
{
	int ay,by,ah,bh;
	ah=a/2;
	bh=b/3;
	ay=a%2;
	by=b%3;
	sum=sum+ah+bh;
	if(ah+bh+ay>=2||ah+bh+by>=3)
	return power(ah+ay+bh,ah+bh+by,sum); 	
	else
	return sum;	
}
int main()
{
	int a,b,sum;
	cin>>a;
	sum=a;
	b=a;
	cout<<power(a,b,sum);
	return 0;
}
