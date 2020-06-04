#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Array
{
//请完成类的设计
	public:
		Array(int n);
		vector<T> sz;
		void input(int n);
		T& operator [](int n)
		{
			return sz[n];
		}
		private:
			int num;

};
template <typename T>
Array<T>::Array(int n)
{
	num=n;
}
template <typename T>
void Array<T>::input(int n)
{
	int i;	
	T num0=0;
	for(i=0;i<n;i++)
	{

		cin>>num0;
		sz.push_back(num0);
	}
}


class Fract
{
//请完成类的设计
	public:
		Fract(int n,int m=1);
		void show();
		Fract &operator += (Fract &f2)
{
  Fract f1(f2.fz*fm+f2.fm*fz,f2.fm*fm);
  return *this=f1;
}
		friend ostream & operator <<(ostream &s,const Fract& c1){
			return s<<c1.fz<<"/"<<c1.fm<<endl;
		}
		friend istream &operator >> (istream &c,Fract &d)
{
  c>>d.fz>>d.fm;
  return c;
}
	private:
		int fz,fm;
};
Fract::Fract(int n,int m)
{
	int max,min,i;
	fz=n;fm=m;
	if(n<0) n=0-n;
	if(m<0) m=0-m;
	max=(n<m? m:n);	
	min=(n<m? n:m);
	for(i=min;i>1;i--)
	{
		if(min%i==0&&max%i==0)
		{
			fz=fz/i;
			fm/=i;
			break;
		}
	}
		
}
void Fract::show()
{
	if(fz==0||fm==1)
	{
		cout<<fz<<endl;
	}
	else
	{
		if(fm<0&&fz>0)
		{
			fm=0-fm;
			fz=0-fz;
			Fract c0(1,1);
			c0.fz=fz;
			c0.fz=fm;
			cout<<c0;
		}
		else
		{
			Fract c1(1,1);
			c1.fz=fz;
			c1.fm=fm;
			cout<<c1;
		}
	}
}

int main()
{
    unsigned int n;
    cin >> n;
    Array<double> db(n);
    db.input(n);
    double dbsum(0.0);
    for (unsigned int i = 0; i < n; i++)
        dbsum += db[i];
    cout << dbsum << endl;

    cin >> n;
    Array<Fract> fr(n);
    fr.input(n);
    Fract frsum(0, 1);
    for (unsigned int i = 0; i < n; i++)
        frsum += fr[i];
    frsum.show();
}
