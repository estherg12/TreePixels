#ifndef NODEBST_HPP
#define NODEBST_HPP
#include "List.hpp"
#include <chrono>
#include <iostream>
using namespace std;

class NodeBST
{
    NodeBST* rightchild;
    NodeBST* leftchild;
    List* list;
    int sumRGB;
public:
    NodeBST();
    NodeBST(NodeBST* r, NodeBST* l, List* h, int s);
    ~NodeBST();
    
    NodeBST* getRightChild();
    void setRightChild(NodeBST* r);
    
    NodeBST* getLeftChild();
    void setLeftChild(NodeBST* l);
    
    List* getList();
    void setList(List* p);
    
    int getSumRGB();
    void setSumRGB(int s);
};

#endif // NODEBST_HPP
