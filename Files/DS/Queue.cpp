#include "Queue.hpp"

Queue::Queue()
{
    front = nullptr;
    rear = nullptr;
}

Queue::~Queue()
{
    makenull();
}

void Queue::enqueue(Pixel* elem)
{
    ElementQueue* element = new ElementQueue(elem, nullptr);
    if(isEmpty())
    {
        front = element;
        rear = element;
    }
    else
    {
        rear->setNext(element);
        rear=element;
    }
}

Pixel* Queue::dequeue()
{
    Pixel* result = nullptr;
    if(!isEmpty())
    {
        ElementQueue* aux = front;
        Pixel* auxp = front->getPixel();
        front = front->getNext();
        
        delete(aux);
        
        if(front==nullptr)
        {
            rear=nullptr;
        }
        
        result = auxp;
    }
    return result;
}

Pixel* Queue::getFront()
{
    Pixel* result = nullptr;
    if(!isEmpty())
    {
        result= front->getPixel();
    }
    return result;
}

Pixel* Queue::getRear()
{
    Pixel* result = nullptr;
    if(!isEmpty())
    {
        result = rear->getPixel();
    }
    return result;
}

void Queue::makenull()
{
    while(front!=nullptr)
    {
        dequeue();
    }
}

bool Queue::isEmpty()
{
    return front == nullptr;
}