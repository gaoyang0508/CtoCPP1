#include <iostream>
#include <iomanip>
using namespace std;

typedef int elementType;
typedef struct node
{
    elementType data;
    node* next;
} LList, *PList;

class linkedList
{
public:
    linkedList();//���캯��
    virtual ~linkedList();//����������ע��Ҫ���������нڵ����Դ
    void insert( int value );//���棺�����ʼ������ʹ�ã�
    bool initiate();//��ʼ��������ʹ��new��������ͷ��㡣�������ʧ�ܣ��򷵻�false�����򷵻�true
    bool isEmpty();//�жϵ������Ƿ�Ϊ��
    //ɾ���������е�pos��Ԫ�ؽ�㣬����ɾ���Ľڵ��ֵ����value�С�
    //ע�⣺�������Ϊ�ա�ɾ��λ�ô��������ȡ��Լ�ɾ��λ��Ϊ0���������Ҫ��ֹɾ���������Ӧ��Ϣ
    bool remove( int pos, int& value );
    void print();//˳���ӡ����������ǵ�����Ϊ�գ������ Empty
    int Length();//���ص������ȡ�����ǵ�����Ϊ�գ��򷵻�-1
private:
    LList *head;
    int len;
};

//���ڴ˴��������г�Ա������ʵ��
linkedList::linkedList()
{
  head=(PList)malloc(sizeof(LList));
  head->next=NULL;
	len=0;
}
bool linkedList::initiate()
{
	LList *head=new node;
  if(head==NULL)
	return 0;
	else return 1;
}
void linkedList::insert(int value)
{
	LList* p1=new node;
	p1->data=value;
	LList* p;
	LList* q;
	p=head->next;
	q=head;
	while(p)
	{
		q=p;
		p=p->next;
	}
	p1->next=q->next;
	q->next=p1;
}
bool linkedList::isEmpty()
{
	if(head->next==NULL) 
	  return true;
	else return false;
}
linkedList::~linkedList()
{
	PList q;
	while(1)
	{
		q=head;
		if(q->next==NULL)
		{
			delete q;
			break;
		}
		head=head->next;
		delete q;
	}
}
bool linkedList::remove(int pos,int& value)
{
	if(pos>len)
	{
		cout<<"pos > len, failed"<<endl;
		return 0;
	}
	if(pos<=0)
	{
		cout<<"pos <= 0, failed"<<endl;
		return 0;
	}
	if(len==0)
	{
		cout<<"Empty"<<endl;
		return 0;
	}
	PList p0,q0;
	q0=head;p0=head->next;
	for(int i=0;i<pos-1;i++)
	{
		q0=p0;
		p0=p0->next;
	}
	value=p0->data;
	q0->next=p0->next;
}
int linkedList::Length()
{

		PList p;
		int i=0;
		p=head;
		while(p)
		{
			p=p->next;
		  i++;
		}
	  len=i-1;
  if(len==0) return -1;
	else return len;
}







//��Ա����print
void linkedList::print()
{
    if( isEmpty() )
    {
        cout << "Empty" << endl;
        return;
    }
    LList* tmp = head->next;
    while(tmp)
    {
        cout <<tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}


int main(int argc, char* argv[])
{
    linkedList L1;
    int n;
    int val;
    //��ʼ������
    if(!L1.initiate())
        return 0;

    cin>>n;//�������������ݸ���
    for(int i=0; i<n; i++) //����n����������������
    {
        cin>>val;
        L1.insert(val);
    }
    cout << "Origin Length��" << L1.Length() << endl;//���������
    cout << "data��" ;
    L1.print();//��ӡ����

    cin>>n;//������Ҫɾ�������ݵ�λ��
    if (L1.remove(n,val))
    {
        //ɾ��λ��n�����ݣ�����ɾ��������ֵ����val��
        cout<<"Delete the data at position("<<n<<"):"<<val<<endl;
        cout<< "New Length��" << L1.Length()<< endl;//���������
        cout<< "data��" ;
        L1.print();//��ӡ����
    }

    return 0;
}

