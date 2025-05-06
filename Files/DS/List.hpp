#ifndef LIST_HPP
#define LIST_HPP
#include "ElementList.hpp"
#include "Pixel.hpp"

class List
{
    ElementList* header;
public:
    List();
    ~List();
    
    bool hasMoreOnes();
    
    void insert(Pixel* p, ElementList* e);
    void insertPos(Pixel* p, int pos);
    void insertFirst(Pixel* p);
    void insertLast(Pixel* p);
    
    void deleteP(ElementList* p);
    void deletePos(int pos);
    
    ElementList* locate(Pixel* p);//returns pointer
    int locatePos(Pixel* p);//returns position
    
    Pixel* retrieve(int pos);//returns item (pixel)
    
    ElementList* getNext(ElementList* p);
    ElementList* getPrev(ElementList* p);
    
    
    void makenull();
    bool empty();
    
    ElementList* findPosition(int pos);
    int getSize();//returns how many elements
    Pixel* getLast();//returns the last element
    ElementList* getHeader();
};

#endif // LIST_HPP
