#include<iostream>
using namespace std;

//class AA
//{
//public:
//	void fun()
//	{
//		cout << "AA" << endl;
//	}
//protected:
//	int _a;
//};
//
//class BB : public AA
//{
//public:
//	void fun()
//	{
//		cout << "BB" << endl;
//	}
//protected:
//	int _b;
//};

//class Person
//{
//public:
//	Person(const char *name = "",int num = 0) //���๹�캯��
//		:_name(name)
//		,_num(num)
//	{}
//	~Person()//������������
//	{
//		cout << "~Person()" << endl;
//	}
//	Person(const Person& p)//���࿽�����캯��
//		:_name(p._name)
//		,_num(p._num)
//	{}
//	Person& operator=(const Person& p)//���ำֵ���������
//	{
//		if (this != &p)
//		{
//			_name = p._name;
//			_num = p._num;
//		}
//		return *this;
//	}
//	
//protected:
//	string _name; // ����
//	int _num;
//};
//class Student : public Person
//{
//public:
//	Student(const char* name = "", const int num1 = 0, int num2 = 0)//���๹�캯��
//		:Person(name,num1)   
//		,_num(num2)
//	{}
//	~Student()//������������
//	{
//		cout << "~Student()" << endl;
//	}
//	Student(const Student& s)//���࿽�����캯��
//		:Person(s)
//		,_num(s._num)
//	{}
//	Student& operator=(const Student& s)//���ำֵ���������
//	{
//		Person::operator=(s); //��ʾ���ø��ำֵ���������
//		_num = s._num;
//	}
//protected:
//	int _num; // ѧ��
//};


//
//class A
//{
//public:
//	int _a;
//};
//
//class B : virtual public A
//{
//public:
//	int _b;
//};
//
//class C : virtual public A
//{
//public:
//	int _c;
//};
//
//class D : public B,public C
//{
//public:
//	int _d;
//};
//class Person
//{
//public:
//	string _name; // ����
//};
//class Student : public Person
//{
//protected:
//	int _num; //ѧ��
//};
//class Teacher : public Person
//{
//protected:
//	int _id; // ְ�����
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // ���޿γ�
//};
//void Test()
//{
//	// ��ʾָ�������ĸ�����ĳ�Ա
//	Assistant a;
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//}

//void Test()
//{
//
//	D d;
//	d._a = 1;
//	d._b = 2;
//	d._c = 3;
//	d._d = 4;
//}



//int main()
//{
//	Test();
//	Person a("boday",15);
//	Student b("crash",1502,17);
//	
//
//1. �ڼ̳���ϵ�л���������඼�ж�����������
//2. ����͸�������ͬ����Ա�������Ա�����θ���Գ�Ա��ֱ�ӷ��ʡ�
//	���������Ա�����У�����ʹ�� ����::�����Ա ���ʣ�--����	--�ض���
//3. ע����ʵ�����ڼ̳���ϵ������ò�Ҫ����ͬ���ĳ�Ա��
//	a = b; //�������ֵ�����������Ƭ����������Ǳ�����֧�ֵ�
//	b = a; //��������ܸ�ֵ���������
//
//	Person *p1 = &b; //����3
//	Person &a1 = b; //����3
//	Student *p2 = (Student*)&a; //����4
//	Student& b1 = (Student&)a; //����4
//	system("pause");
//	return 0;
//}

class Person
{
public:
	virtual void Buyticket()
	{
		cout << "��Ʊ��ȫ��" << endl;
	}
protected:
	char* _name;
};

class Student : public Person
{
public:
	virtual void Buyticket()
	{
		cout << "��Ʊ����Ʊ" << endl;
	}
protected:
	char* _name;
};

void Fun(Person &p)
{
	p.Buyticket();
}

int main()
{
	Person p;
	Student s;
	Fun(p);
	Fun(s);
	system("pause");
	return 0;
}




