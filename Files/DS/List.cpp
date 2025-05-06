#include "List.hpp"

List::List()
{
    header = nullptr;
}

List::~List()
{
    makenull();
}

bool List::hasMoreOnes()
{
    bool result = false;
    if(!empty())
    {
        int countOnes = 0; //counter to know how many pixels from file 1 are in the list
        int countTwos = 0; //counter to know how many pixels from file 2 are in the list
        ElementList* temp = header;
        while(temp != nullptr)
        {
            if(temp->getPixel()->getOriginFile() == 1)
            {//if the element has origin file 1 sum 1 to the counter of ones
                countOnes++;
            }
            else
            {//if the element has origin file 2 sum 1 to the counter of two
                countTwos++;
            }
            temp = temp->getNext(); //go to the next element
        }
        
        if(countOnes > countTwos)
        {
            result = true; //only change return to true if there are more pixels from file 1 than from file 2
        }
    }
    return result;   
}

void List::insert(Pixel* px, ElementList* pnt)
{
    ElementList* element = new ElementList(px, nullptr);
    
    //Case 1: If list is empty
    //Case 2: at beginning
    if(header==nullptr||header==pnt)
    {
        insertFirst(px);
    }
    
    //Case 3: Before element pnt
    ElementList* temp = header;
    while((temp!=nullptr) && (temp->getNext() != pnt))
    {
        temp=temp->getNext();
    }
    
    if(temp!=nullptr)
    {
        element->setNext(pnt);
        temp->setNext(element);
    }
    else
    {//Case 4: pnt is nullptr, insert at the end
        insertLast(px);
    }
}

void List::insertPos(Pixel* px, int pos)
{
    if (pos>=0)
    {
        ElementList* element = new ElementList(px, nullptr);
        
        //Case 1: First position
        if((header==nullptr) || (pos==0))
        {
            insertFirst(px);
        }
        else
        {
            ElementList* prevNew = findPosition(pos-1);//find the element just before the position where the new element should be inserted
        
            //Case 3: position out of range
            if(!prevNew)
            {
                delete element;
            }
            
            //Case 4: General case
            ElementList* n = prevNew->getNext();
            element->setNext(n);
            prevNew->setNext(element);
        }
    }
}

void List::insertFirst(Pixel* px)
{
    ElementList* element = new ElementList(px, nullptr);
    element->setNext(header);
    header = element;
}

void List::insertLast(Pixel* px)
{
    if(empty())//Case 0: empty
    {
        insertFirst(px);
    }
    else
    {
        ElementList* element = new ElementList(px, nullptr);
        ElementList* temp = header;
        
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

void List::deleteP(ElementList* p)
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
            ElementList* temp = p->getNext();
            p->setNext(temp->getNext());
            delete(temp);
        }
    }
    
}

void List::deletePos(int pos)
{
    if(!empty())//Case 1: invalid position or empty list
    {
        ElementList* prev = findPosition(pos);
        ElementList* temp = findPosition(pos);
        
        if(temp)//Case 2: element does not exist
        {
            ElementList* auxN = temp->getNext();
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

ElementList* List::locate(Pixel* px)
{
    ElementList* result = nullptr;
    ElementList* temp = header;
    while (temp!=nullptr)
    {
        if(temp->getPixel()==px)
        {
            result = temp;
        }
        else
        {
            temp = temp->getNext();
        }
    }
    return result;
}

int List::locatePos(Pixel* px)
{
    int result = -1;
    ElementList* temp = header;
    int pos=0;
    
    while(temp!=nullptr)
    {
        if(temp->getPixel()==px)
        {
            result = pos;
        }
        temp=temp->getNext();
        pos++;
    }
    return result;//not found if still -1
}

Pixel* List::retrieve(int pos)
{
    Pixel* result = nullptr;
    ElementList* temp = findPosition(pos);
    if(temp!=nullptr)
    {
        result = temp->getPixel();
    }
    return result;
}

ElementList* List::getNext(ElementList* p)
{
    ElementList* result = nullptr;
    if(p!=nullptr)
    {
        result = p->getNext();
    }
    return result;
}

ElementList* List::getPrev(ElementList* p)
{
    ElementList* result = nullptr;
    ElementList* temp = header;
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

void List::makenull()
{
    while(!empty())
    {
        deletePos(0);
    }
}

bool List::empty()
{
    return header==nullptr;
}

ElementList* List::findPosition(int pos)
{
    ElementList* temp = nullptr;
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

Pixel* List::getLast()
{
    ElementList* temp = nullptr;
    if(!empty())
    {
        temp = header;
        while(temp->getNext()!=nullptr)
        {//get to the last element
            temp=temp->getNext();
        }
    }
    
    return temp->getPixel();
}

int List::getSize()
{
    int result = -1;
    if(!empty())
    {
        int pos=1; //counter
        ElementList* temp = header;
        while(temp->getNext()!=nullptr)
        {
            temp=temp->getNext();
            pos++;
            result = pos;
        }
    }
    
    return result;
}

ElementList* List::getHeader()
{
    return header;
}