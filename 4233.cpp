#include  <iostream>
using  namespace  std;
class Point
{
	public:
	Point();
	Point(int a,int b);
	~Point();
	Point& operator ++();
	Point operator ++(int);
	friend ostream & operator <<(ostream& s,const Point& p){
		return s<<"("<<p.m_x<<","<<p.m_y<<")"<<endl;
	}
	private:
		int m_x,m_y;
};
Point::Point()
{
	m_x=0;
	m_y=0;
}
Point::Point(int a,int b)
{
	m_x=a;
	m_y=b;
}
Point::~Point()
{
}
Point& Point::operator ++()
{
	m_x++;
	m_y++;
	return *this;
}
Point Point::operator ++(int)
{
	Point old=*this;
	m_x++;
	m_y++;
	return old;
}
int  main()
{
        Point  a(1,3);
        cout<<a;
        cout<<a++;
        cout<<++a;
        return  0;
}
