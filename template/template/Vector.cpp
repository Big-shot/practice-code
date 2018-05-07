// #include"Vector.h"
// 
// 
// template<class T>
// Vector<T>::Vector(const Vector<T>& v)
// {
//     int len = v.Size();
//     delete[]_first; 
//     _first = _finish = new T[len];
//     for(int i = 0;i<len;i++)
//     {
//         *(_finish) = v._first[i];
//         ++_finish;
//     }
//     _endofstorge = _first+len;
// }
// template<class T>
// Vector<T>& Vector<T>::operator=(Vector<T>& v)
// {
//     delete[]_first;
//     Vector<T> v1(v);
//     _first = v1._first;
//     _finish = v1._finish;
//     _endofstorge = v1._endofstorge;
// }
// 
// template<class T>
// void Vector<T>::PushBack(const T& x)
// {
//     if(_finish == _endofstorge)
//         Expand(Capacity()*2+1);
//     _first[Size()] = x;
//     ++_finish;
// }
// 
// template<class T>
// void Vector<T>::PopBack()
// {
//     Erase(Size());
// }
// 
// template<class T>
// void Vector<T>::Expand(size_t n)
// {
//     int size = Size();
//     if(n>Capacity())
//     {
//         T* tmp = new T[n];
//         for (int i = 0;i<size;i++)
//         {
//             *(tmp+i) = *(_first+i);
//         }
//         delete[]_first;
//         _first = tmp;
//         _finish = _first + size;
//         _endofstorge = _first + n;
//     }
// }
// 
// template<class T>
// void Vector<T>::Insert(size_t pos,const T& x)
// {
//     assert(_first+pos <= _finish);
//     if(_finish == _endofstorge)
//         Expand(2*Capacity());
//     T* end = _finish;
//     while(end != _first + pos)
//     {
//         *(end) = *(end-1);
//         --end;
//     }
//     _first[pos] = x;
//     ++_finish;
// }
// 
// template<class T>
// void Vector<T>::Erase(size_t pos)
// {
//     int size = Size();
//     assert(_first+pos < _finish);
//     T* start = _first + pos + 1;
//     while(start != _finish)
//     {
//         *(start - 1) = *(start);
//         ++start;
//     }
//     --_finish;
// }
// 
// template<class T>
// size_t Vector<T>::Find(const T& x)
// {
//     int size = Size();
//     for(int i = 0;i<size;i++)
//     {
//         if (_first[i] == x)
//             return i;
//     }
//     return -1;
// }
// 
// template<class T>
// T& Vector<T>::operator[](size_t pos)
// {
//     assert(_first+pos < _finish);
//     return _first[pos];
// }
// 
// template<class T>
// const T& Vector<T>::operator[](size_t pos) const
// {
//     assert(_first+pos < _finish);
//     return _first[pos];
// }
// 
// template<class T>
// size_t Vector<T>::Size()
// {
//     return _finish - _first;
// }
// 
// template<class T>
// size_t Vector<T>::Capacity()
// {
//     return _endofstorge - _first;
// }
// 
// template<class T>
// bool Vector<T>::Empty()
// {
//     return Size()==0;
// }
