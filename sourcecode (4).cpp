#include <iostream>
#include <iomanip>
using namespace std;
//请在此处补充Account类的定义
class Account
{
public:
void init(const char *a,const char *mz,char *xb,int nl,float q);
void printmoney();
void deposit(double m);
void withdraw(double n);
private:
const char *account,*name,*sex;
int age;
float money;
};
void Account::init(const char *a,const char *mz,char *xb,int nl,float q)
{
account=a;
name=mz;
sex=xb;
age=nl;
if(q*100-(int)(q*100)>0)
cout<<"您输入的金额不合法"<<endl;
else 
money=q;
}
void Account::printmoney()
{
cout<<fixed<<setprecision(2);
cout<<name<<"的存款为"<<money<<endl;
}
void Account::deposit(double m)
{
if(m*100-(int)(m*100))
cout<<"您输入的金额不合法"<<endl;
else 
money=money+m;
}
void Account::withdraw(double n)
{
if(n*100-(int)(n*100))
cout<<"您输入的金额不合法"<<endl;
else
{
if(n>money)
cout<<"您的存款金额不足"<<endl;
else
money=money-n;
}
}


int main()
{
    Account tom;
    tom.init("32020320011001876X", "Tom Black", "男", 19, 2000.89);
    tom.printmoney();//输出：Tom Black的存款为2000.89
    tom.deposit(89.471);//输出：您输入的金额不合法
    tom.printmoney();//输出：Tom Black的存款为2000.89
    tom.deposit(10000);
    tom.printmoney();//输出：Tom Black的存款为12000.89
    tom.withdraw(10001);
    tom.printmoney();//输出：Tom Black的存款为1999.89
    tom.withdraw(10000.123);//输出：您输入的金额不合法
    tom.printmoney();//输出：Tom Black的存款为1999.89
    tom.withdraw(10000.9);//输出：您的存款金额不足
    tom.printmoney();//输出：Tom Black的存款为1999.89
    Account jerry;
    jerry.init("320203200910116569", "Jerry Black", "女", 11, 100.956);//输出：您输入的金额不合法
    jerry.printmoney();//输出：Jerry Black的存款为0.00
}

