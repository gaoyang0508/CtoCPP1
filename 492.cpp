#include<iostream>
#include<vector>
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
		vector<Book> m_Books;
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
};
unsigned int Store::GetCount()
{
	return m_Books.size();
}
Store::Store()
{
	cout<<"Store default constructor called!"<<endl;
}
Store::Store(int n)
{
	m_Books.resize(n);
	cout<<"Store constructor with (int n) called!"<<endl;
}
Store::~Store()
{
	cout<<"Store destructor called!"<<endl;
}
Store::Store(const Store& other)
{
	m_Books=other.m_Books;
	cout<<"Store copy constructor called!"<<endl;
}
void Store::in(Book &b)
{
	m_Books.push_back(b);
}
void Store::out(string name)
{
	int i;
	for(i=0;i<m_Books.capacity();i++)
	{
		if(m_Books[i].GetName()==name)
		{
			m_Books.erase(m_Books.begin()+i);
			break;
		}
	}
}
Book Store::findbyID(int ID)
{
	int flag=0,i;
	vector<Book>::iterator it;
	for(it=m_Books.begin(),i=0;it!=m_Books.end();it++)
	{
		if(m_Books[i].GetID()==ID)
		{
		flag=1;break;
		}
		i++;
	}
	if(flag)
	return m_Books[i];
	else
	return Book();
}
Book Store::findbyName(string name)
{
	int flag=0,i;
	vector<Book>::iterator it;
	for(it=m_Books.begin(),i=0;it!=m_Books.end();it++)
	{
		if(m_Books[i].GetName()==name)
		{
		flag=1;break;
		}
		i++;
	}
	if(flag)
	return m_Books[i];
	else
	return Book();
}
void Store::printList()
{
	int i;
	cout<<"There are totally "<<GetCount()<<" Books:"<<endl;
	for(i=0;i<GetCount();i++)
	{
		cout<<"ID="<<m_Books[i].GetID()<<";  Name:"<<m_Books[i].GetName()<<";  Author:"<<m_Books[i].GetAuthor()<<";  Date:"<<m_Books[i].GetDate()<<";"<<endl;
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
