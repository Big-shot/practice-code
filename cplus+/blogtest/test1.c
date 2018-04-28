#include<iostream>
using namespace std;

class AA
{
    public:
        void fun()
        {
            cout << "AA" << endl;

        }
    protected:
        int _a;

};

class BB : public AA
{
    public:
        void fun()
        {
            cout << "BB" << endl;

        }
    protected:
        int _b;

};

int main()
{
    AA a;
    BB b;
    a = b;
    b = a;

    AA *p1 = &b;
    AA &a1 = b;
    BB *p2 = (BB*)&a;
    BB& b1 = a;
    return 0;

}
