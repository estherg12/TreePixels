#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "ElementQueue.hpp"
#include "Pixel.hpp"
#include <iostream>
using namespace std;

class Queue
{
    ElementQueue* front;
    ElementQueue* rear;
public:
    Queue();
    ~Queue();
    
    void enqueue(Pixel* p);
    Pixel* dequeue();
    Pixel* getFront();
    Pixel* getRear();
    void makenull();
    bool isEmpty();
    
};

#endif