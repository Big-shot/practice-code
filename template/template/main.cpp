#include "Vector.h"

#include"List.h"
template<class T>
void PrintVocter(Vector<T> &v)
{
    int size = v.Size();
    for (int i = 0;i<size; i++)
    {
        cout<<v[i]<<" ";
    }
    printf("\n");
}

void VectorTest()
{
    Vector<int> v;
    v.PushBack(1);
    v.PushBack(2);
    v.PushBack(3);
    v.PushBack(4);
    v.PushBack(5);
    v.PushBack(6);
    v.PushBack(7);
    PrintVocter(v);

    Vector<string> v1;
    v1.PushBack("hello");
    v1.PushBack("world !");
    v1.PushBack("i");
    v1.PushBack("love");
    v1.PushBack("you");
    PrintVocter(v1);

}
List<int> l;
void ListTest()
{
    
    l.PushFront(5);
    l.PushFront(4);
    l.PushFront(3);
    l.PushFront(2);
    l.PushFront(1);
    l.PrintList();
    
    List<string> l1;
    l1.PushBack("hello");
    l1.PushBack("world !");
    l1.PushBack("i");
    l1.PushBack("love");
    l1.PushBack("you");
    l1.PrintList();
}



int main()
{
  //VectorTest();
  ListTest();
  return 0;
}


