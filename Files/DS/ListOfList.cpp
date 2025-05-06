#include "ListOfList.hpp"

ListOfList::ListOfList()
{
    this->header = nullptr;
}

ListOfList::~ListOfList()
{
    makenull();
}

void ListOfList::insert(int sum, List* l)
{
    ElementListOfList* element = new ElementListOfList(nullptr, l, sum);
    
    //Case 1: If list is empty
    if(header==nullptr)
    {
        insertFirst(sum, l);
    }
    else
    {
        //Case 2: at beginning
        if(sum < header->getSumRGB())
        {
            element->setNext(header);
            header = element;
        }
        else
        {
            //Find the position in which the new element should be inserted
            ElementListOfList* temp = header;
            ElementListOfList* tempN = temp->getNext();
            bool found = false;
            while((tempN != nullptr) && (found == false))
            {
                if ((temp->getSumRGB() < sum)&&(sum < tempN->getSumRGB()))
                {
                    //if the new element is bigger than the temporal element and it's next, the position is in the middle
                    found = true;
                }
                else
                {
                    //go to the next element
                    temp = tempN;
                    tempN = temp->getNext();
                }
            }
            //position founded or last
            temp->setNext(element);
            element->setNext(tempN); //in case it got to the last, tempN will be nullptr
        }
    }
}

void ListOfList::insertFirst(int sum, List* l)
{
    ElementListOfList* element = new ElementListOfList(nullptr, l, sum);
    element->setNext(header);
    header = element;
}

void ListOfList::insertLast(int sum, List* l)
{
    if(empty())//Case 0: empty
    {
        insertFirst(sum, l);
    }
    else
    {
        ElementListOfList* element = new ElementListOfList(nullptr, l, sum);
        ElementListOfList* temp = header;
        
        //Case 1: only 1 element
        if(header->getNext()==nullptr)
        {
            header->setNext(element);
        }
        else
        {
            //Case 2: Last position
            while (temp->getNext())//while next(temp)!=nullptr
            {//find the last element: temp->getNext()==nullptr
                temp=temp->getNext();
            }
            temp->setNext(element);
        }
    }
}

void ListOfList::deleteP(ElementListOfList* p)
{
    //Case 1: null pointer exception
    if(p!=nullptr)
    {
        //Case 2: first and only
        if(header==p && p->getNext()==nullptr)
        {
            delete(header);
            header=nullptr;
        }
        //Case 3: Last one
        if (p->getNext()==nullptr)
        {
            delete(p);
        }
        else{
            //Case 4: general case
            ElementListOfList* temp = p->getNext();
            p->setNext(temp->getNext());
            delete(temp);
        }
    }
    
}

void ListOfList::deletePos(int pos)
{
    if(!empty())//Case 1: invalid position or empty list
    {
        ElementListOfList* prev = findPosition(pos);
        ElementListOfList* temp = findPosition(pos);
        
        if(temp)//Case 2: element does not exist
        {
            ElementListOfList* auxN = temp->getNext();
            //Case 3: first element
            if(temp==header)
            {
                delete(temp);
                header = auxN;//if there was only an element, now header is null
            }
            else
            {
                prev->setNext(auxN);
                delete(temp);
            }
        }
    }
}

ElementListOfList* ListOfList::getNext(ElementListOfList* p)
{
    ElementListOfList* result = nullptr;
    if(p!=nullptr)
    {
        result = p->getNext();
    }
    return result;
}

ElementListOfList* ListOfList::getPrev(ElementListOfList* p)
{
    ElementListOfList* result = nullptr;
    ElementListOfList* temp = header;
    //Case 1: first element
    if(header != p)
    {
        while (temp->getNext() != nullptr)
        {
            if(temp->getNext() == p)
            {
                result = p; //found
            }
            temp = temp->getNext();
        }
    }
    return result;
}

void ListOfList::makenull()
{
    while(!empty())
    {
        deletePos(0);
    }
}

bool ListOfList::empty()
{
    return header==nullptr;
}

ElementListOfList* ListOfList::findPosition(int pos)
{
    ElementListOfList* temp = nullptr;
    if(pos>=0)
    {
        temp = header;
        while(temp!=nullptr && pos>0)
        {
            temp=temp->getNext();
            pos--;
        }
    }
    
    
    return temp;
}

ElementListOfList* ListOfList::getLast()
{
    ElementListOfList* temp = nullptr;
    if(!empty())
    {
        temp = header;
        while(temp->getNext()!=nullptr)
        {//get to the last element
            temp=temp->getNext();
        }
    }
    
    return temp;
}

int ListOfList::getSize()
{
    int result = -1;
    if(!empty())
    {
        int pos=1; //counter
        ElementListOfList* temp = header;
        while(temp->getNext()!=nullptr)
        {
            temp=temp->getNext();
            pos++;
            result = pos;
        }
    }
    
    return result;
}

ElementListOfList* ListOfList::getHeader()
{
    return header;
}

ElementListOfList* ListOfList::getMiddle()
{
    ElementListOfList* result = nullptr;
    int size = getSize();
    int middle = 0;
    
    if(size > 0) //not empty
    {
        if((size%2) == 0) //even number of elements
        {
            middle = size/2;
        }
        else
        {
            middle = (size+1)/2;
        }
        
        ElementListOfList* temp = header;
        for(int i=1; i<middle; i++)
        {
            temp=temp->getNext();
        }
        result = temp;
    }
    return result;
}

void ListOfList::setHeader(ElementListOfList* h)
{
    this->header = h;
}