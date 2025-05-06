#include "BST.hpp"
#include <iostream>
using namespace std;

BST::BST()
{
    this->root = nullptr;
}

BST::~BST()
{
}

NodeBST* BST::getRoot()
{
    return this->root;
}

void BST::setRoot(NodeBST* r)
{
    this->root = r;
}

bool BST::search(int sum, NodeBST* n)
{
    bool result = false;
    if (n != nullptr)
    {
        if (n->getSumRGB() == sum)
        {
            result = true;
        }
        else if (sum < n->getSumRGB())
        {
            result = search(sum, n->getLeftChild());
        }
        else if (sum > n->getSumRGB())
        {
            result = search(sum, n->getRightChild());
        }
    }
    return result;
}

void BST::insert(Pixel* px)
{
    int sum = px->getSumRGB();
    
    List* newList = new List();
    newList->insertLast(px);
    
    if(root == nullptr)
    {
        root = new NodeBST(nullptr, nullptr, newList, sum);
    }
    else
    {
        insertRec(px, root);
    }
}

void BST::insertRec(Pixel* px, NodeBST* n)
{
    int sum = px->getSumRGB();
    List* newList = new List();
    
    //Case 0: empty node
    if(n != nullptr) //there is a node
    {
        if(sum < n->getSumRGB())
        {
            if(n->getLeftChild() == nullptr)
            {
                //Case 1: inserting in the Left Child
                n->setLeftChild(new NodeBST(nullptr, nullptr, newList, sum));
                newList->insertLast(px);
            }
            else
            {
                insertRec(px, n->getLeftChild());
            }
        }
        else
        {
            if(sum > n->getSumRGB())
            {
                if(n->getRightChild() == nullptr)
                {
                    //Case 2: inserting in the Right Child
                    n->setRightChild(new NodeBST(nullptr, nullptr, newList, sum));
                    newList->insertLast(px);
                }
                else
                {
                    insertRec(px, n->getRightChild());
                }
            }
            else
            {
                //Case 3: sum of the new node is equal to an existing node
                //new element in the list, not the first pixel in the node's list
                List* realList = n->getList();//get the list of the node, which already has pixels in it
                realList->insertLast(px);//insert the new pixel in the last position of the list of the node
            }
        }
    }
    else
    {
        cout<<"Error: this should not be reached"<<endl;
    }
}

void BST::remove(int sum, NodeBST* n)
{
    if (n != nullptr)
    {
        if (sum < n->getSumRGB())
        {
            remove(sum, n->getLeftChild());
        }
        else if (sum > n->getSumRGB())
        {
            remove(sum, n->getRightChild());
        }
        else if ((n->getLeftChild() == nullptr) && (n->getRightChild() == nullptr))
        {
            
        }
    }
}

int BST::deletemin(NodeBST* n)
{
    int result = 0;
    int aux = 0;
    if (n->getLeftChild() == nullptr)
    {
        aux = n->getSumRGB();
        n = n->getRightChild();
        result = aux;
    }
    else
    {
        result = deletemin(n->getLeftChild());
    }
    return result;
}

bool BST::empty()
{
    return root == nullptr;
}