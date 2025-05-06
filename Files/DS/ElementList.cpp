#include "ElementList.hpp"

ElementList::ElementList(Pixel* p, ElementList* n)
{
    this->pixel = p;
    this->next = n;
}

ElementList::ElementList()
{
    this->pixel = nullptr;
    this->next = nullptr;
}

ElementList::~ElementList()
{
}

Pixel* ElementList::getPixel()
{
    return this->pixel;
}

void ElementList::setPixel(Pixel* p)
{
    this->pixel = p;
}

ElementList* ElementList::getNext()
{
    return this->next;
}

void ElementList::setNext(ElementList* p)
{
    this->next = p;
}