#ifndef BST_HPP
#define BST_HPP
#include "NodeBST.hpp"
#include "List.hpp"
#include "ElementList.hpp"
#include "Pixel.hpp"

#include <iostream>
using namespace std;

class BST
{
    NodeBST* root;
public:
    BST();
    ~BST();
    bool search (int sum, NodeBST* n);
    void insert (Pixel* px);
    void insertRec(Pixel* px, NodeBST* n);
    void remove (int sum, NodeBST* n);
    int deletemin (NodeBST* n);
    bool empty();
    
    NodeBST* getRoot();
    void setRoot(NodeBST* n);
};

#endif // BST_HPP
