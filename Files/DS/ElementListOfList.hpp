#ifndef ELEMENTLISTOFLIST_HPP
#define ELEMENTLISTOFLIST_HPP
#include "List.hpp"

class ElementListOfList
{
    ElementListOfList* next;
    List* list;
    int sumRGB;
public:
    ElementListOfList();
    ElementListOfList(ElementListOfList* n, List* l, int sum);
    ~ElementListOfList();
    
    ElementListOfList* getNext();
    void setNext(ElementListOfList* e);
    
    List* getList();
    void setList(List* l);
    
    int getSumRGB();
    void setSumRGB(int s);

};

#endif // ELEMENTLISTOFLIST_HPP
