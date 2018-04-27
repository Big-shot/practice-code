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
//	Person(const char *name = "",int num = 0) //父类构造函数
//		:_name(name)
//		,_num(num)
//	{}
//	~Person()//父类析构函数
//	{
//		cout << "~Person()" << endl;
//	}
//	Person(const Person& p)//父类拷贝构造函数
//		:_name(p._name)
//		,_num(p._num)
//	{}
//	Person& operator=(const Person& p)//父类赋值运算符重载
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
//	string _name; // 姓名
//	int _num;
//};
//class Student : public Person
//{
//public:
//	Student(const char* name = "", const int num1 = 0, int num2 = 0)//子类构造函数
//		:Person(name,num1)   
//		,_num(num2)
//	{}
//	~Student()//子类析构函数
//	{
//		cout << "~Student()" << endl;
//	}
//	Student(const Student& s)//子类拷贝构造函数
//		:Person(s)
//		,_num(s._num)
//	{}
//	Student& operator=(const Student& s)//子类赋值运算符重载
//	{
//		Person::operator=(s); //显示调用父类赋值运算符重载
//		_num = s._num;
//	}
//protected:
//	int _num; // 学号
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
//	string _name; // 姓名
//};
//class Student : public Person
//{
//protected:
//	int _num; //学号
//};
//class Teacher : public Person
//{
//protected:
//	int _id; // 职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//void Test()
//{
//	// 显示指定访问哪个父类的成员
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
//1. 在继承体系中基类和派生类都有独立的作用域。
//2. 子类和父类中有同名成员，子类成员将屏蔽父类对成员的直接访问。
//	（在子类成员函数中，可以使用 基类::基类成员 访问）--隐藏	--重定义
//3. 注意在实际中在继承体系里面最好不要定义同名的成员。
//	a = b; //子类对象赋值给基类对象（切片）这个特性是编译器支持的
//	b = a; //父类对象不能赋值给子类对象
//
//	Person *p1 = &b; //特性3
//	Person &a1 = b; //特性3
//	Student *p2 = (Student*)&a; //特性4
//	Student& b1 = (Student&)a; //特性4
//	system("pause");
//	return 0;
//}

class Person
{
public:
	virtual void Buyticket()
	{
		cout << "买票—全价" << endl;
	}
protected:
	char* _name;
};

class Student : public Person
{
public:
	virtual void Buyticket()
	{
		cout << "买票—半票" << endl;
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




