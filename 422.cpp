#include  <iostream>
#include  <string>
using  namespace  std;

class  CStudent
{
public:
CStudent();
CStudent(string p1,int a);
static int count;
~CStudent();
static int getcount();
void printname();
private:
string name="noname";
int age;


};
//请在这里初始静态成员变量
int CStudent::count=0;
CStudent::CStudent()
{
cout<<name<<" is contructing"<<endl;
count++;
}
CStudent::CStudent(string p1,int a)
{
name=p1;
age=a;
cout<<name<<" is contructing"<<endl;
count++;
}
CStudent::~CStudent()
{
count--;
cout<<name<<" is destructing"<<endl;
}
int CStudent::getcount()
{
return (count);
}
void CStudent::printname()
{
cout<<"name:"<<name<<endl;
}


int  main()
{
        cout  <<  "现在有学生"  <<  CStudent::getcount()  <<  endl;
        {
                CStudent  stuB[5];
                stuB[4].printname();
                cout  <<  "现在有学生"  <<  CStudent::getcount()  <<  endl;
        }
        cout  <<  "现在有学生"  <<  CStudent::getcount()  <<  endl;
        {
                CStudent  stuA[2]  =  {CStudent("Tom",  3),  CStudent("Jerry",  2)};
                for  (int  i  =  0;  i  <  2;  i++)
                {
                        stuA[i].printname();
                }
                cout  <<  "现在有学生"  <<  CStudent::getcount()  <<  endl;
        }
        cout  <<  "现在有学生"  <<  CStudent::getcount()  <<  endl;

        return  0;
}
