#ifndef ELEMENTQUEUE_HPP
#define ELEMENTQUEUE_HPP
#include "Pixel.hpp"

class ElementQueue
{
    ElementQueue* next;
    Pixel* pixel;
public:
    ElementQueue();
    ElementQueue(Pixel* px);
    ElementQueue(Pixel* px, ElementQueue* pNext);
    ~ElementQueue();
    
    Pixel* getFresh();
    Pixel* getPixel();
    ElementQueue* getNext();
    void setNext(ElementQueue* pNext);

};

#endif // ELEMENTQUEUE_HPP
