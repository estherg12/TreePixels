#include "ElementListSum.hpp"

ElementListSum::ElementListSum()
{
    this->sum = 0;
    this->next = nullptr;
}

ElementListSum::~ElementListSum()
{
}

ElementListSum::ElementListSum(int s, ElementListSum* n)
{
    this->sum = s;
    this->next = n;
}

//Getters & Setters
int ElementListSum::getSum()
{
    return sum;
}

void ElementListSum::setSum(int s)
{
    this->sum = s;
}

ElementListSum* ElementListSum::getNext()
{
    return next;
}

void ElementListSum::setNext(ElementListSum *p)
{
    this->next=p;
}
