#include<iostream>
#include<stdio.h>

using namespace std;

typedef int Datatype;

struct Node
{
    typedef struct Node* _prev;
    typedef struct Node* _next;
   
    Datatype _data;

    Node(Datatype x)
        :_data(x)
        ,_prev(NULL)
        ,_next(NULL)
    {}
};

typedef struct Node Node;

class List
{
public:
    List()
        :_head(new Node(Datatype())
    {
        _head->_prev = _head;
        _head->_next = _head;
    }
    ~List()
    

private:
    Node* _head;
};

