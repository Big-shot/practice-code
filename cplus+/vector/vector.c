#include"vector.h"

//构造函数
vector::vector()
    :_first(NULL)
    ,_finish(NULL)
     ,_endofstorge(NULL)
{}

//析构函数
vector::~vector()
{
    delete []_first;
    _first = _finish = _endofstorge = NULL;
}

//拷贝构造函数(深拷贝)  a2(a1)
vector::vector(const vector& a)
{
    if(a.GetSize()>0)
    {
        _first = new Datatype[a.GetSize()];
        memcpy(_first,a._first,sizeof(Datatype)*a.GetSize());
        _finish = _endofstorge =_first + a.GetSize();
    }
}

//赋值运算符重载  a2=a1
vector& vector::operator=(vector& a)
{
   swap(_first,a._first);
   swap(_finish,a._finish);
   swap(_endofstorge,a._endofstorge);
    return *this;
}


int vector::GetSize() const
{
    return _finish-_first;
}

int vector::GetCapacity() const
{
    return _endofstorge-_first;
}

void vector::Expand(int n)
{
    int len = GetSize();
    if(n>GetCapacity())
    {
        Datatype* tmp = new Datatype[n];
        if(_first)
        {
            memcpy(tmp,_first,sizeof(Datatype)*len);
            delete []_first;
        }
        _first = tmp;
        _finish = tmp + len;
        _endofstorge = tmp + n;  
    }
}

void  vector::vectorInsert(int pos,Datatype x)// 插入
{
    int len = GetSize();
    if(len==GetCapacity())
        Expand(GetCapacity()*2+3);

    for(int i = len;i>pos;i--)
    {
        _first[i]=_first[i-1] ;
    }
    _first[pos] = x;
    _finish++;
}
int  vector::vectorErase(size_t pos)//删除
{
    size_t len = GetSize();
    if(pos>=len)
        return -1;
    memcpy(_first+pos,_first+pos+1,sizeof(Datatype)*(len-pos));
    return 0;
}
int  vector::vectorFind(Datatype x)//查找
{
    int len = GetSize();
    for(int i = 0; i<len; i++)
    {
        if(_first[i]==x)
            return i;
    }
    return -1;
}
int  vector::vectorReplace(Datatype src,Datatype dst)//替换
{
    int pos = vectorFind(src);
    if(pos>=0)
    {
        _first[pos] = dst;
        return 0;
    }
    return -1;
}


void vector::vectorPrint()
{
    int len = GetSize();
    for(int i=0; i<len; i++)
    {
        std::cout<<_first[i];
    }
    std::cout<<"\n";

}
