#include "String.h"

String::String(char *str)
{
    _str = new char[strlen(str)+1];
    strcpy(_str,str);

}

String::~String()
{
    delete[] _str; 
    _str = NULL;

}

String::String(const String& s)
    :_str(NULL)
{
    String tmp(s._str);
    swap(_str,tmp._str);

}

String& String::operator=(const String& s )
{
    String tmp(s._str);
    swap(_str,tmp._str);
    return *this;
}
