#ifndef LISTSUM_HPP
#define LISTSUM_HPP
#include "ElementListSum.hpp"

class ListSum
{
    ElementListSum* header;
public:
    ListSum();
    ~ListSum();
    
    void insertLast(int item);
    void insertFirst(int item);
    
    bool search(int item);
    
    ElementListSum* getHeader();

};

#endif // LISTSUM_HPP
