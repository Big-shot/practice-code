#include "List.h"
#include "Vector.h"

//template <class T,class Container> //��ͨģ�����
template <class T,template<class> class Container> //ģ���ģ�����
class Stack
{
public:
    void StackPush(const T& s)
    {
        _con.PushBack(s);
    }
    void StackPop()
    {
        _con.PopBack();
    }
    T& StackTop()
    {
        return _con.Back();
    }
    bool StackEmpty()
    {
        return _con.Empty();
    }
protected:
    //Container _con;
    Container<T> _con; //ģ���ģ�����
};


void StackTest()
{
//     Stack<int,Vector<int>> s;
//     s.StackPush(1);
//     s.StackPush(2);
//     s.StackPush(3);
//     s.StackPush(4);
//     s.StackPush(5);
// 
//     while (!s.StackEmpty())
//     {
//         cout<<s.StackTop()<<" ";
//         s.StackPop();
//     }
//     cout<<endl;

    Stack<string,List> s;
    s.StackPush("hello");
    s.StackPush("world");
    s.StackPush("welcome");
    s.StackPush("you");
    s.StackPush("!");

    while (!s.StackEmpty())
    {
        cout<<s.StackTop()<<" ";
        s.StackPop();
    }
    cout<<endl;

}