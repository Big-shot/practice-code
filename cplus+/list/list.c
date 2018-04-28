#include"list.h"

List::~List()
{
    while(_head)
    {
        Node* tmp = _head;
        _head = _head->_next;
        delete _tmp;
    }
}
