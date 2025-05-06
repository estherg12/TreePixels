#include "ElementListOfList.hpp"

ElementListOfList::ElementListOfList()
{
    this->list = nullptr;
    this->next = nullptr;
    this->sumRGB = 0;
}

ElementListOfList::ElementListOfList(ElementListOfList* e, List* l, int sum)
{
    this->list = l;
    this->next = e;
    this->sumRGB = sum;
}

ElementListOfList::~ElementListOfList()
{
}

ElementListOfList* ElementListOfList::getNext()
{
    return this->next;
} 

int ElementListOfList::getSumRGB()
{
    return this->sumRGB;
} 

List* ElementListOfList::getList()
{
    return this->list;
}

void ElementListOfList::setNext(ElementListOfList* n)
{
    this->next = n;
}

void ElementListOfList::setList(List* l)
{
    this->list = l;
}

void ElementListOfList::setSumRGB(int s)
{
    this->sumRGB = s;
}

