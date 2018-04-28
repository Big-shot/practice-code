
#include<iostream>
#include<vector>
#include<string.h>
#include<stdlib.h>
using namespace std;

typedef char Datatype;

class vector
{
public:
    vector();
    int GetSize()const;
    int GetCapacity()const;
    void Expand(int n);//扩容
    ~vector();
    vector(const vector& a) ;
    vector& operator=(vector& a);
    void vectorInsert(int pos,Datatype x); // 插入
    int vectorErase(size_t pos); //删除
    int vectorFind(Datatype x);//查找
    int vectorReplace(Datatype src,Datatype dst);//替换
    void vectorPrint();

private:
    Datatype *_first;
    Datatype *_finish;
    Datatype *_endofstorge;
};
