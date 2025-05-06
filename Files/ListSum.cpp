#include "ListSum.hpp"

ListSum::ListSum()
{
}

ListSum::~ListSum()
{
}

void ListSum::insertLast(int item)
{
    ElementListSum* element = new ElementListSum(item, nullptr);
    ElementListSum* temp = header; //initializes a temporary pointer pointing to the header
    
    if(header == nullptr)
    {
        insertFirst(item);
    }
    else
    {
        //Case 2: Last position
        while (temp->getNext())
        {//find the last element: temp->getNext() == nullptr
            temp=temp->getNext();
        }
        temp->setNext(element);
    }
}

void ListSum::insertFirst(int item)
{
    ElementListSum* element = new ElementListSum(item, nullptr);
    element->setNext(header); //if the list is empty, the new and only element (header) will point to null
    header = element;
}

bool ListSum::search(int item)
{
    bool result = false;
    ElementListSum* temp = this->header;
    while(temp != nullptr)
    {
        if(temp->getSum() == item)
        {
            result = true;
        }
        temp = temp->getNext();
    }
    return result;
}

ElementListSum* ListSum::getHeader()
{
    return this->header;
}
