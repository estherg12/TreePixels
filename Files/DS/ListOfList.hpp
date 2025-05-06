#ifndef LISTOFLIST_HPP
#define LISTOFLIST_HPP
#include "ElementListOfList.hpp"
#include "List.hpp"
#include "ElementList.hpp"

class ListOfList
{
    ElementListOfList* header;
public:
    ListOfList();
    ~ListOfList();
    
    void insert(int sum, List* l);
    void insertFirst(int sum, List* l);
    void insertLast(int sum, List* l);
    
    void deleteP(ElementListOfList* p);
    void deletePos(int pos);
    
    ElementListOfList* getNext(ElementListOfList* p);
    ElementListOfList* getPrev(ElementListOfList* p);
    
    
    void makenull();
    bool empty();
    
    ElementListOfList* findPosition(int pos);
    int getSize();//returns how many elements
    ElementListOfList* getLast();//returns the last element
    ElementListOfList* getHeader();
    ElementListOfList* getMiddle();
    
    void setHeader(ElementListOfList* h);
};

#endif // LISTOFLIST_HPP
