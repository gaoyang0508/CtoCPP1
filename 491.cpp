#include<iostream>
using namespace std;
class Book
{
	public:
		Book();
		Book(const Book& other);
		virtual ~Book();
		void SetID(int n_ID);
		void SetName(string n_Name);
		void SetAuthor(string n_Author);
		void SetIntroduction(string n_Introduction);
		void SetDate(string n_Date);
		void SetPage(unsigned int n_Page);
		int GetID();
		string GetName();
		string GetAuthor();
		string GetIntroduction();
		string GetDate();
		unsigned int GetPage();
	private:
		unsigned int m_ID;//编号 
		string m_Name;//书名
		string m_Introduction;//简介
		string m_Author;//作者
		string m_Date;//日期
		unsigned int m_Page;//页数
};
Book::Book()
{
	m_ID=0;
}
Book::Book(const Book& other)
{
	m_ID=other.m_ID;
	m_Name=other.m_Name;
	m_Introduction=other.m_Introduction;
	m_Author=other.m_Author;
	m_Date=other.m_Date;
	m_Page=other.m_Page;
}
void Book::SetID(int n_ID)
{
	m_ID=n_ID;
}
void Book::SetName(string n_Name)
{
	m_Name=n_Name;
}
void Book::SetAuthor(string n_Author)
{
	m_Author=n_Author;
}
void Book::SetIntroduction(string n_Introduction)
{
	m_Introduction=n_Introduction;
}
void Book::SetDate(string n_Date)
{
	m_Date=n_Date;
}
void Book::SetPage(unsigned int n_Page)
{
	m_Page=n_Page; 
}
Book::~Book()
{}
int Book::GetID()
{
	return m_ID;
}
string Book::GetName()
{
	return m_Name;
}
string Book::GetAuthor()
{
	return m_Author;
}
string Book::GetIntroduction()
{
	return m_Introduction;
}
string Book::GetDate()
{
	return m_Date;
}
unsigned int Book::GetPage()
{
	return m_Page;
}
class Store
{
	private:
		Book *m_pBook;
		unsigned int m_Count;
	public:
		Store();
		Store(int n);
		virtual ~Store();
		Store(const Store& other);
		void in(Book &b);
		void out(string name);
		Book findbyID(int ID);
		Book findbyName(string name);
		void printList();
		unsigned int GetCount();
		void SetCount(unsigned int a);
};
void Store::SetCount(unsigned int a)
{
	m_Count=a;
}
unsigned int Store::GetCount()
{
	return m_Count;
}
Store::Store()
{
	m_Count=0;
	m_pBook='\0';
	cout<<"Store default constructor called!"<<endl;
}
Store::Store(int n)
{
	m_Count=n;
	m_pBook=new Book[n];
	cout<<"Store constructor with (int n) called!"<<endl;
}
Store::~Store()
{
	m_Count=0;
	if(m_pBook!=0)
	{
		delete[] m_pBook;
		cout<<"Store destructor called!"<<endl;
	}
}
Store::Store(const Store& other)
{
	int i;
	m_Count=other.m_Count;
	m_pBook=new Book[m_Count];
	for(i=0;i<m_Count;i++)
	{
		m_pBook[i].SetID(other.m_pBook[i].GetID());
		m_pBook[i].SetName(other.m_pBook[i].GetName());
		m_pBook[i].SetIntroduction(other.m_pBook[i].GetIntroduction());
		m_pBook[i].SetAuthor(other.m_pBook[i].GetAuthor());
		m_pBook[i].SetDate(other.m_pBook[i].GetDate());
		m_pBook[i].SetPage(other.m_pBook[i].GetPage());
		cout<<"Store copy constructor called!"<<endl;
	}
}
void Store::in(Book &b)
{
	Book *n_pBook;
	int i;
	m_Count++;
	n_pBook=new Book[m_Count];
	for(i=0;i<m_Count-1;i++)
	{
		n_pBook[i].SetID(m_pBook[i].GetID());
		n_pBook[i].SetName(m_pBook[i].GetName());
		n_pBook[i].SetIntroduction(m_pBook[i].GetIntroduction());
		n_pBook[i].SetAuthor(m_pBook[i].GetAuthor());
		n_pBook[i].SetDate(m_pBook[i].GetDate());
		n_pBook[i].SetPage(m_pBook[i].GetPage());
	}
	n_pBook[m_Count-1].SetID(b.GetID());
	n_pBook[m_Count-1].SetName(b.GetName());
	n_pBook[m_Count-1].SetIntroduction(b.GetIntroduction());
	n_pBook[m_Count-1].SetAuthor(b.GetAuthor());
	n_pBook[m_Count-1].SetDate(b.GetDate());
	n_pBook[m_Count-1].SetPage(b.GetPage());
	delete[] m_pBook;
	m_pBook=n_pBook;
}
void Store::out(string name)
{
	int i,j;
	Book *n_pBook;
	m_Count--;
	n_pBook=new Book[m_Count];
	for(i=0,j=0;i<m_Count+1;i++)
	{
		if(m_pBook[i].GetName()!=name)
		{
			n_pBook[j].SetID(m_pBook[i].GetID());
			n_pBook[j].SetName(m_pBook[i].GetName());
			n_pBook[j].SetIntroduction(m_pBook[i].GetIntroduction());
			n_pBook[j].SetAuthor(m_pBook[i].GetAuthor());
			n_pBook[j].SetDate(m_pBook[i].GetDate());
			n_pBook[j].SetPage(m_pBook[i].GetPage());
			j++;
		}
	}
	delete[] m_pBook;
	m_pBook=n_pBook;
}
Book Store::findbyID(int ID)
{
	int flag=0;
	int i,j;
	for(i=0;i<m_Count;i++)
	{
		if(m_pBook[i].GetID()==ID)
		{
		flag=1;j=i;
		}
	}
	if(flag)
	return m_pBook[j];
	else
	return Book();
}
Book Store::findbyName(string name)
{
	int flag=0;
	int i,j;
	for(i=0;i<m_Count;i++)
	{
		if(m_pBook[i].GetName()==name)
		{
		flag=1;j=i;
		}
	}
	if(flag)
	return m_pBook[j];
	else
	return Book();
}
void Store::printList()
{
	int i;
	cout<<"There are totally "<<GetCount()<<" Books:"<<endl;
	for(i=0;i<m_Count;i++)
	{
		cout<<"ID="<<m_pBook[i].GetID()<<";  Name:"<<m_pBook[i].GetName()<<";  Author:"<<m_pBook[i].GetAuthor()<<";  Date:"<<m_pBook[i].GetDate()<<";"<<endl;
	}
}
int  main()
{
        Store  s;
        Book  b1,b2,b3;
        b1.SetID(1);
        b1.SetName("C++  语言程序设计(第4版)");
        b1.SetAuthor("郑莉");
        b1.SetIntroduction("介绍C++及面向对象的知识");
        b1.SetDate("201007");
        b1.SetPage(529);
        b2.SetID(2);
        b2.SetName("离散数学");
        b2.SetAuthor("左孝凌");
        b2.SetIntroduction("介绍命题逻辑、谓词逻辑、集合论、代数系统和图论");
        b2.SetDate("198209");
        b2.SetPage(305);
        b3.SetID(3);
        b3.SetName("c程序设计");
        b3.SetAuthor("谭浩强");
        b3.SetIntroduction("介绍C程序设计中的基本知识，如语句格式、语法等");
        b3.SetDate("201006");
        b3.SetPage(355);

        cout<<"第一本书入库"<<endl;
        s.in(b1);
        cout<<"第二本书入库"<<endl;
        s.in(b2);
        cout<<"第三本书入库"<<endl;
        s.in(b3);
        cout  <<"现有库存书籍数量："<<s.GetCount()  <<  endl;
        cout  <<"查找并出库图书：离散数学"  <<  endl;
        Book  tmpbook=s.findbyName("离散数学");
        if(tmpbook.GetID()!=0)
        {
                s.out("离散数学");
                cout  <<"离散数学  已成功出库"  <<  endl;
        }
        else
                cout<<"没有找到name为离散数学的书"<<endl;
        cout  <<"现有库存书籍数量："<<s.GetCount()  <<  endl;

        cout  <<"查找图书  ID：3"  <<  endl;
        tmpbook=s.findbyID(3);
        if(tmpbook.GetID()!=0)
                cout<<"找到ID为"<<3<<"的书，书名："<<tmpbook.GetName()<<endl;
        else
                cout<<"没有找到ID为"<<3<<"的书"<<endl;

        cout  <<"查找图书  name：离散数学"  <<  endl;
        tmpbook=s.findbyName("离散数学");
        if(tmpbook.GetID()!=0)
                cout<<"找到name为离散数学的书，ID："<<tmpbook.GetID()<<endl;
        else
                cout<<"没有找到name为离散数学的书"<<endl;

        cout<<"输出所有库存图书的信息"<<endl;
        s.printList();
        cout<<"程序运行结束"<<endl;
        return  0;
}
