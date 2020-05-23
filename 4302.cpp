#include<iostream>
#include<fstream>
using namespace std;
struct student
{
	short stu_id,score;
};
int main()
{
	short ID,fs;
	int i,n;
	cin>>n;
	student *p=new student[n];
	for(i=0;i<n;i++)
	{
		cin>>p[i].stu_id>>p[i].score;
		cout<<endl;
	}
	ofstream outt("out.txt",ios::binary);
	outt.write((char *) p,sizeof(p[n]));
	outt.close();
	delete[] p;
	p=new student[n];
	ifstream outt2("out.txt",ios::binary);
	for(i=0;i<n;i++)
	{
		outt2.read((char *) p+i,sizeof(student));
	}
	outt2.close();
	ofstream outt3("out.txt",ios::ate);
	outt3.write((char *) p,sizeof(p[n]));
	outt3.close();
	delete[] p;
}
