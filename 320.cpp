#include<iostream>
using namespace std;
class CTime
{
	private:
	int nian,yue,ri,xs,fz,miao;
	public:
	CTime(int year=0,int month=0,int day=0,int hour=0,int minute=0,int second=0);
	CTime(CTime &a);
	~CTime();
	void showTime();
	int dayDiff(CTime t);
	int isvalid();
	int sum();
	int flag;
};
CTime::CTime(int year,int month,int day,int hour,int minute,int second)
{
	if((year%4==0&&year%100!=0)||year%400==0)
	{
	if((month==2&&day<=29)||((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&day<=31)||((month==4||month==6||month==9||month==11)&&day<=30))
	{
	if(hour<24&&minute<60&&second<60)
	{
	nian=year;
	yue=month;
	ri=day;
	xs=hour;
	fz=minute;
	miao=second;
	cout<<"构造函数被调用"<<endl;
	flag=1;
	}
	else
	{	cout<<"time error!"<<endl<<"构造函数被调用"<<endl;flag=0;nian=0;yue=0;ri=0;xs=0;fz=0;miao=0;}
	}
	else
	{	cout<<"date error!"<<endl<<"构造函数被调用"<<endl;flag=0;nian=0;yue=0;ri=0;xs=0;fz=0;miao=0;}
	}
	else
	{
	if((month==2&&day<29)||((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&day<=31)||((month==4||month==6||month==9||month==11)&&day<=30))
	{
	if(hour<24&&minute<60&&second<60)
	{
	nian=year;
	yue=month;
	ri=day;
	xs=hour;
	fz=minute;
	miao=second;
	cout<<"构造函数被调用"<<endl;
	flag=1;
	}
	else
	{	cout<<"time error!"<<endl<<"构造函数被调用"<<endl;flag=0;nian=0;yue=0;ri=0;xs=0;fz=0;miao=0;}
	}
	else
	{	cout<<"date error!"<<endl<<"构造函数被调用"<<endl;flag=0;nian=0;yue=0;ri=0;xs=0;fz=0;miao=0;}
	}
}//在判断时间的合法性的基础上录入数据 
int CTime::isvalid()
{return (flag);}//判断日期时间是否合法 
CTime::~CTime()
{cout<<"析构函数被调用"<<endl;}
void CTime::showTime()
{
	cout<<nian<<"/"<<yue<<"/"<<ri<<" "<<xs<<":"<<fz<<":"<<miao<<endl;
}//输出时间 
CTime::CTime(CTime &a)
{
	nian=a.nian;
	yue=a.yue;
	ri=a.ri;
	xs=a.xs;
	fz=a.fz;
	miao=a.miao;
	cout<<"拷贝构造函数被调用"<<endl;
}
int CTime::sum()
{
	int yearg=0,yueg=0,rig=0,he=0,m2;
	yearg=nian;
	yueg=yue;
	rig=ri;
	if((yearg%4==0&&yearg%100!=0)||(yearg%400==0))
	m2=29;
	else m2=28;
	yearg-=1;
	he=he+yearg*365+rig+yearg/4+yearg/400-yearg/100;
	switch(yueg-1)
	{
	case 11:he=he+30;
	case 10:he=he+31;
	case 9:he=he+30;
	case 8:he=he+31;
	case 7:he=he+31;
	case 6:he=he+30;
	case 5:he=he+31;
	case 4:he=he+30;
	case 3:he=he+31;
	case 2:he=he+m2;
	case 1:he=he+31;
	case 0:;break;
	}
	return he;
} 
int CTime::dayDiff(CTime t) 
{
	if (sum()>t.sum())
	return (sum()-t.sum());
	else
	return (t.sum()-sum());
}
int  main()
{
        int  year,  month,  day,  hour,  minute,  second;
        cin  >>  year  >>  month  >>  day  >>  hour  >>  minute  >>  second;
        CTime  t1(year,  month,  day,  hour,  minute,  second);
        t1.showTime();
        CTime  t2(2000,  1,  1);  //利用默认形参将时间初始化为00:00:00
        if  (t1.isvalid())          //如果日期和时间合法，则计算天数
        {
                int  days=0;
                days=t1.dayDiff(t2);
                cout  <<  "这两天之间相隔了"  <<  days  <<  "天"  <<  endl;
                days=t2.dayDiff(t1);
                cout  <<  "这两天之间相隔了"  <<  days  <<  "天"  <<  endl;
        }
}
