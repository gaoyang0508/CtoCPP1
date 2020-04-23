#include  "iostream"
using  namespace  std;
class vehicle
{
	private:
		int maxspeed,weight;
	public:
		vehicle(int i,int j);
		vehicle();
		~vehicle();
		void run();
		void stop();
};
vehicle::vehicle()
{
}
vehicle::vehicle(int i,int j)
{
	maxspeed=i;
	weight=j;
	cout<<"vehicle constructor called. maxspeed:"<<maxspeed<<"; weight"<<weight<<endl;
};
vehicle::~vehicle()
{
	cout<<"vehicle destructor called. maxspeed:"<<maxspeed<<"; weight"<<weight<<endl;
}
void vehicle::run()
{
	cout<<"vehicle run"<<endl;
}
void vehicle::stop()
{
	cout<<"vehicle stop"<<endl;
}
class bicycle:virtual public vehicle
{
	private:
		int height;
	public:
		bicycle(int m);
		~bicycle();
};
bicycle::bicycle(int m)
{
	height=m;
	cout<<"bicycle constructor called. height:"<<height<<endl;
}
bicycle::~bicycle()
{
	cout<<"bicycle destructor called. height:"<<height<<endl;
}
class motorcar:virtual public vehicle
{
	private:
		int seatnum;
	public:
		motorcar(int i);
		~motorcar();
};
motorcar::motorcar(int i)
{
	seatnum=i;
	cout<<"motorcar constructor called. seatnum:"<<seatnum<<endl;
}
motorcar::~motorcar()
{
	cout<<"motorcar destructor called. seatnum:"<<seatnum<<endl;
}
class motorcycle:public bicycle,public motorcar
{
	public:
		motorcycle(int height0,int seatnum0,int maxspeed,int weight0);
		~motorcycle();
};
motorcycle::motorcycle(int height0,int seatnum0,int maxspeed0,int weight0):bicycle(height0),motorcar(seatnum0),vehicle(maxspeed0,weight0)
{
	cout<<"motorcycle constructor called"<<endl;
}
motorcycle::~motorcycle()
{
	cout<<"motorcycle destructor called"<<endl;
}
int  main(int  argc,  char  *argv[])
{
        motorcycle  m(1,  2,  3,  4);//1表示height，2表示setnum，3表示maxspeed，4表示weight
        m.run();
        m.stop();
        return  0;
}
