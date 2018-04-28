
#include"vector.h"

int main()
{
    vector a;
    a.vectorInsert(0,'c');
    a.vectorInsert(1,'h');
    a.vectorInsert(2,'a');
    a.vectorInsert(3,'n');
    a.vectorInsert(4,'g');
    a.vectorInsert(5,'e');
    a.vectorInsert(6,' ');
    a.vectorInsert(7,'w');
    a.vectorInsert(8,'o');
    a.vectorInsert(9,'r');
    a.vectorInsert(10,'l');
    a.vectorInsert(11,'d');
    std::cout<<"原串:";
    a.vectorPrint();

    std::cout<<"删除:";
    a.vectorErase(11); //删除
    a.vectorPrint();
    std::cout<<"查找:";
    std::cout<<a.vectorFind('o')<<endl;//查找
    std::cout<<"替换:";
    a.vectorReplace(' ','e');//替换
    a.vectorPrint();
    return 0;
}
