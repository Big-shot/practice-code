#ifndef __VECTOR_H__
#define __VECTOR_H__


#include<iostream>
#include<stdlib.h>
#include<assert.h>
#include<string>
using namespace std;


template<class T>
class Vector
{
public:
    Vector():_first(NULL),_finish(NULL),_endofstorge(NULL)//构造函数
    {}
    ~Vector()//析构函数
    {
        delete[]_first;
        _first = _finish = _endofstorge = NULL;
    }
    Vector(const Vector<T>& v)
        :_first(NULL)
        ,_finish(NULL)
        ,_endofstorge(NULL)
    {
        int len = v._finish - v._first;
        _first = _finish = new T[len];
        T* start = v._first;
        while(start != v._finish)
        {
            *(_finish) = *start;
            ++_finish;
            ++start;
        }
        _endofstorge = _first+len;
    }

    Vector<T>& operator=(Vector<T>& v)
    {
        delete[]_first;
        Vector<T> v1(v);
        swap(_first ,v1._first);
        swap(_finish , v1._finish);
        swap(_endofstorge , v1._endofstorge);

        return *this;
    }

    void PushBack(const T& x)
    {
        if(_finish == _endofstorge)
            Expand(Capacity()*2+1);
        _first[Size()] = x;
        ++_finish;
    }
    void PopBack()
    {
        Erase(Size()-1);
    }
    T& Back()
    {
        return *(_finish-1);
    }
    T& Front()
    {
        return *(_first);
    }
    void Expand(size_t n)
    {
        int size = Size();
        if(n>Capacity())
        {
            T* tmp = new T[n];
            for (int i = 0;i<size;i++)
            {
                *(tmp+i) = *(_first+i);
            }
            delete[]_first;
            _first = tmp;
            _finish = _first + size;
            _endofstorge = _first + n;
        }
    }
    void Insert(size_t pos,const T& x)
    {
        assert(_first+pos <= _finish);
        if(_finish == _endofstorge)
            Expand(2*Capacity());
        T* end = _finish;
        while(end != _first + pos)
        {
            *(end) = *(end-1);
            --end;
        }
        _first[pos] = x;
        ++_finish;
    }
    void Erase(size_t pos)
    {
        assert(_first+pos < _finish);
        int size = Size();
        T* start = _first + pos + 1;
        while(start != _finish)
        {
            *(start - 1) = *(start);
            ++start;
        }
        --_finish;
    }
    void PopFront()
    {
        Erase(0);
    }
    size_t Find(const T& x)
    {
        int size = Size();
        for(int i = 0;i<size;i++)
        {
            if (_first[i] == x)
                return i;
        }
        return -1;
    }
    T& operator[](size_t pos)
    {
        assert(pos<Size());
        return _first[pos];
    }
    const T& operator[](size_t pos) const
    {
        assert(_first+pos < _finish);
        return _first[pos];
    }
    size_t Size()
    {
        return _finish - _first;
    }
    size_t Capacity()
    {
        return _endofstorge - _first;
    }
    bool Empty()
    {
         return Size()==0;
    }

protected:
    T* _first;
    T* _finish;
    T* _endofstorge;
};

#endif //__VECTOR_H__
