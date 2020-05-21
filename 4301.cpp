#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int main()
{
	int i=0,j,len=0;
	double min;
	vector<double> box(1);
	ifstream a1("a.txt",ios::binary);
	if(a1)
	{
		while(a1.good())
		{
			if(!a1.fail())
			{
				len++;
				box.resize(len);
				a1>>box[i];
				i++;
			}
		}
	}
	else{cout<<"ERROR:Cannot open file'a.txt'."<<endl;}
	for(i=0;i<box.size()-1;i++)
	{
		min=box[i];
		for(j=i+1;j<box.size();j++)
		{
			if(min>box[j])
			{
				min=box[j];
				box[j]=box[i];
				box[i]=min;
			}
		}
	}
	ofstream b1("b.txt",ios::binary);
	for(i=0;i<box.size();i++)
	b1<<box[i]<<' ';
	b1.close();
	a1.close();
	return 0;
}
