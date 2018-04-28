#include <iostream>
#include <string.h>
#include<stdlib.h>
using namespace std;

class String
{
    public:
        String(char *str = "");
        String(const String& s);
        String& operator=(const String &s);
        ~String();
    private:
        char* _str;

};

