#include "List.h"
#include "Vector.h"


template<class T,class Container>
class Queue
{
public:
    void PushBack(const T& q)
    {
        _con.PushBack(q);
    }
    void PopFront()
    {
        _con.PopFront();
    }
    T& Front()
    {
        return _con.Front();
    }
    int Size()
    {
        return _con.Size();
    }
    bool Empty()
    {
        return _con.Empty();
    }
protected:
    Container _con;
};

void QueueTest()
{
//     Queue<int,Vector<int>> q;
//     q.PushBack(1);
//     q.PushBack(2);
//     q.PushBack(3);
//     q.PushBack(4);
//     q.PushBack(5);
// 
//     while (!q.Empty())
//     {
//         cout<<q.Front()<<" ";
//         q.PopFront();
//     }
//     cout<<endl;

    Queue<string,List<string>> q;
    q.PushBack("change");
    q.PushBack("my");
    q.PushBack("world");
    q.PushBack("come");
    q.PushBack("on !");

    while (!q.Empty())
    {
        cout<<q.Front()<<" ";
        q.PopFront();
    }
    cout<<endl;
}