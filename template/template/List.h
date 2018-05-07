#ifndef __LIST_H__
#define __LIST_H__


#include<string>
#include<iostream>
using namespace std;

template <class T>
struct ListNode
{
    struct ListNode* _prev;
    struct ListNode* _next;
    T _data;
    
};

template <class T>
class List
{
    typedef ListNode<T> Node;
public:
    List()//���캯��
    {
        _head = new Node;
        _head->_next = _head->_prev = _head;
    }
    List(const List<T>& h) //��������
    {
        Node* head = h._head;
        Node* tmp = head->_next;
       
        _head = new Node;
        _head->_next = _head->_prev = _head;
        while (tmp != head)
        {
            PushBack(tmp->_data);
            tmp = tmp->_next;
        }
    }
    ~List() //��������
    {
        Clear();
        delete _head;
        _head = NULL;
    }
    void PushBack(const T& x) //β��
    {
        Node *tmp = new Node;
        tmp->_data = x;
        Node* tail = _head->_prev;

        tail->_next = tmp;
        tmp->_prev = tail;
        _head->_prev = tmp;
        tmp->_next = _head;
        
    }
    void PushFront(const T& x) //ͷ��
    {
        Node *tmp = new Node;
        tmp->_data = x;
        Node* cur = _head->_next;
        tmp->_prev = _head;
        _head->_next = tmp;
        tmp->_next = cur;
        cur->_prev = tmp;
    }
    void PopBack() //βɾ
    {
        Node* cur = _head->_prev;
        _head->_prev = cur->_prev;
        cur->_prev->_next = _head;

        delete[]cur;
        cur->_next = cur->_prev = NULL;
    }
    void PopFront() //ͷɾ
    {
        Node* cur = _head->_next;
        _head->_next = cur->_next;
        cur->_next->_prev = _head;
    }
    void Insert(Node* pos,const T& x) //�������
    {
        Node* cur = new Node;
        cur->_data = x;
        cur->_prev = pos->_prev;
        pos->_prev->_next = cur;
        pos->_prev = cur;
        cur->_next = pos;
    }
    void Erase(Node* pos) //ɾ�����λ��
    {
        Node* cur = pos->_next;
        pos->_prev->_next = cur->_next;
        cur->_next->_prev = pos->_prev;
    }
    void Clear() //�����������
    {
        Node* cur = _head->_next;
        while(cur != _head)
        {
            Node* tmp = cur;
            cur = cur->_next;
            delete tmp;
        }
        _head->_next = _head;
        _head->_prev = _head;
    }
    Node* Find(const T& x) //����
    {
        Node* cur = _head->_next;
        while (cur != _head)
        {
            if(cur->_data==x)
                return cur;
            cur = cur->_next;
        }
        return NULL;
    }

    size_t Size() //��ȡ������
    {
        size_t count = 0;
        Node* cur = _head->_next;
        while (cur != _head)
        {
            count++;
            cur = cur->_next;
        }
        return count;
    }
    bool Empty()
    {
        if (_head->_next = _head->_prev)
            return 1;
        return 0;
    }
    void PrintList() //��ӡ����
    {
        Node* tmp = _head->_next;
        while (tmp != _head)
        {
            std::cout<<tmp->_data<<" ";
            tmp = tmp->_next;
        }
        std::cout<<std::endl;
    }

protected:
    Node* _head;

};

#endif//__LIST_H__
