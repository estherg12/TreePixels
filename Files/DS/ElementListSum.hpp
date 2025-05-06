#ifndef ELEMENTLISTSUM_HPP
#define ELEMENTLISTSUM_HPP

class ElementListSum
{
    int sum;
    ElementListSum* next;
public:
    ElementListSum();
    ElementListSum(int x, ElementListSum* n);
    ~ElementListSum();
    
    int getSum();
    void setSum(int s);

    ElementListSum* getNext();
    void setNext(ElementListSum* n);
};

#endif // ELEMENTLISTSUM_HPP
