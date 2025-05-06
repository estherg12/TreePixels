#include "NodeBST.hpp"
#include <chrono>
#include <iostream>
using namespace std;

NodeBST::NodeBST()
{
    this->rightchild = nullptr;
    this->leftchild = nullptr;
    this->list = nullptr;
    this->sumRGB = 0;
}

NodeBST::NodeBST(NodeBST* r, NodeBST* l, List* h, int s)
{
    this->rightchild = r;
    this->leftchild = l;
    this->list = h;
    this->sumRGB = s;
}

NodeBST::~NodeBST()
{
}

NodeBST* NodeBST::getRightChild()
{
    return this->rightchild;
}

void NodeBST::setRightChild(NodeBST* r)
{
    this->rightchild = r;
}

NodeBST* NodeBST::getLeftChild()
{
    return this->leftchild;
}

void NodeBST::setLeftChild(NodeBST* l)
{
    this->leftchild = l;
}

List* NodeBST::getList()
{
    return this->list;
}

void NodeBST::setList(List* h)
{
    this->list = h;
}

int NodeBST::getSumRGB()
{
    return this->sumRGB;
}

void NodeBST::setSumRGB(int s)
{
    this->sumRGB = s;
}