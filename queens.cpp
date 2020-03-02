#include <iostream>
using namespace std;
int main()
{
	char a[8][8],b[8];
	int i,j,x,c,flag=0,y=0;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		a[i][j]=0;
	}
	cin>>b;
	for(i=0;i<8;i++)
	{
		if(b[i]=='*')	
		{	x=i;
			continue;
		}
		b[i]=b[i]-48;
		a[i][b[i]-1]=1;
		for(c=0;c<8;c++)
		a[c][b[i]-1]=1;
		for(c=0;(i-c>=0)&&(b[i]-1-c>=0);c++)
		a[i-c][b[i]-1-c]=1;
		for(c=0;(i-c>=0)&&(b[i]-1+c<8);c++)
		a[i-c][b[i]-1+c]=1;
		for(c=0;(i+c<8)&&(b[i]-1-c>=0);c++)
		a[i+c][b[i]-1-c]=1;
		for(c=0;(i+c<8)&&(b[i]-1+c<8);c++)
		a[i+c][b[i]-1+c]=1; 
	}
	for(c=0;c<8;c++)
	{
		if(a[x][c]==0)	
		{
		flag=1;
		y=c+1;
		break;
		}
	 } 
	 if (flag)
	 cout<<y<<endl;
	 else cout<<"No Answer";
}
