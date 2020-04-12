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
		unsigned int m_ID;//��� 
		string m_Name;//����
		string m_Introduction;//���
		string m_Author;//����
		string m_Date;//����
		unsigned int m_Page;//ҳ��
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
        b1.SetName("C++  ���Գ������(��4��)");
        b1.SetAuthor("֣��");
        b1.SetIntroduction("����C++����������֪ʶ");
        b1.SetDate("201007");
        b1.SetPage(529);
        b2.SetID(2);
        b2.SetName("��ɢ��ѧ");
        b2.SetAuthor("��Т��");
        b2.SetIntroduction("���������߼���ν���߼��������ۡ�����ϵͳ��ͼ��");
        b2.SetDate("198209");
        b2.SetPage(305);
        b3.SetID(3);
        b3.SetName("c�������");
        b3.SetAuthor("̷��ǿ");
        b3.SetIntroduction("����C��������еĻ���֪ʶ��������ʽ���﷨��");
        b3.SetDate("201006");
        b3.SetPage(355);

        cout<<"��һ�������"<<endl;
        s.in(b1);
        cout<<"�ڶ��������"<<endl;
        s.in(b2);
        cout<<"�����������"<<endl;
        s.in(b3);
        cout  <<"���п���鼮������"<<s.GetCount()  <<  endl;
        cout  <<"���Ҳ�����ͼ�飺��ɢ��ѧ"  <<  endl;
        Book  tmpbook=s.findbyName("��ɢ��ѧ");
        if(tmpbook.GetID()!=0)
        {
                s.out("��ɢ��ѧ");
                cout  <<"��ɢ��ѧ  �ѳɹ�����"  <<  endl;
        }
        else
                cout<<"û���ҵ�nameΪ��ɢ��ѧ����"<<endl;
        cout  <<"���п���鼮������"<<s.GetCount()  <<  endl;

        cout  <<"����ͼ��  ID��3"  <<  endl;
        tmpbook=s.findbyID(3);
        if(tmpbook.GetID()!=0)
                cout<<"�ҵ�IDΪ"<<3<<"���飬������"<<tmpbook.GetName()<<endl;
        else
                cout<<"û���ҵ�IDΪ"<<3<<"����"<<endl;

        cout  <<"����ͼ��  name����ɢ��ѧ"  <<  endl;
        tmpbook=s.findbyName("��ɢ��ѧ");
        if(tmpbook.GetID()!=0)
                cout<<"�ҵ�nameΪ��ɢ��ѧ���飬ID��"<<tmpbook.GetID()<<endl;
        else
                cout<<"û���ҵ�nameΪ��ɢ��ѧ����"<<endl;

        cout<<"������п��ͼ�����Ϣ"<<endl;
        s.printList();
        cout<<"�������н���"<<endl;
        return  0;
}
